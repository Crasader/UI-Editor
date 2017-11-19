#ifndef FORM_TOOL_WINDOW_H
#define FORM_TOOL_WINDOW_H

#include <memory>
#include <wx/aui/aui.h>
#include "WorkArea.h"

class WindowAttributeManager;

class FormToolWindow : public WorkArea
{
public:
	FormToolWindow(wxAuiManager& manager, wxWindow* parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	virtual ~FormToolWindow();

	// ��ȡ�ù������������ڶ���
	wxWindow* getBench() override { return m_bench; }

	// ��������ͣ������
	void setDirection(int direction);
	// �������ñ���
	void setCaption(const wxString& captionName);
	// �������ø���ͣ������
	void setPaneInfo(const wxAuiPaneInfo& paneInfo);
	// ��ȡ����ͣ������
	wxAuiPaneInfo& getPaneInfo();

private:
	wxAuiManager& m_auiManager;
	// ������¼���������Ĵ�����
	wxPanel* m_bench;
};

#endif		// FORM_TOOL_WINDOW_H