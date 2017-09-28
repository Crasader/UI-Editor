#ifndef COPY_WIN_OBJECT_H
#define COPY_WIN_OBJECT_H

/*
 * �ļ�����CopyWinObject
 * ���ã�Drag & Drop���������ݴ�������ֵ������
 * ע�������ǰֻ����һ��Ӧ��ֱ�ӵĿ����������Ҫ�����޸���ʵ�ֲ�ͬ��Ŀ֮��Ŀ���
 */

#include <map>
#include <type_traits>
#include <wx/string.h>
#include <wx/dataobj.h>
#include "../EditorWindow/WindowFactoryDefine.h"

const wxString COPY_DATA_FORMAT = wxS("CopyWinValue");

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

	// �ú���Ĭ�ϴ���Ľṹ��ΪCopyWindowInfo
	bool GetDataHere(void *buf) const override;
	
	size_t GetDataSize() const override;
	// ���õĽṹ��Ĭ��ΪCopyWindowInfo
	bool SetData(size_t len, const void* buf) override;

	// ������ȡ�洢�Ĵ���������Ϣ
	const CopyWindowInfo& getWinValue() const { return m_data; }

private:
	CopyWindowInfo m_data;
};

#endif	// COPY_WIN_OBJECT_H