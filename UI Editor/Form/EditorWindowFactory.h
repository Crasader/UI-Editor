#ifndef EDITOR_WINDOW_FACTORY_H
#define EDITOR_WINDOW_FACTORY_H

#include "WorkAreaDefine.h"
#include "EditorToolWindow.h"

class EditorWorkArea;
class wxMDIParentFrame;

class EditorWindowFactory
{
public:
	EditorWindowFactory();
	~EditorWindowFactory();

	// ������Ӧ��ToolWindow
	EditorToolWindow* createToolWindow(ToolWindowType type, wxAuiManager &manager, wxWindow * parent, 
		int direction = wxLEFT, const wxString & paneName = wxEmptyString) const;
	// ���ٶ�Ӧ��ToolWindow
	void destroyToolWindow(EditorToolWindow* &toolWnd) const;

	// ������������
	EditorWorkArea* createWorkArea(wxMDIParentFrame* parent, 
		const wxString& captionName, const wxPoint& position, const wxSize &size) const;
	// ������������
	void destroyWorkArea(EditorWorkArea* &workArea) const;

private:
	
};

#endif	// EDITOR_WINDOW_FACTORY_H