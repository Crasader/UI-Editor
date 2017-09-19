#ifndef EDITOR_FRAME_H
#define EDITOR_FRAME_H

/*
 * �ļ�����EditorFrame
 * ���ã�UI Editor������㴰�ڣ���������UI Editor�Ĵ���
 */

#include <wx/wxprec.h>
#include <wx/aui/aui.h>
#include <memory>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Form/EditorWindowFactory.h"

class EditorToolWindow;
class EditorWorkArea;
class WindowAttributeManager;

class EditorFrame : public wxMDIParentFrame
{
public:
	EditorFrame(const wxString& title);
	~EditorFrame();

	// ÿ֡������
	void updateFrame(float dt);

	// ��д���ٺ���
	bool Destroy() override;

private:
	// ���ش�������
	void loadWindowAttributes();
	// ��ʼ���Ӵ���
	void initSubWindows();
	// �����˵���
	void addMenu();

private:
	// ���������ڴ�С�ı�
	void OnSize(wxSizeEvent& event);

private:
	wxAuiManager* m_auiManager;
	// ����������
	std::shared_ptr<WindowAttributeManager> m_winAttrManager;

	// �������������͹��ߴ���
	EditorWindowFactory m_manager;
	// ���ߴ���
	// ��������ѡ��
	EditorToolWindow* m_tool_widget_select;
	// �������ڶ����Ӽ���ϵ
	EditorToolWindow* m_tool_object_view;
	// ���������޸�
	EditorToolWindow* m_tool_property_editor;

	// ����������
	EditorWorkArea* m_editWorkArea;

DECLARE_EVENT_TABLE()
};

// ����һ���������ٵ���Ϣ
wxDECLARE_EVENT(DESTROY_EVENT, wxNotifyEvent);

#endif	// EDITOR_FRAME_H
