#ifndef EDITOR_UI_XML_SAVER_H
#define EDITOR_UI_XML_SAVER_H

/*
 * �ļ�����EditorUiXmlSaver
 * ���ã��ṩ�������ļ�����Ĺ���
 */

#include <map>
#include <wx/string.h>
#include <wx/any.h>

class wxXmlDocument;
class wxXmlNode;
class wxXmlAttribute;

class EditorUiXmlSaver
{
public:
	using WIN_ATTR_MAP = std::map<wxString, wxAny>;
public:
	EditorUiXmlSaver();
	~EditorUiXmlSaver() = default;

	// ���һ������
	wxXmlNode* addRootWindow(const wxString& winType, const WIN_ATTR_MAP& winAttrs);
	// ���һ���Ӵ���
	wxXmlNode* appendChildWindow(const wxString& winType, const WIN_ATTR_MAP& winAttrs, wxXmlNode* parent);
	// ���洰����Ϣ���ļ�
	bool saveWindow(const wxString& fileName);

private:
	// ���ݴ���������б���ȡxml�ڵ�������б�
	wxXmlAttribute* getXmlAttr(const WIN_ATTR_MAP& winAttrs);
	// ��ʼ��UI�ļ�����
	void initXmlSaver();

private:
	wxXmlDocument* m_doc = nullptr;
};

#endif	// EDITOR_UI_XML_SAVER_H