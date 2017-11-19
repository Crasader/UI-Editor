#ifndef FORM_WIDGET_SELECT_H
#define FORM_WIDGET_SELECT_H

/*
 * �ļ�����FormWidgetSelect
 * ���ã����������ڻ�����������Ҫ���ƵĿؼ�����
 */

#include <vector>
#include <wx/treectrl.h>
#include "FormToolWindow.h"

class FormWidgetSelect : public FormToolWindow
{
public:
	FormWidgetSelect(wxAuiManager &manager, wxWindow * parent, int direction = wxLEFT, const wxString & paneName= wxEmptyString);
	~FormWidgetSelect() override;

	// ������ȡ�����ܴ����Ŀؼ�������
	std::vector<wxString> getAllWinNames() const;

private:
	// �������������ؼ�����ͼ��
	void OnDragWidgetIcon(wxTreeEvent& event);
private:
	// ������ʼ������
	void initSubWindows();

private:
	wxTreeCtrl* m_widget_tree;
};

#endif	// FORM_WIDGET_SELECT_H
