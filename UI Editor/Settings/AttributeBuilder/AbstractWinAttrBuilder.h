#ifndef ABSTRACT_WIN_ATTR_BUILDER_H
#define ABSTRACT_WIN_ATTR_BUILDER_H

#include <map>
#include <vector>
#include "../WindowAttributeDefine.h"

class AbstractWinAttrBuilder
{
public:
	AbstractWinAttrBuilder();
	virtual ~AbstractWinAttrBuilder();

	// ���ظ��ര�ڶ�Ӧ������
	virtual bool loadWinAttr() = 0;

	// ��ȡ���صĴ������ԣ���ȡ�󣬳������¼��أ����򲻿�ʹ��
	std::map<wxString, std::vector<AttributeProperty>> getWinAttrs();

protected:
	std::map<wxString, std::vector<AttributeProperty>> m_winAttrs;
};


#endif	// ABSTRACT_WIN_ATTR_BUILDER_H
