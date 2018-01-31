#include "MainFrame.h"

#include "Settings/WindowAttributeManager.h"
#include "Form/FormToolWindow.h"
#include "Form/FormWidgetSelect.h"
#include "Form/FormObjectView.h"
#include "Form/FormPropertyEditor.h"
#include "Form/FormWorkArea.h"
#include "EditMessage/ChangeManager.h"
#include "EditMessage/CommandFactory.h"

const wxString WIN_ATTR_FILE = "WindowAttribute.xml";

MainFrame::MainFrame(const wxString & title)
	: wxMDIParentFrame(NULL, wxID_ANY, title)
{
	loadWindowAttributes();
	initMessageHandle();
	addMenu();
	initSubWindows();
}

MainFrame::~MainFrame()
{
	m_auiManager->UnInit();
}

// ÿ֡������
void MainFrame::updateFrame(float dt)
{
	m_editWorkArea->updateFrame(dt);
}

// ��д���ٺ���
bool MainFrame::Destroy()
{
	bool destroyed = wxFrame::Destroy();
	if (destroyed)
	{
		wxNotifyEvent event(DESTROY_EVENT, GetId());
		event.SetEventObject(this);
		// Do send it.
		ProcessWindowEvent(event);

		return true;
	}

	return false;
}


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_SIZE(MainFrame::OnSize)

	EVT_MENU(wxID_UNDO, MainFrame::OnUndoCommand)
	EVT_MENU(wxID_REDO, MainFrame::OnRedoCommand)
wxEND_EVENT_TABLE()

// ���������ڴ�С�ı�
void MainFrame::OnSize(wxSizeEvent & event)
{
	if (m_auiManager)
	{
		m_auiManager->Update();
	}
}

// ��������ȡ��֮ǰ������
void MainFrame::OnUndoCommand(wxCommandEvent & WXUNUSED(event))
{
	using namespace Command;
	ChangeManager::instance()->getCommandStack().Undo();
}

// ����������֮ǰ������
void MainFrame::OnRedoCommand(wxCommandEvent & WXUNUSED(event))
{
	using namespace Command;
	ChangeManager::instance()->getCommandStack().Redo();
}

// ���ؿؼ�����
void MainFrame::loadWindowAttributes()
{
	m_winAttrManager.reset(new WindowAttributeManager());
	m_winAttrManager->LoadAttributeFile(WIN_ATTR_FILE);
}

// �����˵���
void MainFrame::addMenu()
{
	// �ļ��˵�
	wxMenu* fileMenu = new wxMenu;
	fileMenu->Append(wxID_NEW);
	fileMenu->Append(wxID_OPEN);
	fileMenu->Append(wxID_SAVE);
	fileMenu->Append(wxID_SAVEAS);
	fileMenu->Append(wxID_EXIT);

	// �༭�˵�
	wxMenu* editMenu = new wxMenu;
	editMenu->Append(wxID_UNDO);
	editMenu->Append(wxID_REDO);
	editMenu->Append(wxID_CUT);
	editMenu->Append(wxID_COPY);
	editMenu->Append(wxID_PASTE);
	editMenu->Append(wxID_FIND);

	// �����˵�
	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_HELP);
	helpMenu->Append(wxID_ABOUT);

	// ��Ӳ˵���
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(editMenu, "&Edit");
	menuBar->Append(helpMenu, "&Help");

	using namespace Command;
	ChangeManager::instance()->getCommandStack().SetEditMenu(editMenu);

	SetMenuBar(menuBar);

	// ���״̬��
	CreateStatusBar(1);
	SetStatusText("Welcome to UI Editor");
}

// ��ʼ��������صĶ���
void MainFrame::initMessageHandle()
{
	using namespace Command;
	ChangeManager::createInstance();
	CommandFactory::createInstance(ChangeManager::instance());

	ChangeManager::instance()->setWindowAttrMgr(m_winAttrManager);
}

// ��ʼ���Ӵ���
void MainFrame::initSubWindows()
{
	wxSize clientSize = GetClientSize();

	m_auiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
	double width = 0.6;
	double height = 0.6;
	m_auiManager->SetDockSizeConstraint(width, height);

	auto funcWndsMgr = m_manager;
	auto tool_window_del_func = [funcWndsMgr](FormToolWindow* editWnd) {funcWndsMgr.destroyToolWindow(editWnd); };

	// �ؼ�����ѡ��
	m_tool_widget_select.reset(dynamic_cast<FormWidgetSelect*>(
		m_manager.createToolWindow(ToolWindowType::WidgetSelect, *m_auiManager, this, wxLEFT, "Widget Select")),
		tool_window_del_func);
	wxAuiPaneInfo widgetSelectPaneInfo = m_tool_widget_select->getPaneInfo();
	widgetSelectPaneInfo.BestSize(100, clientSize.GetHeight());
	m_tool_widget_select->setPaneInfo(widgetSelectPaneInfo);
	// �鿴�ؼ������Ӽ���ϵ
	m_tool_object_view.reset(dynamic_cast<FormObjectView*>(
		m_manager.createToolWindow(ToolWindowType::ObjectView, *m_auiManager, this, wxRIGHT, "Object View")),
		tool_window_del_func);
	wxAuiPaneInfo objectViewPaneInfo = m_tool_object_view->getPaneInfo();
	objectViewPaneInfo.BestSize(300, clientSize.GetHeight());
	m_tool_object_view->setPaneInfo(objectViewPaneInfo);
	// �ؼ����������޸�
	m_tool_property_editor.reset(dynamic_cast<FormPropertyEditor*>(
		m_manager.createToolWindow(ToolWindowType::PropertyEditor, *m_auiManager, this, wxRIGHT, "Property Editor")),
		tool_window_del_func);
	// ��ʼ����ͬ�ؼ����Ͷ�Ӧ�������б�
	std::vector<wxString> winNames = m_tool_widget_select->getAllWinNames();
	m_tool_property_editor->initSubWindows(winNames);
	for (const auto& value : winNames)
	{
		m_tool_property_editor->insertWindowTypeAttrs(value, m_winAttrManager->getEditWinAttr(value));
	}
	wxAuiPaneInfo propertyEditorPaneInfo = m_tool_property_editor->getPaneInfo();
	propertyEditorPaneInfo.BestSize(300, clientSize.GetHeight());
	m_tool_property_editor->setPaneInfo(propertyEditorPaneInfo);

	m_auiManager->Update();

	auto work_area_del_func = [funcWndsMgr](FormWorkArea* editWnd) {funcWndsMgr.destroyWorkArea(editWnd); };
	// �����������
	m_editWorkArea.reset(
		m_manager.createWorkArea(this, "WorkArea", wxDefaultPosition, wxSize(500, 400)),
			work_area_del_func);

	// ��������������鿴�ؼ����󴰿�֮��Ĺ���
	m_tool_object_view->setRootWindowId(m_editWorkArea->getManageWindowId());

	// �����������Ͷ�Ӧ��������ӵ�����������
	using namespace Command;
	ChangeManager::instance()->setObjectView(m_tool_object_view);
	ChangeManager::instance()->setPropertyEditor(m_tool_property_editor);
	ChangeManager::instance()->setWorkArea(m_editWorkArea);
}

wxDEFINE_EVENT(DESTROY_EVENT, wxNotifyEvent);