#ifndef FORM_PROPERTY_EDITOR_H
#define FORM_PROPERTY_EDITOR_H

/*
 * �ļ�����FormPropertyEditor
 * ���ã������༭�ؼ�������
 */

#include <map>
#include <vector>
#include "FormToolWindow.h"

class wxPropertyGrid;
class wxPGProperty;
class wxBoxSizer;
class wxPropertyGridEvent;

class FormPropertyEditor : public FormToolWindow
{
public:
	FormPropertyEditor(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	~FormPropertyEditor() override;

	// ��ʼ���༭���Դ���
	void initSubWindows(const std::vector<wxString>& windowTypes);
	// �޸Ķ�Ӧ�ؼ��������б�
	void insertWindowTypeAttrs(const wxString& winType, const std::vector<wxPGProperty*>& attrs);

	// ��ʾ��Ӧ���͵ı༭��
	void resetAttrs(const wxString& winTypeName);
	// ���������б��ֵ
	void updateAttrs(const std::map<wxString, wxAny>& propAttrs);
private:
	// �����������Ըı�
	void OnPropertyGridChanged(wxPropertyGridEvent& event);
private:
	// �������ÿؼ����Եı༭���б�
	std::map<wxString, wxPropertyGrid*> m_propertyGrids;
	// ���ֹ�����
	wxBoxSizer* m_sizer;
	// ��ǰ�༭�Ŀؼ�����
	wxString m_curEditWinType;
	// �����༭��ǰ�ؼ����Եı༭��
	wxPropertyGrid* m_curPropertyGrid = nullptr;
};

#endif	// FORM_PROPERTY_EDITOR_H
