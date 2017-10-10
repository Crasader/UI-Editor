#include "EditorFrame.h"

#include "Settings/WindowAttributeManager.h"
#include "Form/EditorToolWindow.h"
#include "Form/EditorToolWidgetSelect.h"
#include "Form/EditorToolObjectView.h"
#include "Form/EditorToolPropertyEditor.h"
#include "Form/EditorWorkArea.h"
#include "EditMessage/ChangeManager.h"
#include "EditMessage/CommandFactory.h"

const wxString WIN_ATTR_FILE = "WindowAttribute.xml";

EditorFrame::EditorFrame(const wxString & title)
	: wxMDIParentFrame(NULL, wxID_ANY, title)
{
	loadWindowAttributes();
	addMenu();
	initSubWindows();
}

EditorFrame::~EditorFrame()
{
	m_auiManager->UnInit();
}

// ÿ֡������
void EditorFrame::updateFrame(float dt)
{
	m_editWorkArea->updateFrame(dt);
}

// ��д���ٺ���
bool EditorFrame::Destroy()
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


wxBEGIN_EVENT_TABLE(EditorFrame, wxFrame)
	EVT_SIZE(EditorFrame::OnSize)
wxEND_EVENT_TABLE()

// �����˵���
void EditorFrame::addMenu()
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
	
	SetMenuBar(menuBar);

	// ���״̬��
	CreateStatusBar(1);
	SetStatusText("Welcome to UI Editor");
}

// ���������ڴ�С�ı�
void EditorFrame::OnSize(wxSizeEvent & event)
{
	if (m_auiManager)
	{
		m_auiManager->Update();
	}
}

// ���ش�������
void EditorFrame::loadWindowAttributes()
{
	m_winAttrManager.reset(new WindowAttributeManager());
	m_winAttrManager->LoadAttributeFile(WIN_ATTR_FILE);
}

// ��ʼ���Ӵ���
void EditorFrame::initSubWindows()
{
	wxSize clientSize = GetClientSize();

	m_auiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
	double width = 0.6;
	double height = 0.6;
	m_auiManager->SetDockSizeConstraint(width, height);

	auto funcWndsMgr = m_manager;
	auto tool_window_del_func = [funcWndsMgr](EditorToolWindow* editWnd) {funcWndsMgr.destroyToolWindow(editWnd); };

	// ��������ѡ��
	m_tool_widget_select.reset(dynamic_cast<EditorToolWidgetSelect*>(
		m_manager.createToolWindow(ToolWindowType::WidgetSelect, *m_auiManager, this, wxLEFT, "Widget Select")),
		tool_window_del_func);
	wxAuiPaneInfo widgetSelectPaneInfo = m_tool_widget_select->getPaneInfo();
	widgetSelectPaneInfo.BestSize(100, clientSize.GetHeight());
	m_tool_widget_select->setPaneInfo(widgetSelectPaneInfo);
	// �鿴���ڶ����Ӽ���ϵ
	m_tool_object_view.reset(dynamic_cast<EditorToolObjectView*>(
		m_manager.createToolWindow(ToolWindowType::ObjectView, *m_auiManager, this, wxRIGHT, "Object View")),
		tool_window_del_func);
	wxAuiPaneInfo objectViewPaneInfo = m_tool_object_view->getPaneInfo();
	objectViewPaneInfo.BestSize(300, clientSize.GetHeight());
	m_tool_object_view->setPaneInfo(objectViewPaneInfo);
	// ���ڶ��������޸�
	m_tool_property_editor.reset(dynamic_cast<EditorToolPropertyEditor*>(
		m_manager.createToolWindow(ToolWindowType::PropertyEditor, *m_auiManager, this, wxRIGHT, "Property Editor")),
		tool_window_del_func);
	// ��ʼ����ͬ�������Ͷ�Ӧ�������б�
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

	auto work_area_del_func = [funcWndsMgr](EditorWorkArea* editWnd) {funcWndsMgr.destroyWorkArea(editWnd); };
	// ��ӹ�������
	m_editWorkArea.reset(
		m_manager.createWorkArea(this, "WorkArea", wxDefaultPosition, wxSize(500, 400)),
			work_area_del_func);

	// ���ù���������鿴���󴰿�֮��Ĺ���
	m_tool_object_view->setRootWindowId(m_editWorkArea->getManageWindowId());

	using namespace Command;
	ChangeManager::createInstance();
	CommandFactory::createInstance(ChangeManager::instance());
	// �����������͹��ߴ�����ӵ��ı䴦�������
	ChangeManager::instance()->setObjectView(m_tool_object_view);
	ChangeManager::instance()->setPropertyEditor(m_tool_property_editor);
	ChangeManager::instance()->setWorkArea(m_editWorkArea);

	ChangeManager::instance()->setWindowAttrMgr(m_winAttrManager);
}

wxDEFINE_EVENT(DESTROY_EVENT, wxNotifyEvent);