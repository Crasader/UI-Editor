#ifndef EDITOR_WINDOW_DEFINE_H
#define EDITOR_WINDOW_DEFINE_H

/*
 * �ļ�����EditorWindowType
 * ���ã����һЩ����Editorϵ�пؼ��ĸ������������
 */

// Enable״̬���Ƿ���ʾ���Լ��Ƿ�Ϊfocus�ж���Ķ����ʶ
enum EDITOR_WINDOW_STATE
{
	EDITOR_STATE_NORMAL = 0,			// ����״̬����ʶ��겻�ڿؼ���
	EDITOR_STATE_MOUSE_OVER = 1,		// ����ڿؼ���
	EDITOR_STATE_PRESSED = 2,			// ����ڿؼ��ϰ���
};


#endif	// EDITOR_WINDOW_DEFINE_H
