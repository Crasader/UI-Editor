#include "EditorToolObjectView.h"
#include "EditorToolObjectViewDefine.h"

EditorToolObjectView::EditorToolObjectView(wxAuiManager &manager, wxWindow * parent, int direction, const wxString & paneName)
	: EditorToolWindow(manager, parent, direction, paneName)
{
	initSubWindows();
}

EditorToolObjectView::~EditorToolObjectView()
{

}

// ����root�ڵ��Ӧ�Ĵ���ID
void EditorToolObjectView::setRootWindowId(ID_TYPE id)
{
	wxTreeListItem rootItem = m_objectView->GetRootItem();
	m_idToItems[id] = rootItem;
}

// ���һ���ӽڵ�������ʶһ������
bool EditorToolObjectView::addWindowItem(ID_TYPE parentId, ID_TYPE childId, const wxString &objectName, const wxString & winTypeName)
{
	wxTreeListItem parentItem = m_idToItems.at(parentId);
	wxTreeListItem childItem = m_objectView->AppendItem(parentItem, objectName, wxTreeListCtrl::NO_IMAGE, wxTreeListCtrl::NO_IMAGE, new EditorWindowID(childId));
	m_objectView->SetItemText(childItem, 1, winTypeName);
	m_idToItems[childId] = childItem;
	return true;
}

// ��ʼ���Ӵ���
void EditorToolObjectView::initSubWindows()
{
	m_objectView = new wxTreeListCtrl(getBench(), wxID_ANY, wxPoint(0, 0), wxSize(300, 600), wxTL_DEFAULT_STYLE | wxTL_CHECKBOX);
	m_objectView->AppendColumn(wxS("object"));
	m_objectView->AppendColumn(wxS("class"));
	//wxTreeListItem item = m_objectView->AppendItem(m_objectView->GetRootItem(), wxS("background"));
	//m_objectView->SetItemText(item, 1, wxS("EditorLabel"));

	wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
	boxSizer->Add(m_objectView, 1, wxALL, 5);
	getBench()->SetSizerAndFit(boxSizer);
}

