#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H

/*
 * �ļ�����WindowInterface
 * ���ã���������༭����ʹ�õĽӿ�
 */

#include "EditorFunc.h"
#include "AbstractEditorWindow.h"
#include "EditorContainerWindow.h"

using AbstractEditorWindow = inner::SimpleWindow<inner::EditorFunc>;
using ContainterEditorWindow = inner::ContainerWindow<inner::EditorContainerFunc>;

#endif	// WINDOW_INTERFACE_H
