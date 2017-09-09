#include "EditorToolWidgetSelect.h"

#include <wx/dnd.h>
#include "../ErrorHandle/ErrorMessage.h"

const wxString WIDGET_SELECT_ICONS = "widget-icons.png";

const int ICONS_START_X = 0;
const int ICONS_START_Y = 0;
const int ICONS_DIS_X = 25;
const int ICONS_DIS_Y = 25;

const int ICONS_ROW_NUM = 3;
const int ICONS_COLUMN_NUM = 5;

EditorToolWidgetSelect::EditorToolWidgetSelect(wxAuiManager & manager, wxWindow * parent, int direction, const wxString & paneName)
	: EditorToolWindow(manager, parent, direction, paneName)
{
	initSubWindows();
}


EditorToolWidgetSelect::~EditorToolWidgetSelect()
{

}

// ��������������������ͼ��
void EditorToolWidgetSelect::OnDragWidgetIcon(wxTreeEvent & event)
{
	const wxTreeItemId& treeItem = event.GetItem();
	int itemImage = m_widget_tree->GetItemImage(treeItem);

	wxBitmapDataObject bitmap;
	bitmap.SetBitmap(m_widget_tree->GetImageList()->GetBitmap(itemImage));

	wxDropSource dropSource;
	dropSource.SetData(bitmap);

	dropSource.DoDragDrop();
}

// ������ʼ������
void EditorToolWidgetSelect::initSubWindows()
{
	wxImage iconImage(WIDGET_SELECT_ICONS, wxBITMAP_TYPE_PNG);

	if (!iconImage.Ok())
	{
		EditorMessage::showErrorMessage(wxT("Sorry, could not load file: ") + WIDGET_SELECT_ICONS);
	}

	wxImageList* imageList = new wxImageList(ICONS_DIS_X, ICONS_DIS_Y);

	for (int i = 0; i != ICONS_ROW_NUM; ++i)
	{
		for (int j = 0; j != ICONS_COLUMN_NUM; ++j)
		{
			imageList->Add(iconImage.GetSubImage(
				wxRect(ICONS_START_X + ICONS_DIS_X * j, ICONS_START_Y + ICONS_DIS_Y * i, ICONS_DIS_X, ICONS_DIS_Y)));
		}
	}

	m_widget_tree = new wxTreeCtrl(getBench(), wxID_ANY, wxPoint(0, 0), wxSize(300, 600), wxTR_HIDE_ROOT | wxTR_NO_LINES | wxTR_NO_BUTTONS);
	m_widget_tree->AssignImageList(imageList);

	// �������������б�
	wxTreeItemId rootId = m_widget_tree->AddRoot(wxT("Root"));
	wxTreeItemId itemId1 = m_widget_tree->AppendItem(rootId, wxT("Static"), 3, 3);
	wxTreeItemId itemId2 = m_widget_tree->AppendItem(rootId, wxT("Button"), 10, 10);

	// ��ʱ��
	m_widget_tree->Bind(wxEVT_TREE_BEGIN_DRAG, &EditorToolWidgetSelect::OnDragWidgetIcon, this, wxID_ANY);

	wxBoxSizer* vBoxSizer = new wxBoxSizer(wxVERTICAL);
	vBoxSizer->Add(m_widget_tree, 1, wxALL, 5);
	getBench()->SetSizerAndFit(vBoxSizer);
}
