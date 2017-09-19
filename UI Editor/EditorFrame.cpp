#include "EditorFrame.h"

#include "Settings/WindowAttributeManager.h"
#include "Form/EditorToolWindow.h"
#include "Form/EditorWorkArea.h"

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
	m_manager.destroyToolWindow(m_tool_widget_select);
	m_manager.destroyToolWindow(m_tool_object_view);
	m_manager.destroyToolWindow(m_tool_property_editor);
	m_manager.destroyWorkArea(m_editWorkArea);
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

	// ��������ѡ��
	m_tool_widget_select = m_manager.createToolWindow(ToolWindowType::WidgetSelect, *m_auiManager, this, wxLEFT, "Widget Select");
	wxAuiPaneInfo& widgetSelectPaneInfo = m_tool_widget_select->getPanelInfo();
	widgetSelectPaneInfo.BestSize(100, clientSize.GetWidth());
	widgetSelectPaneInfo.MaxSize(200, clientSize.GetWidth());
	widgetSelectPaneInfo.Resizable(true);
	m_tool_widget_select->setPanelInfo(widgetSelectPaneInfo);
	m_tool_widget_select->setWinAttrManager(m_winAttrManager);
	// �鿴���ڶ����Ӽ���ϵ
	m_tool_object_view = m_manager.createToolWindow(ToolWindowType::ObjectView, *m_auiManager, this, wxRIGHT, "Object View");
	m_tool_object_view->setWinAttrManager(m_winAttrManager);
	// ���ڶ��������޸�
	m_tool_property_editor = m_manager.createToolWindow(ToolWindowType::PropertyEditor, *m_auiManager, this, wxRIGHT, "Property Editor");
	m_tool_property_editor->setWinAttrManager(m_winAttrManager);

	m_auiManager->Update();

	//wxMDIClientWindowBase* clientWindow = GetClientWindow();
	//clientWindow->SetSize(200, 0, 500, 400);

	// ��ӹ�������
	m_editWorkArea = m_manager.createWorkArea(this, "WorkArea", wxDefaultPosition, wxSize(500, 400));
}

wxDEFINE_EVENT(DESTROY_EVENT, wxNotifyEvent);