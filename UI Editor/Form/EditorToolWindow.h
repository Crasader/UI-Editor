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

	// 获取该工作区的主窗口对象
	wxWindow* getBench() override { return m_bench; }

	// 用来设置停靠方向
	void setDirection(int direction);
	// 用来设置标题
	void setCaption(const wxString& captionName);
	// 用来设置各种停靠属性
	void setPanelInfo(const wxAuiPaneInfo& paneInfo);
	// 获取各种停靠属性
	wxAuiPaneInfo& getPanelInfo();

	// 设置窗口属性列表
	void setWinAttrManager(std::shared_ptr<WindowAttributeManager> winAttrMgr) { m_winAttrMgr = winAttrMgr;  }

protected:
	// 用来获取窗口属性列表
	std::shared_ptr<WindowAttributeManager> m_winAttrMgr;
private:
	wxAuiManager& m_auiManager;
	// 用来记录该区域管理的窗口类
	wxPanel* m_bench;
};

#endif		// EDITOR_TOOL_WINDOW_H