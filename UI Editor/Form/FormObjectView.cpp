#include "FormObjectView.h"
#include "FormObjectViewDefine.h"

FormObjectView::FormObjectView(wxAuiManager &manager, wxWindow * parent, int direction, const wxString & paneName)
	: FormToolWindow(manager, parent, direction, paneName)
{
	initSubWindows();
}

FormObjectView::~FormObjectView()
{

}

// ����root�ڵ��Ӧ�Ŀؼ�ID
void FormObjectView::setRootWindowId(ID_TYPE id)
{
	wxTreeListItem rootItem = m_objectView->GetRootItem();
	m_idToItems[id] = rootItem;
}

// ���һ���ӽڵ�������ʶһ���ؼ�
bool FormObjectView::addWindowItem(ID_TYPE parentId, ID_TYPE childId, const wxString &objectName, const wxString & winTypeName)
{
	wxTreeListItem parentItem = m_idToItems.at(parentId);
	wxTreeListItem childItem = m_objectView->AppendItem(parentItem, objectName, wxTreeListCtrl::NO_IMAGE, wxTreeListCtrl::NO_IMAGE, new EditorWindowID(childId));
	m_objectView->SetItemText(childItem, 1, winTypeName);
	m_idToItems[childId] = childItem;
	return true;
}

// ���õ�ǰѡ�ж��󣬻�ȡ��֮ǰ���е�ѡ��
void FormObjectView::setCurSelect(ID_TYPE selectId) const
{
	m_objectView->UnselectAll();
	m_objectView->Select(m_idToItems.at(selectId));
}

// ���ѡ�ж���
void FormObjectView::addSelect(ID_TYPE selectId) const
{
	m_objectView->Select(m_idToItems.at(selectId));
}

// ȡ��ѡ�ж���
void FormObjectView::unSelect(ID_TYPE unSelectId) const
{
	m_objectView->Unselect(m_idToItems.at(unSelectId));
}

// ��ȡ��ǰ����ѡ��
std::vector<ID_TYPE> FormObjectView::getSelections() const
{
	std::vector<ID_TYPE> selections;
	wxTreeListItems items;
	m_objectView->GetSelections(items);
	for (const auto& item : items)
	{
		auto data = dynamic_cast<EditorWindowID *>(m_objectView->GetItemData(item));
		selections.push_back(data->getEditorWinId());
	}

	return selections;
}

// �޸Ķ���༭���е���ʾ����ǰֻ����޸Ķ���
void FormObjectView::changeWinAttr(ID_TYPE changeId, const wxString &attrName, const wxAny &toSetValue) const
{
	if (attrName == OBJECT_NAME)
	{
		wxTreeListItem item = m_idToItems.at(changeId);
		m_objectView->SetItemText(item, 0, toSetValue.As<wxString>());
	}
}

// ��ʼ���Ӵ���
void FormObjectView::initSubWindows()
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

