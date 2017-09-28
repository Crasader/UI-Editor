#include "CopyWinObject.h"

// �ú���Ĭ�ϴ���Ľṹ��ΪCopyWindowInfo
bool CopyWinObject::GetDataHere(void* buf) const
{
	CopyWindowInfo* value = reinterpret_cast<CopyWindowInfo*>(buf);
	new (buf) CopyWindowInfo;
	*value = m_data;
	return true;
}


size_t CopyWinObject::GetDataSize() const
{
	return sizeof(m_data);
}

// ���õĽṹ��Ĭ��ΪCopyWindowInfo
bool CopyWinObject::SetData(size_t len, const void * buf)
{
	const CopyWindowInfo* value = reinterpret_cast<const CopyWindowInfo*>(buf);
	m_data = *value;
	return true;
}
