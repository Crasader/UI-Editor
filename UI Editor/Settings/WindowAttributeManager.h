#ifndef WINDOW_ATTRIBUTE_LOAD_H
#define WINDOW_ATTRIBUTE_LOAD_H

#include <wx/wx.h>
#include <map>
#include <vector>
#include <memory>

#include "WindowAttributeDefine.h"

class wxPGProperty;
class PropertyFactory;

class WindowAttributeManager
{
public:
	WindowAttributeManager();
	~WindowAttributeManager();

	bool LoadAttributeFile(const wxString& winAttrFile);

	// ������ȡ��������Ӧ�Ĵ�������
	const std::vector<wxPGProperty*>& getWinAttr(const wxString& winName) const;

private:
	// ������¼����������Ϣ
	std::map<wxString, std::vector<wxPGProperty*>> m_winAttrProperty;
	// �������Դ���wxPGProperty
	std::unique_ptr<PropertyFactory> m_propertyFacotry;
};

#endif		// WINDOW_ATTRIBUTE_LOAD_H