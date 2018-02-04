#include <thread>
#include "EditorSave.h"


EditorSave* EditorSave::s_editor_save = nullptr;

EditorSave::EditorSave()
	: m_saveContinue(false)
{
	m_xmlSaver = new EditorUiXmlSaver();
}

// ���д�����Ϣ����
bool EditorSave::operator()()
{
	auto node = m_xmlSaver->addRootWindow(m_info.getWinType(), m_info.getWinAttrs());
	for (auto it = m_info.getChildConstBeg(); it != m_info.getChildConstEnd(); ++it)
	{
		appendNodeInfo(*it, node);
	}
	m_xmlSaver->saveWindow(m_saveFileName);
	return false;
}

// ���洢�Ĵ�����Ϣ���浽�ļ�
void EditorSave::appendNodeInfo(const SaveInfo & info, wxXmlNode *parent)
{
	auto node = m_xmlSaver->appendChildWindow(info.getWinType(), info.getWinAttrs(), parent);
	for (auto it = info.getChildConstBeg(); it != info.getChildConstEnd(); ++it)
	{
		appendNodeInfo(*it, node);
	}
}