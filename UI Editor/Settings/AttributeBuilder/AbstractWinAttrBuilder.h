#ifndef ABSTRACT_WIN_ATTR_BUILDER_H
#define ABSTRACT_WIN_ATTR_BUILDER_H

#include <map>
#include <vector>
#include "WinAttrAndNameProtocol.h"

class AbstractWinAttrBuilder
{
public:
	AbstractWinAttrBuilder();
	virtual ~AbstractWinAttrBuilder();

	// ���ظ���ؼ���Ӧ������
	virtual bool loadWinAttr() = 0;

	// ��ȡ���صĿؼ����ԣ��ڵ���loadWinAttr��ֻ�ɵ���һ��
	std::map<wxString, std::vector<WinAttrProperty>> getWinAttrs();

protected:
	std::map<wxString, std::vector<WinAttrProperty>> m_winAttrs;
};


#endif	// ABSTRACT_WIN_ATTR_BUILDER_H
