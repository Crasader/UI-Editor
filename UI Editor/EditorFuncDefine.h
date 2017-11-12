#ifndef EDITOR_FUNC_DEFINE_H
#define EDITOR_FUNC_DEFINE_H

#include <wx/string.h>

#define WCHAR_LABEL_TYPE	1

// ����ָʾ���ڵ�����
enum EditorWindowType
{
	EDITOR_DEFAULT_WINDOW = 0,		// �����Ĵ�������
	EDITOR_MANAGER_WINDOW,			// EditorManagerWindow
	EDITOR_CONTAINER_WINDOW,		// EditorContainerWindow
	EDITOR_LABEL,					// EditorLabel
	EDITOR_BUTTON,					// EditorButton
};

using ID_TYPE = int;

// �༭���ڵ���ʼID
const ID_TYPE ID_BEG = 100;

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

#endif	// EDITOR_FUNC_DEFINE_H