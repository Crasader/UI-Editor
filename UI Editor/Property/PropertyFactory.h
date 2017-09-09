#ifndef PROPERTY_FACTORY_H
#define PROPERTY_FACTORY_H

#include <map>
#include <wx/string.h>
#include "../ErrorHandle/ErrorHandle.h"

struct AttributeProperty;
class wxPGProperty;
class wxEnumProperty;

class PropertyFactory
{
public:
	PropertyFactory();
	~PropertyFactory() {}

	// ��̬����
	static const PropertyFactory* Instance();

	// �������ò�������ȡһ��wxPGProperty
	wxPGProperty* createProperty(const AttributeProperty& attrProperty) const;
	// ���������б�
	void destroyProperty(wxPGProperty* &property);

private:
	// ���ñ༭���ĸ�������
	void setEditorAttributes(wxPGProperty* property, const std::map<wxString, wxString>& editorAttrs) const;
	// ���ݴ����xml������������ȡwxWidgets�ж�Ӧ������
	const wxString& getwxAttrFromXmlAttr(const wxString& xmlAttr) const;
	// ��ʼ����������
	void initXmlAttrTowxAttr();

private:
	static PropertyFactory *s_propertyFactory;
	// ��¼XML��Attribute��wxWidgets�����ԵĹ�ϵ
	std::map<wxString, wxString> m_xmlAttrTowxAttr;
};

namespace PropertyFactoryImpl
{
	// ������������������
	wxPGProperty* createPropertyFromName(const wxString& propertyName, const wxString& editorProperty);
	// ���ݱ༭���������ñ༭��
	void setPropertyEditor(wxPGProperty* property, const wxString& editorName);
	// �������Ա༭��֤��
	void setEditorValidator(wxPGProperty* property, const wxString& validatorName);
	// �������Ե�һЩ��������
	void SetPropertyAdditional(wxPGProperty* property, const std::map<wxString, wxString>& additionalInfos);
	// ����EnumProperty��һЩ��������
	void SetEnumPropAdditional(wxEnumProperty* property, const std::map<wxString, wxString>& additionalInfos);
}

// ���ݴ����xml������������ȡwxWidgets�ж�Ӧ������
inline const wxString& PropertyFactory::getwxAttrFromXmlAttr(const wxString& xmlAttr) const
{
	const auto it = m_xmlAttrTowxAttr.find(xmlAttr);
	if (it != m_xmlAttrTowxAttr.cend())
	{
		return it->second;
	}

	throw ExtraException::unexpected_situation("PropertyFactory::getwxAttrFromXmlAttr: wxAttr should be found.");
	thread_local wxString errorRet = wxString("");
	return errorRet;
}

#endif	// PROPERTY_FACTORY_H