#include "AbstractWinAttrBuilder.h"

AbstractWinAttrBuilder::AbstractWinAttrBuilder()
{
}

AbstractWinAttrBuilder::~AbstractWinAttrBuilder()
{
}


// ��ȡ���صĿؼ����ԣ��ڵ���loadWinAttr��ֻ�ɵ���һ��
std::map<wxString, std::vector<WinAttrProperty>> AbstractWinAttrBuilder::getWinAttrs()
{
	return std::move(m_winAttrs);
}
