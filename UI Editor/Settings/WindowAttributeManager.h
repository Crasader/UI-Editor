#ifndef WINDOW_ATTRIBUTE_LOAD_H
#define WINDOW_ATTRIBUTE_LOAD_H

/*
 * �ļ�����WindowAttributeManager
 * ���ã��������������ӦwxPGProperty֮��Ĺ�ϵ
 * ˵�������ļ��д�������wxPGProperty��һ��wxPGPropertyΪ�������ļ��ж�ȡ�ģ���Ӧ��Ĭ�ϵ�ֵ��
 * ����һ�׶�Ӧ���ڱ༭������ʹ�õģ����е�ֵ�����ű༭���̲��ϸı�
 */

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
	using EDIT_WIN_ATTR_ITERATOR = std::vector<wxPGProperty*>::iterator;
public:
	WindowAttributeManager();
	~WindowAttributeManager();

	bool LoadAttributeFile(const wxString& winAttrFile);

	// ������ȡ��������Ӧ�Ĵ�������
	const std::vector<wxPGProperty*>& getWinAttr(const wxString& winName) const;
	// ������ȡ���Ա༭�Ķ�Ӧ�������ԣ�ͨ��ʹ��iterator������ֻ�޸�ֵ�������ı�
	// ���º�����ҪlogN������ʱ�䣬�����뱣���Ӧ��ITERATOR
	EDIT_WIN_ATTR_ITERATOR getEditWinAttrBeg(const wxString& winName);
	EDIT_WIN_ATTR_ITERATOR getEditWinAttrEnd(const wxString& winName);

private:
	// ����Ĭ�������б�
	void createDefaultAttrs(const std::map<wxString, std::vector<AttributeProperty>>& winAttrs);
	// �����༭�õ������б�
	void createEditAttrs(const std::map<wxString, std::vector<AttributeProperty>>& winAttrs);

private:
	// ������¼����Ĭ��������Ϣ
	std::map<wxString, std::vector<wxPGProperty*>> m_winAttrProperty;
	// ������¼��ǰ�༭�Ĵ���������Ϣ
	std::map<wxString, std::vector<wxPGProperty*>> m_winEditAttrProperty;
	// �������Դ���wxPGProperty
	std::unique_ptr<PropertyFactory> m_propertyFacotry;
};

#endif		// WINDOW_ATTRIBUTE_LOAD_H