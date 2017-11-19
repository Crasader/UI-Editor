#ifndef FORM_FACTORY_H
#define FORM_FACTORY_H

#include "WorkAreaDefine.h"
#include "FormToolWindow.h"

class FormWorkArea;
class wxMDIParentFrame;

class FormFactory
{
public:
	FormFactory();
	~FormFactory();

	// ������Ӧ��ToolWindow
	FormToolWindow* createToolWindow(ToolWindowType type, wxAuiManager &manager, wxWindow * parent, 
		int direction = wxLEFT, const wxString & paneName = wxEmptyString) const;
	// ���ٶ�Ӧ��ToolWindow
	void destroyToolWindow(FormToolWindow* &toolWnd) const;

	// ������������
	FormWorkArea* createWorkArea(wxMDIParentFrame* parent, 
		const wxString& captionName, const wxPoint& position, const wxSize &size) const;
	// ������������
	void destroyWorkArea(FormWorkArea* &workArea) const;

private:
	
};

#endif	// FORM_FACTORY_H