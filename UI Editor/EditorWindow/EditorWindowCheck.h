#ifndef EDITOR_WINDOW_CHECK_H
#define EDITOR_WINDOW_CHECK_H

/*
 * �ļ�����EditorWindowCheck
 * ���ã������ڲ���ʱ�ṩ���ֱȽ�����
 */

#include "EditorWindowInterface.h"

// ���ǳɹ����ж�
template <typename CheckType = EditorAbstractWindow>
class UiNoCheck
{
public:
	UiNoCheck() = default;
	~UiNoCheck() = default;

	bool operator()(CheckType* window) { return true; }
};

// �ж��ڱ༭�����Ƿ���Ա༭
template <typename DecoType, typename CheckType = EditorAbstractWindow>
class UiEditable : public DecoType
{
public:
	UiEditable() = default;
	~UiEditable() {}

	bool operator()(CheckType* window) { return window->isUiEditable() && DecoType::DecoType()(window); }
};

// �ж��Ƿ�������Ӷ���
template <typename DecoType, typename CheckType = EditorAbstractWindow>
class UiContainer : public DecoType
{
public:
	UiContainer() = default;
	~UiContainer() = default;

	bool operator()(CheckType* window) { return window->isContainerWnd() && DecoType::DecoType()(window); }
};

// ����һЩ��������
using Check_UiEditable = UiEditable<UiNoCheck<>>;
using Check_UiContainer = UiContainer<UiNoCheck<>>;

#endif	// EDITOR_WINDOW_CHECK_H
