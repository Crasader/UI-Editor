#ifndef EDITOR_SAVE_H
#define EDITOR_SAVE_H

/*
 * �����ļ������ģ��
 */

#include <atomic>
#include "SaveInfo.h"
#include "EditorUiXmlSaver.h"

class wxXmlNode;

class EditorSave
{
public:
	EditorSave();
	~EditorSave() = default;

	// ���ô洢���ļ���Ϣ
	void setSaveInfo(const SaveInfo& info) = delete;
	void setSaveInfo(SaveInfo&& info) { m_info = std::move(info); }
	// ���ô洢�ļ�����
	void setSaveFileName(const wxString& fileName) { m_saveFileName = fileName; }
	void setSaveFileName(wxString&& fileName) { m_saveFileName = std::move(fileName); }
	// ���������Ƿ�����������
	// �̰߳�ȫ����
	void setSaveContinue(bool cont) { m_saveContinue.store(cont, std::memory_order_release); }
	// ���д�����Ϣ����
	bool operator()();

private:
	// ���洢�Ĵ�����Ϣ���浽�ļ�
	void appendNodeInfo(const SaveInfo& info, wxXmlNode* parent);

	// ��Ҫ�洢�Ĵ�����Ϣ
	SaveInfo m_info;
	// �洢�����ļ�����
	wxString m_saveFileName;
	// �����ж����߳��Ƿ�ȡ������
	std::atomic<bool> m_saveContinue;

	// ���ڱ��洰��UI�Ĺ�����
	EditorUiXmlSaver* m_xmlSaver = nullptr;
};

#endif	// EDITOR_SAVE_H
