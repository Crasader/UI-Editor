#ifndef EDITOR_TOOL_OBJECT_VIEW_H
#define EDITOR_TOOL_OBJECT_VIEW_H

/*
 * �ļ�����EditorToolObjectView
 * ���ã������鿴��ǰ�����Ĵ��ڸ��Ӽ���ϵ
 */

#include "EditorToolWindow.h"
#include <wx/treelist.h>
#include <unordered_map>
#include "../EditorWindow/EditorFuncDefine.h"

class EditorToolObjectView : public EditorToolWindow
{
public:
	EditorToolObjectView(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~EditorToolObjectView() override;

	// ����root�ڵ��Ӧ�Ĵ���ID
	void setRootWindowId(ID_TYPE id);
	// ���һ���ӽڵ�������ʶһ������
	bool addWindowItem(ID_TYPE parentId, ID_TYPE childId, const wxString& objectName, const wxString& winTypeName);

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
