#ifndef EDITOR_WINDOW_INTERFACE_H
#define EDITOR_WINDOW_INTERFACE_H

/*
 * �ļ�����WindowInterface
 * ���ã���������༭�ؼ�ʹ�õĽӿ�
 */

#include "EditorAbstractWindow.h"
#include "EditorContainerWindow.h"

using EditorAbstractWindow = inner::SimpleWindow<inner::EditorFunc>;
using ContainterEditorWindow = inner::ContainerWindow<inner::EditorContainerFunc>;

#endif	// EDITOR_WINDOW_INTERFACE_H
