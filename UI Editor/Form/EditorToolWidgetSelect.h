#ifndef EDITOR_TOOL_WIDGET_SELECT_H
#define EDITOR_TOOL_WIDGET_SELECT_H

/*
 * �ļ�����EditorToolWidgetSelect
 * ���ã����������ڻ�����������Ҫ���ƵĴ�������
 */

#include "EditorToolWindow.h"
#include <wx/treectrl.h>

class EditorToolWidgetSelect : public EditorToolWindow
{
public:
	EditorToolWidgetSelect(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName= wxEmptyString);
	~EditorToolWidgetSelect() override;


private:
	// ��������������������ͼ��
	void OnDragWidgetIcon(wxTreeEvent& event);
private:
	// ������ʼ������
	void initSubWindows();

private:
	wxTreeCtrl* m_widget_tree;
};

#endif	// EDITOR_TOOL_WIDGET_SELECT_H
