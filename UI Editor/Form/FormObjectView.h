#ifndef FORM_OBJECT_VIEW_H
#define FORM_OBJECT_VIEW_H

/*
 * �ļ�����FormObjectView
 * ���ã������鿴��ǰ�����Ŀؼ����Ӽ���ϵ
 * ˵�����ؼ�����չʾʹ�ö�ѡģʽ��չʾ���е�ǰѡ�еĿؼ�����
 */

#include <wx/treelist.h>
#include <unordered_map>
#include <unordered_set>
#include "FormToolWindow.h"
#include "FormObjectViewDefine.h"

class FormObjectView : public FormToolWindow
{
public:
	FormObjectView(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~FormObjectView() override;

	// ����root�ڵ��Ӧ�Ŀؼ�ID
	void setRootWindowId(ID_TYPE id, const wxString& rootName);
	// ���һ���ӽڵ�������ʶһ���ؼ�
	bool addWindowItem(ID_TYPE parentId, ID_TYPE childId, const wxString& objectName, const wxString& winTypeName);
	// ɾ��һ���ӽڵ�
	bool delWindowItem(ID_TYPE childId);

	// ���õ�ǰѡ�ж��󣬻�ȡ��֮ǰ���е�ѡ��
	void setCurSelect(ID_TYPE selectId) const;
	// ���ѡ�ж���
	void addSelect(ID_TYPE selectId) const;
	// ȡ��ѡ�ж���
	void unSelect(ID_TYPE unSelectId) const;
	// ���õ�ǰ����ѡ��
	void setSelections(const std::unordered_set<ID_TYPE>& selections);
	// ��ȡ��ǰ����ѡ��
	std::unordered_set<ID_TYPE> getSelections() const;
	// �޸Ķ���༭���е���ʾ����ǰֻ����޸Ķ���
	void changeWinAttr(ID_TYPE changeId, const wxString& attrName, const wxAny& toSetValue) const;

private:
	// ��������ѡ�иı����Ϣ
	void handleSelectionChange(wxTreeListEvent &event);
	// ���������ڱ���ѡ
	

private:
	// ��ʼ���Ӵ���
	void initSubWindows();

private:
	// չʾ�����Ŀؼ������ṹ
	wxTreeListCtrl* m_objectView;
	// �ؼ�ID��ڵ�ID֮��Ĺ���
	std::unordered_map<ID_TYPE, wxTreeListItem> m_idToItems;
};

#endif	// FORM_OBJECT_VIEW_H
