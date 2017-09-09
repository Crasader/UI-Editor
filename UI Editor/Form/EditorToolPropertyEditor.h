#ifndef EDITOR_TOOL_PROPERTY_EDITOR_H
#define EDITOR_TOOL_PROPERTY_EDITOR_H

/*
 * �ļ�����EditorToolPropertyEditor
 * ���ã������༭���ڵ�����
 */

#include "EditorToolWindow.h"

class wxPropertyGrid;

class EditorToolPropertyEditor : public EditorToolWindow
{
public:
	EditorToolPropertyEditor(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~EditorToolPropertyEditor() override;

private:
	// ��ʼ���༭���Դ���
	void initSubWindows();

private:
	// ������ʾ���ԵĴ���
	wxPropertyGrid* m_propertyGrid;
};

#endif	// EDITOR_TOOL_PROPERTY_EDITOR_H
