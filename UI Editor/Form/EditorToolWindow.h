#ifndef EDITOR_TOOL_WINDOW_H
#define EDITOR_TOOL_WINDOW_H

#include "WorkArea.h"
#include <wx/aui/aui.h>
#include <memory>

class WindowAttributeManager;

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
	void setPaneInfo(const wxAuiPaneInfo& paneInfo);
	// ��ȡ����ͣ������
	wxAuiPaneInfo& getPaneInfo();

	//// ���ô��������б�
	//void setWinAttrManager(std::shared_ptr<WindowAttributeManager> winAttrMgr) { m_winAttrMgr = winAttrMgr;  }

//protected:
//	// ������ȡ���������б�
//	std::shared_ptr<WindowAttributeManager> m_winAttrMgr;
private:
	wxAuiManager& m_auiManager;
	// ������¼���������Ĵ�����
	wxPanel* m_bench;
};

#endif		// EDITOR_TOOL_WINDOW_H