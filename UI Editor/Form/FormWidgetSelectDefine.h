#ifndef FORM_WIDGET_SELECT_DEFINE_H
#define FORM_WIDGET_SELECT_DEFINE_H

#include <wx/treebase.h>
#include <wx/string.h>

/*
 * �ļ�����EditorToolWidgetSelectDefine
 * ���ã�
 * ��1���ڵ����Ͷ���
 */


// �洢�ڿؼ�ѡ��ڵ��е�����
class WidgetSelectItemName : public wxTreeItemData
{
public:
	WidgetSelectItemName(const wxString& widgetName)
		: m_widgetName(widgetName)
	{

	}

	~WidgetSelectItemName() override {}

	// ������ȡ�ؼ�������
	wxString getWidgetName() const { return m_widgetName;  }

private:
	wxString m_widgetName;
};

#endif	// FORM_WIDGET_SELECT_DEFINE_H
