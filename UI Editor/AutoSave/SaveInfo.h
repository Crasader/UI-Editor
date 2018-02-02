#ifndef SAVE_INFO_H
#define SAVE_INFO_H

#include <map>
#include <vector>
#include <wx/string.h>
#include <wx/any.h>

/*
 * ���������ļ���ÿ��������Ϣ����ǰ��Ϣ������
 * ��1���ô��ڵ�������Ϣ
 * ��2���ô��ڵ��Ӵ�����Ϣ
 */

class SaveInfo
{
public:
	using WIN_ATTR_MAP = std::map<wxString, wxAny>;
public:
	SaveInfo() = default;
	~SaveInfo() = default;
	
	// �������캯�����ƶ����캯��
	SaveInfo(const SaveInfo& info) = delete;
	SaveInfo(SaveInfo&& info) = default;

	SaveInfo& operator=(const SaveInfo& info) = delete;
	SaveInfo& operator=(SaveInfo&& info) = default;

	// ���ô���������
	void setWinType(const wxString& winType) { m_winType = winType; }
	// ���øô��ڵ���������
	void setWinAttrs(const WIN_ATTR_MAP& winAttrs) { m_allWinAttrs = winAttrs; }

	// ���Ӵ�����Ϣ�洢���ö�����
	void push_back(const SaveInfo& info) = delete;
	void push_back(SaveInfo&& info) { m_childrens.push_back(std::move(info)); }

private:
	// �ô��ڵ���������
	wxString m_winType;
	// �ô��ڵ���������
	WIN_ATTR_MAP m_allWinAttrs;
	// �ô��ڵ��Ӵ���
	std::vector<SaveInfo> m_childrens;
};

#endif	// SAVE_INFO_H