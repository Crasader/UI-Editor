#include <thread>
#include "EditorSave.h"

EditorSave::EditorSave()
	: m_saveContinue(true)
{
	m_xmlSaver = new EditorUiXmlSaver();
}

// ���д�����Ϣ����
bool EditorSave::operator()()
{
	auto node = m_xmlSaver->addRootWindow(m_info.getWinType(), m_info.getWinAttrs());
	for (auto it = m_info.getChildConstBeg(); it != m_info.getChildConstEnd(); ++it)
	{
		// ������߳�ȡ�����򷵻�
		if (!m_saveContinue.load(std::memory_order_relaxed))
		{
			return false;
		}

		appendNodeInfo(*it, node);
	}
	// ������߳�ȡ�����򷵻�
	if (!m_saveContinue.load(std::memory_order_relaxed))
	{
		return false;
	}

	m_xmlSaver->saveWindow(m_saveFileName);
	return true;
}

// ���洢�Ĵ�����Ϣ���浽�ļ�
void EditorSave::appendNodeInfo(const SaveInfo & info, wxXmlNode *parent)
{
	// ������߳�����ȡ��������̣���ֱ�ӷ���
	if (!m_saveContinue.load(std::memory_order_relaxed))
	{
		return;
	}

	auto node = m_xmlSaver->appendChildWindow(info.getWinType(), info.getWinAttrs(), parent);
	for (auto it = info.getChildConstBeg(); it != info.getChildConstEnd(); ++it)
	{
		appendNodeInfo(*it, node);
	}
}