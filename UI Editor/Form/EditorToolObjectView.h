#ifndef EDITOR_TOOL_OBJECT_VIEW_H
#define EDITOR_TOOL_OBJECT_VIEW_H

/*
 * �ļ�����EditorToolObjectView
 * ���ã������鿴��ǰ�����Ĵ��ڸ��Ӽ���ϵ
 */

#include "EditorToolWindow.h"
#include <wx/treelist.h>

class EditorToolObjectView : public EditorToolWindow
{
public:
	EditorToolObjectView(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~EditorToolObjectView() override;

private:
	// ��ʼ���Ӵ���
	void initSubWindows();

private:
	wxTreeListCtrl* m_objectView;
};

#endif	// EDITOR_TOOL_OBJECT_VIEW_H
