#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H

/*
 * �ļ�����WindowInterface
 * ���ã���������༭����ʹ�õĽӿ�
 */

namespace inner
{
	class EditorFunc;
	template <typename T>
	class SimpleWindow;
}

using AbstractEditorWindow = inner::SimpleWindow<inner::EditorFunc>;


#endif	// WINDOW_INTERFACE_H
