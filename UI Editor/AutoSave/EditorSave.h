#ifndef EDITOR_SAVE_H
#define EDITOR_SAVE_H

/*
 * �����ļ������ģ��
 */

#include <atomic>
#include "SaveInfo.h"

class EditorSave
{
public:
	static EditorSave* createInstance() { s_editor_save = new EditorSave(); return s_editor_save; }
	static EditorSave* getInstance() { return s_editor_save; }
	static void destroyInstance() { delete s_editor_save; s_editor_save = nullptr; }

	~EditorSave() = default;

	// ���ô洢���ļ���Ϣ
	void setSaveInfo(const SaveInfo& info) = delete;
	void setSaveInfo(SaveInfo&& info) { m_info = std::move(info); }
	// ���ô洢�ļ�����
	void setSaveFileName(const wxString& fileName) { m_saveFileName = fileName; }
	void setSaveFileName(wxString&& fileName) { m_saveFileName = std::move(fileName); }
	// ���������Ƿ�����������
	// �̰߳�ȫ����
	void setSaveContinue(bool cont) { m_saveContinue.store(cont); }
	// ���д�����Ϣ����
	bool operator()();
private:
	EditorSave();

	static EditorSave* s_editor_save;

	// ��Ҫ�洢�Ĵ�����Ϣ
	SaveInfo m_info;
	// �洢�����ļ�����
	wxString m_saveFileName;
	// �����ж����߳��Ƿ�ȡ������
	std::atomic<bool> m_saveContinue;
};

#endif	// EDITOR_SAVE_H
