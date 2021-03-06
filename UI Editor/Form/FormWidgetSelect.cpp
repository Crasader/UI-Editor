#include <wx/dnd.h>
#include <wx/fontdlg.h>
#include <wx/propgrid/property.h>
#include "FormWidgetSelect.h"
#include "../ErrorHandle/ErrorMessage.h"
#include "FormWidgetSelectDefine.h"
#include "../CopyDrop/CopyWinObject.h"
#include "../Settings/WindowAttributeManager.h"

const wxString WIDGET_SELECT_ICONS = "widget-icons.png";

const int ICONS_START_X = 0;
const int ICONS_START_Y = 0;
const int ICONS_DIS_X = 25;
const int ICONS_DIS_Y = 25;

const int ICONS_ROW_NUM = 3;
const int ICONS_COLUMN_NUM = 5;

FormWidgetSelect::FormWidgetSelect(wxAuiManager & manager, wxWindow * parent, int direction, const wxString & paneName)
	: FormToolWindow(manager, parent, direction, paneName)
{
	initSubWindows();
}


FormWidgetSelect::~FormWidgetSelect()
{

}

// 用来获取所有能创建的控件类型名
std::vector<wxString> FormWidgetSelect::getAllWinNames() const
{
	auto rootId = m_widget_tree->GetRootItem();
	std::vector<wxString> winNames;

	wxTreeItemIdValue cookie = nullptr;
	for (auto id = m_widget_tree->GetFirstChild(rootId, cookie); id.IsOk(); id = m_widget_tree->GetNextChild(rootId, cookie))
	{
		WidgetSelectItemName* itemName = dynamic_cast<WidgetSelectItemName*>(m_widget_tree->GetItemData(id));
		if (itemName != nullptr)
		{
			winNames.push_back(itemName->getWidgetName());
		}
	}
	return winNames;
}

// 用来处理拖拉控件类型图标
void FormWidgetSelect::OnDragWidgetIcon(wxTreeEvent& event)
{
	const wxTreeItemId& treeItem = event.GetItem();
	wxTreeItemData *itemData = m_widget_tree->GetItemData(treeItem);
	auto itemWidgetName = dynamic_cast<WidgetSelectItemName*>(itemData);
	// 如果不能获得对应的控件，则没有必要使用拖拉了
	if (itemWidgetName == nullptr)
	{
		event.Veto();
	}

	// 使用拖拉
	CopyWindowInfo winValue(itemWidgetName->getWidgetName());
	
	CopyWinObject dropData(getCopyDataFormat());
	dropData.SetData(sizeof(winValue), &winValue);

	wxDropSource dropSource;
	dropSource.SetData(dropData);

	dropSource.DoDragDrop();
}

// 用来初始化窗口
void FormWidgetSelect::initSubWindows()
{
	wxImage iconImage(WIDGET_SELECT_ICONS, wxBITMAP_TYPE_PNG);

	if (!iconImage.Ok())
	{
		EditorMessage::showErrorMessage(wxS("Sorry, could not load file: ") + WIDGET_SELECT_ICONS);
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

	// 创建控件类型列表
	wxTreeItemId rootId = m_widget_tree->AddRoot(wxS("Root"));
	wxTreeItemId itemId1 = m_widget_tree->AppendItem(rootId, EDITOR_LABEL_SHOW, 9, 9, new WidgetSelectItemName(EDITOR_LABEL_TYPE));
	wxTreeItemId itemId2 = m_widget_tree->AppendItem(rootId, EDITOR_BUTTON_SHOW, 10, 10, new WidgetSelectItemName(EDITOR_BUTTON_TYPE));
	wxTreeItemId itemId3 = m_widget_tree->AppendItem(rootId, EDITOR_FRAME_SHOW, 4, 4, new WidgetSelectItemName(EDITOR_FRAME_TYPE));

	// 绑定事件
	m_widget_tree->Bind(wxEVT_TREE_BEGIN_DRAG, &FormWidgetSelect::OnDragWidgetIcon, this, wxID_ANY);

	wxBoxSizer* vBoxSizer = new wxBoxSizer(wxVERTICAL);
	vBoxSizer->Add(m_widget_tree, 1, wxALL, 5);
	getBench()->SetSizerAndFit(vBoxSizer);
}
