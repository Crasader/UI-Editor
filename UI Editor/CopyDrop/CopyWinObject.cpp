#include "CopyWinObject.h"

// �ú���Ĭ�ϴ���Ľṹ��ΪCopyWindowValue
bool CopyWinObject::GetDataHere(void* buf) const
{
	CopyWindowValue* value = reinterpret_cast<CopyWindowValue*>(buf);
	new (buf) CopyWindowValue;
	*value = m_data;
	return true;
}


size_t CopyWinObject::GetDataSize() const
{
	return sizeof(m_data);
}

// ���õĽṹ��Ĭ��ΪCopyWindowValue
bool CopyWinObject::SetData(size_t len, const void * buf)
{
	const CopyWindowValue* value = reinterpret_cast<const CopyWindowValue*>(buf);
	m_data = *value;
	return true;
}
