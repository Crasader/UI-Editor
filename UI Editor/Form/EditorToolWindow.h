#ifndef EDITOR_TOOL_WINDOW_H
#define EDITOR_TOOL_WINDOW_H

#include "WorkArea.h"

#include <wx/aui/aui.h>

class wxFrame;

class EditorToolWindow : public WorkArea
{
public:
	EditorToolWindow(wxAuiManager& manager, wxWindow* parent, int direction = wxLEFT, const wxString & paneName = wxEmptyString);
	virtual ~EditorToolWindow();

	// ��ȡ�ù������������ڶ���
	wxWindow* getBench() override { return m_bench; }

	// ��������ͣ������
	void setDirection(int direction);
	// �������ñ���
	void setCaption(const wxString& captionName);
	// �������ø���ͣ������
	void setPanelInfo(const wxAuiPaneInfo& paneInfo);
	// ��ȡ����ͣ������
	wxAuiPaneInfo& getPanelInfo();

private:
	wxAuiManager& m_auiManager;
	// ������¼���������Ĵ�����
	wxPanel* m_bench;
};

#endif		// EDITOR_TOOL_WINDOW_H