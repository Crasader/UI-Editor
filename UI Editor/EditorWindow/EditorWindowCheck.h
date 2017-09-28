#ifndef EDITOR_WINDOW_CHECK_H
#define EDITOR_WINDOW_CHECK_H

/*
 * �ļ�����EditorWindowCheck
 * ���ã������ڲ���ʱ�ṩ���ֱȽ�����
 */

#include "WindowInterface.h"

// ���ǳɹ����ж�
template <typename T>
class UiNoCheck
{
public:
	UiNoCheck() = default;
	~UiNoCheck() = default;

	bool operator()(T* window) { return true; }
};

// �ж��ڱ༭�����Ƿ���Ա༭
template <typename T>
class UiEditable
{
public:
	UiEditable() = default;
	~UiEditable() {}

	bool operator()(T* window) { return window->isUiEditable(); }
};

// �ж��ڱ༭�����Ƿ�Ϊ���ɱ༭���ҿ������Ӷ���
template <typename T>
class UiEditableContainer
{
public:
	UiEditableContainer() = default;
	~UiEditableContainer() {}

	bool operator()(T* window) { return window->isUiEditable() && window->isContainerWnd(); }
};

#endif	// EDITOR_WINDOW_CHECK_H
