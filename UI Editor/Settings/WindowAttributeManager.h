#ifndef WINDOW_ATTRIBUTE_LOAD_H
#define WINDOW_ATTRIBUTE_LOAD_H

/*
 * �ļ�����WindowAttributeManager
 * ���ã���������ؼ����ӦwxPGProperty֮��Ĺ�ϵ
 * ˵�������ļ��д�������wxPGProperty��һ��wxPGPropertyΪ�������ļ��ж�ȡ�ģ���Ӧ��Ĭ�ϵ�ֵ��
 * ����һ�׶�Ӧ���ڱ༭������ʹ�õģ����е�ֵ�����ű༭���̲��ϸı�
 */

#include <map>
#include <vector>
#include <memory>
#include <wx/wx.h>
#include "WinAttrAndNameProtocol.h"

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

	// ������ȡ�ؼ�����Ӧ��Ĭ�Ͽؼ�����
	const std::vector<wxPGProperty*>& getWinAttr(const wxString& winName) const;
	// ������ȡ�ؼ�����Ӧ��Ĭ������ֵ
	const std::map<wxString, wxAny>& getWinDefValues(const wxString& winName) const;
	// ������ȡ�ؼ�����Ӧ�ı༭����ֵ
	const std::vector<wxPGProperty*>& getEditWinAttr(const wxString& winName) const;
	//// ������ȡ���Ա༭�Ķ�Ӧ�ؼ����ԣ�ͨ��ʹ��iterator������ֻ�޸�ֵ�������ı�
	//// ���º�����ҪlogN������ʱ�䣬�����뱣���Ӧ��ITERATOR
	//EDIT_WIN_ATTR_ITERATOR getEditWinAttrBeg(const wxString& winName);
	//EDIT_WIN_ATTR_ITERATOR getEditWinAttrEnd(const wxString& winName);

private:
	// ����Ĭ�������б�
	void createDefaultAttrs(const std::map<wxString, std::vector<WinAttrProperty>>& winAttrs);
	// �����༭�õ������б�
	void createEditAttrs(const std::map<wxString, std::vector<WinAttrProperty>>& winAttrs);

private:
	// ������¼�ؼ�Ĭ��������Ϣ
	std::map<wxString, std::vector<wxPGProperty*>> m_winAttrProperty;
	// ������¼�ؼ�Ĭ��������Ϣ
	std::map<wxString, std::map<wxString, wxAny>> m_winAttrDefValues;
	// ������¼��ǰ�༭�Ŀؼ�������Ϣ
	std::map<wxString, std::vector<wxPGProperty*>> m_winEditAttrProperty;
	// �������Կؼ�wxPGProperty
	std::unique_ptr<PropertyFactory> m_propertyFacotry;
};

#endif		// WINDOW_ATTRIBUTE_LOAD_H