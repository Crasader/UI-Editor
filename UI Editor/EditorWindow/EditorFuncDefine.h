#ifndef EDITOR_FUNC_DEFINE_H
#define EDITOR_FUNC_DEFINE_H

// ����ָʾ���ڵ�����
enum EditorWindowType
{
	EDITOR_DEFAULT_WINDOW = 0,		// �����Ĵ�������
	EDITOR_MANAGER_WINDOW,			// EditorManagerWindow
	EDITOR_CONTAINER_WINDOW,		// EditorContainerWindow
	EDITOR_LABEL,					// EditorLabel
	EDITOR_BUTTON,					// EditorButton
};

using ID_TYPE = int;

// �༭���ڵ���ʼID
const ID_TYPE ID_BEG = 100;

#endif	// EDITOR_FUNC_DEFINE_H