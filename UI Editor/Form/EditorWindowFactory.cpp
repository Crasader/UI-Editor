#include "EditorWindowFactory.h"
#include <wx/image.h>

#include "EditorToolWidgetSelect.h"
#include "EditorToolObjectView.h"
#include "EditorToolPropertyEditor.h"
#include "EditorWorkArea.h"
#include "../ErrorHandle/ErrorHandle.h"

EditorWindowFactory::EditorWindowFactory()
{
	// ��ʼ����ͼ����
	if (wxImage::FindHandler(wxBITMAP_TYPE_PNG) == nullptr)
	{
		wxImage::AddHandler(new wxPNGHandler);
	}
}

EditorWindowFactory::~EditorWindowFactory()
{
	wxImage::CleanUpHandlers();
}

EditorToolWindow * EditorWindowFactory::createToolWindow(ToolWindowType type, wxAuiManager &manager, wxWindow * parent,
	int direction, const wxString & paneName) const
{
	switch (type)
	{
	case ToolWindowType::WidgetSelect:
		return new EditorToolWidgetSelect(manager, parent, direction, paneName);

	case ToolWindowType::ObjectView:
		return new EditorToolObjectView(manager, parent, direction, paneName);

	case ToolWindowType::PropertyEditor:
		return new EditorToolPropertyEditor(manager, parent, direction, paneName);

	default:
		throw ExtraExcept::unexpected_situation("createToolWindow'default is a branch that should not be invoked.");
		break;
	}
}

// ���ٶ�Ӧ��ToolWindow
void EditorWindowFactory::destroyToolWindow(EditorToolWindow* &toolWnd) const
{
	delete toolWnd;
	toolWnd = NULL;
}

// ������������
EditorWorkArea * EditorWindowFactory::createWorkArea(wxMDIParentFrame* parent, 
	const wxString& captionName, const wxPoint& position, const wxSize& size) const
{
	return new EditorWorkArea(parent, captionName, position, size);
}

// ������������
void EditorWindowFactory::destroyWorkArea(EditorWorkArea* &workArea) const
{
	delete workArea;
	workArea = NULL;
}
