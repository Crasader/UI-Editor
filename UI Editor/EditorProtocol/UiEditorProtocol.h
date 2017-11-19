#ifndef UI_EDITOR_PROTOCOL_H
#define UI_EDITOR_PROTOCOL_H


/*
 * �ļ�����UiEditorProtocol
 * ���ã�һЩ��Ҫ���趨�����ڵ��趨���ݰ���
 * 1.�趨��ʹ�ö��ֽڻ���UNICODE
 */

#include <wx/string.h>

#define WCHAR_LABEL_TYPE	1

#if WCHAR_LABEL_TYPE
using LABEL_TYPE = std::wstring;
using LABEL_CHAR = wchar_t;

inline LABEL_TYPE wxStrToStdStr(const wxString& str)
{
	return str.ToStdWstring();
}

// ��Ҫ���õ�str��ʹ�÷���ֵ�������һֱ����
inline const LABEL_CHAR* wxStrToCStr(const wxString& str)
{
	return str.wc_str();
}
#else
// �����ı��༭������
using LABEL_TYPE = std::string;
using LABEL_CHAR = char;

inline LABEL_TYPE wxStrToStdStr(const wxString& str)
{
	return str.ToStdString();
}

// ��Ҫ���õ�str��ʹ�÷���ֵ�������һֱ����
inline const LABEL_CHAR* wxStrToCStr(const wxString& str)
{
	return str.c_str();
}
#endif

#endif	// UI_EDITOR_PROTOCOL_H