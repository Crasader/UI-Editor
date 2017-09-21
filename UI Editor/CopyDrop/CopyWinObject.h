#ifndef COPY_WIN_OBJECT_H
#define COPY_WIN_OBJECT_H

/*
 * �ļ�����CopyWinObject
 * ���ã�Drag & Drop���������ݴ�������ֵ������
 * ע�������ǰֻ����һ��Ӧ��ֱ�ӵĿ����������Ҫ�����޸���ʵ�ֲ�ͬ��Ŀ֮��Ŀ���
 */

#include <vector>
#include <type_traits>
#include <wx/string.h>
#include <wx/dataobj.h>

const wxString COPY_DATA_FORMAT = wxS("CopyWinValue");

class CopyWindowValue
{
public:
	using WIN_ATTR_VALUE_LIST = std::vector<std::pair<wxString, wxAny>>;
public:
	CopyWindowValue(const wxString &winName = wxS(""))
		: m_winName(winName)
	{

	}
	~CopyWindowValue() {}
	
	// �������캯��
	CopyWindowValue(const CopyWindowValue& right)
		: m_winName(right.m_winName), m_winAttrValues(right.m_winAttrValues)
	{

	}
	CopyWindowValue(CopyWindowValue&& right) noexcept(std::is_nothrow_move_constructible<wxString>::value
		&& std::is_nothrow_constructible<std::vector<std::pair<wxString, wxAny>>>::value)
		: m_winName(std::move(right.m_winName)), m_winAttrValues(std::move(right.m_winAttrValues))
	{

	}
	// ��ֵ�����
	CopyWindowValue& operator=(const CopyWindowValue& right)
	{
		m_winName = right.m_winName;
		m_winAttrValues = right.m_winAttrValues;
		return *this;
	}
	CopyWindowValue& operator=(CopyWindowValue&& right) noexcept(std::is_nothrow_move_assignable<wxString>::value
		&& std::is_nothrow_move_assignable<std::vector<std::pair<wxString, wxAny>>>::value)
	{
		m_winName = std::move(right.m_winName);
		m_winAttrValues = std::move(right.m_winAttrValues);
		return *this;
	}
	// ���ô�����
	void setWinName(const wxString& winName) { m_winName = winName;  }
	// ��ȡ������
	const wxString& getWinName() const { return m_winName; }
	// ���һ����������
	void add(const wxString winAttr, const wxAny& attrValue) { m_winAttrValues.push_back(std::make_pair(winAttr, attrValue)); }
	// ��ȡ��������
	const WIN_ATTR_VALUE_LIST& getWinAttrValues() const { return m_winAttrValues; }
private:
	// ������
	wxString m_winName;
	// ��������ֵ��
	std::vector<std::pair<wxString, wxAny>> m_winAttrValues;
};

// ��ȡһ���Զ����DataFormat
inline wxDataFormat getCopyDataFormat()
{
	wxDataFormat format;
	format.SetId(COPY_DATA_FORMAT);
	return format;
}

class CopyWinObject : public wxDataObjectSimple
{
public:
	CopyWinObject(const wxDataFormat& format = wxFormatInvalid)
		: wxDataObjectSimple(format)
	{

	}

	// �ú���Ĭ�ϴ���Ľṹ��ΪCopyWindowValue
	bool GetDataHere(void *buf) const override;
	
	size_t GetDataSize() const override;
	// ���õĽṹ��Ĭ��ΪCopyWindowValue
	bool SetData(size_t len, const void* buf) override;

	// ������ȡ�洢�Ĵ���������Ϣ
	const CopyWindowValue& getWinValue() const { return m_data; }

private:
	CopyWindowValue m_data;
};

#endif	// COPY_WIN_OBJECT_H