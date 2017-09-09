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
		int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	// ���ٶ�Ӧ��ToolWindow
	void destroyToolWindow(EditorToolWindow* &toolWnd);

	// ������������
	EditorWorkArea* createWorkArea(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	// ������������
	void destroyWorkArea(EditorWorkArea* &workArea);

private:
	
};

#endif	// EDITOR_WINDOW_FACTORY_H