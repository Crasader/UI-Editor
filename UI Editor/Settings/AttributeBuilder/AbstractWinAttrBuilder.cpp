#include "AbstractWinAttrBuilder.h"

AbstractWinAttrBuilder::AbstractWinAttrBuilder()
{
}

AbstractWinAttrBuilder::~AbstractWinAttrBuilder()
{
}


// ��ȡ���صĴ������ԣ���ȡ�󣬳������¼��أ����򲻿�ʹ��
std::map<wxString, std::vector<AttributeProperty>> AbstractWinAttrBuilder::getWinAttrs()
{
	return std::move(m_winAttrs);
}
