#ifndef EDITOR_TOOL_OBJECT_VIEW_H
#define EDITOR_TOOL_OBJECT_VIEW_H

/*
 * �ļ�����EditorToolObjectView
 * ���ã������鿴��ǰ�����Ĵ��ڸ��Ӽ���ϵ
 * ˵�������ڶ���չʾʹ�ö�ѡģʽ��չʾ���е�ǰѡ�еĴ��ڶ���
 */

#include "EditorToolWindow.h"
#include <wx/treelist.h>
#include <unordered_map>
#include "../EditorFuncDefine.h"

class EditorToolObjectView : public EditorToolWindow
{
public:
	EditorToolObjectView(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~EditorToolObjectView() override;

	// ����root�ڵ��Ӧ�Ĵ���ID
	void setRootWindowId(ID_TYPE id);
	// ���һ���ӽڵ�������ʶһ������
	bool addWindowItem(ID_TYPE parentId, ID_TYPE childId, const wxString& objectName, const wxString& winTypeName);

	// ���õ�ǰѡ�ж��󣬻�ȡ��֮ǰ���е�ѡ��
	void setCurSelect(ID_TYPE selectId) const;
	// ���ѡ�ж���
	void addSelect(ID_TYPE selectId) const;
	// ȡ��ѡ�ж���
	void unSelect(ID_TYPE unSelectId) const;
	// ��ȡ��ǰ����ѡ��
	std::vector<ID_TYPE> getSelections() const;
	// �޸Ķ���༭���е���ʾ����ǰֻ����޸Ķ���
	void changeWinAttr(ID_TYPE changeId, const wxString& attrName, const wxAny& toSetValue) const;

private:
	// ��ʼ���Ӵ���
	void initSubWindows();

private:
	// չʾ�����Ĵ��ڵ����ṹ
	wxTreeListCtrl* m_objectView;
	// ����ID��ڵ�ID֮��Ĺ���
	std::unordered_map<ID_TYPE, wxTreeListItem> m_idToItems;
};

#endif	// EDITOR_TOOL_OBJECT_VIEW_H
