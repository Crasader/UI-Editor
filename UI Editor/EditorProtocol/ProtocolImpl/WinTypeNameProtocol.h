#ifndef WIN_TYPE_NAME_PROTOCOL_H
#define WIN_TYPE_NAME_PROTOCOL_H

#include <wx/treebase.h>
#include <wx/string.h>

/*
 * �ļ�����EditorToolWidgetSelectDefine
 * ���ã�
 * ��1��������һЩ�궨�壬�������壬�򵥺��������
 */

// ���¶���Ŀǰֻ��Ϊ�˱��ڹ�����֮����Կ����ⲿ�ֹ���Ҳ������WindowAttribute.xml�е�����
// �ؼ�������ʾ�Ϳؼ�����

const wxString EDITOR_WINDOW_TYPE = wxS("GWindow");		// ���ɴ���
const wxString EDITOR_WINDOW_SHOW = wxS("Window");

const wxString EDITOR_LABEL_TYPE = wxS("GLabel");		// ���Դ���
const wxString EDITOR_LABEL_SHOW = wxS("Label");

const wxString EDITOR_BUTTON_TYPE = wxS("GButton");		// ���Դ���
const wxString EDITOR_BUTTON_SHOW = wxS("Button");


#endif	// WIN_TYPE_NAME_PROTOCOL_H
