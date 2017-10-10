#ifndef EDITOR_TOOL_PROPERTY_EDITOR_H
#define EDITOR_TOOL_PROPERTY_EDITOR_H

/*
 * �ļ�����EditorToolPropertyEditor
 * ���ã������༭���ڵ�����
 */

#include "EditorToolWindow.h"
#include <map>
#include <vector>

class wxPropertyGrid;
class wxPGProperty;
class wxBoxSizer;

class EditorToolPropertyEditor : public EditorToolWindow
{
public:
	EditorToolPropertyEditor(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~EditorToolPropertyEditor() override;

	// ��ʼ���༭���Դ���
	void initSubWindows(const std::vector<wxString>& windowTypes);
	// �޸Ķ�Ӧ���ڵ������б�
	void insertWindowTypeAttrs(const wxString& winType, const std::vector<wxPGProperty*>& attrs);

	// �������ñ༭����
	void resetAttrs(const wxString& winTypeName);
	// ���������б��ֵ
	void updateAttrs(const std::map<wxString, wxAny>& propAttrs);
private:

private:
	// �������ô������Եı༭���б�
	std::map<wxString, wxPropertyGrid*> m_propertyGrids;
	// ���ֹ�����
	wxBoxSizer* m_sizer;
	// ��ǰ�༭����������
	wxString m_curEditWinType;
	// ��ǰ�����༭�������Եı༭��
	wxPropertyGrid* m_curPropertyGrid = nullptr;
};

#endif	// EDITOR_TOOL_PROPERTY_EDITOR_H
