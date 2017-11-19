#ifndef XML_WIN_ATTR_BUILDER_H
#define XML_WIN_ATTR_BUILDER_h

#include "AbstractWinAttrBuilder.h"

class wxXmlNode;

class XmlWinAttrBuilder : public AbstractWinAttrBuilder
{
public:
	XmlWinAttrBuilder(const wxString& xmlName);
	~XmlWinAttrBuilder();

	// ���ؿؼ�����
	bool loadWinAttr() override;

private:
	// ����һ���ڵ�
	void loadXmlNode(wxXmlNode* node, std::vector<WinAttrProperty> winAttrs);
	// ����һ��Attribute������
	void AnalyzeNode(wxXmlNode* node, WinAttrProperty& attrProperty);

private:
	wxString m_xmlName;
};

#endif	// XML_WIN_ATTR_BUILDER_H
