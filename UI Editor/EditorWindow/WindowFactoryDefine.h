#ifndef WINDOW_FACTORY_DEFINE_H
#define WINDOW_FACTORY_DEFINE_H

/*
 * �ļ�����WindowFactoryDefine
 * ���ã������봴�������йص�����
 */

#include "EditorFuncDefine.h"

// �����������Ĭ�ϵĿ��͸�

// EditorWindow
const int EDITOR_WINDOW_WIDTH = 30;
const int EDITOR_WINDOW_HEIGHT = 15;

// EditorLabel
const int EDITOR_LABEL_WIDTH = 30;
const int EDITOR_LABEL_HEIGHT = 15;

// EditorButton
const int EDITOR_BUTTON_WIDTH = 30;
const int EDITOR_BUTTON_HEIGHT = 15;

// ���ݴ������Ϣ���½�һ�����ڶ���
class CopyWindowInfo
{
public:
	using WIN_ATTR_VALUE_LIST = std::map<wxString, wxAny>;
public:
	CopyWindowInfo(const wxString &winName = wxS(""))
		: m_winName(winName)
	{

	}
	~CopyWindowInfo() {}

	// �������캯��
	CopyWindowInfo(const CopyWindowInfo& right)
		: m_winName(right.m_winName), m_winAttrValues(right.m_winAttrValues)
	{

	}
	CopyWindowInfo(CopyWindowInfo&& right) noexcept(std::is_nothrow_move_constructible<wxString>::value
		&& std::is_nothrow_constructible<std::map<wxString, wxAny>>::value)
		: m_winName(std::move(right.m_winName)), m_winAttrValues(std::move(right.m_winAttrValues))
	{

	}
	// ��ֵ�����
	CopyWindowInfo& operator=(const CopyWindowInfo& right)
	{
		m_winName = right.m_winName;
		m_winAttrValues = right.m_winAttrValues;
		return *this;
	}
	CopyWindowInfo& operator=(CopyWindowInfo&& right) noexcept(std::is_nothrow_move_assignable<wxString>::value
		&& std::is_nothrow_move_assignable<std::map<wxString, wxAny>>::value)
	{
		m_winName = std::move(right.m_winName);
		m_winAttrValues = std::move(right.m_winAttrValues);
		return *this;
	}
	// ���ô�����
	void setWinName(const wxString& winName) { m_winName = winName; }
	// ��ȡ������
	const wxString& getWinName() const { return m_winName; }
	// ����һ����������
	void add(const wxString winAttr, const wxAny& attrValue) { m_winAttrValues.insert(std::make_pair(winAttr, attrValue)); }
	// ��ȡ��������
	const WIN_ATTR_VALUE_LIST& getWinAttrValues() const { return m_winAttrValues; }
	// �ƶ���������
	WIN_ATTR_VALUE_LIST&& moveWinAttrValues() { return std::move(m_winAttrValues); }
private:
	// ������
	wxString m_winName;
	// ��������ֵ��
	std::map<wxString, wxAny> m_winAttrValues;
};

#endif	// WINDOW_FACTORY_DEFINE_H