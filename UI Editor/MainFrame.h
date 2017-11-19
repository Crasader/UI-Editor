#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

/*
 * �ļ�����MainFrame
 * ���ã�UI Editor������㴰�ڣ���������UI Editor�Ĵ���
 */

#include <memory>
#include <wx/wxprec.h>
#include <wx/aui/aui.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Form/FormFactory.h"

class FormToolWindow;
class FormWidgetSelect;
class FormObjectView;
class FormPropertyEditor;
class FormWorkArea;
class WindowAttributeManager;

class MainFrame : public wxMDIParentFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame();

	// ÿ֡������
	void updateFrame(float dt);
	// ��д���ٺ���
	bool Destroy() override;
	// ��ȡ���ܴ���
	std::shared_ptr<FormObjectView> getObjectView() const { return m_tool_object_view; }
	std::shared_ptr<FormPropertyEditor> getPropertyEditor() const { return m_tool_property_editor; }
	std::shared_ptr<FormWorkArea> getWorkArea() const { return m_editWorkArea; }

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

	// �������������͹�����
	FormFactory m_manager;
	// ���ߴ���
	// �ؼ�����ѡ��
	std::shared_ptr<FormWidgetSelect> m_tool_widget_select;
	// չʾ�ؼ������Ӽ���ϵ
	std::shared_ptr<FormObjectView> m_tool_object_view;
	// �ؼ������޸�
	std::shared_ptr<FormPropertyEditor> m_tool_property_editor;

	// ��������
	std::shared_ptr<FormWorkArea> m_editWorkArea;

DECLARE_EVENT_TABLE()
};

// ����һ���������ٵ���Ϣ
wxDECLARE_EVENT(DESTROY_EVENT, wxNotifyEvent);

#endif	// MAIN_FRAME_H
