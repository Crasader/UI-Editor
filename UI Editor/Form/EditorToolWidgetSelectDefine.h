#ifndef EDITOR_TOOL_WIDGET_SELECT_DEFINE_H
#define EDITOR_TOOL_WIDGET_SELECT_DEFINE_H

#include <wx/treebase.h>
#include <wx/string.h>

/*
 * �ļ�����EditorToolWidgetSelectDefine
 * ���ã���1����Ҫ��Ϊ��EditorToolWidgetSelect������ִ���ID
 * ��2��������һЩ�궨�壬�������壬�򵥺��������
 */

// ���¶���Ŀǰֻ��Ϊ�˱��ڹ�����֮����Կ����ⲿ�ֹ���Ҳ������WindowAttribute.xml�е�����
// ����������ʾ�ʹ�������

const wxString EDITOR_WINDOW_TYPE = wxS("GWindow");		// ���ɴ���
const wxString EDITOR_WINDOW_SHOW = wxS("Window");

const wxString EDITOR_LABEL_TYPE = wxS("GLabel");		// ���Դ���
const wxString EDITOR_LABEL_SHOW = wxS("Label");

const wxString EDITOR_BUTTON_TYPE = wxS("GButton");		// ���Դ���
const wxString EDITOR_BUTTON_SHOW = wxS("Button");


// �洢�ڴ���ѡ��ڵ��е�����
class WidgetSelectItemName : public wxTreeItemData
{
public:
	WidgetSelectItemName(const wxString& widgetName)
		: m_widgetName(widgetName)
	{

	}

	~WidgetSelectItemName() override {}

	// ������ȡ���ڶ�Ӧ������
	wxString getWidgetName() const { return m_widgetName;  }

private:
	wxString m_widgetName;
};

#endif	// EDITOR_TOOL_WIDGET_SELECT_DEFINE_H
