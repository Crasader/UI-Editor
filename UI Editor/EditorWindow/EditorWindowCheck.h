#ifndef EDITOR_WINDOW_CHECK_H
#define EDITOR_WINDOW_CHECK_H

#include "EditorWindowInterface.h"

/*
 * �ļ�����EditorWindowCheck
 * ���ã������ڲ���ʱ�ṩ���ֱȽ�����
 */

// ���ǳɹ����ж�
template <typename CheckType = EditorAbstractWindow>
class UiNoCheck
{
public:
	using UiCheckType = CheckType;
public:
	constexpr UiNoCheck() = default;
	~UiNoCheck() = default;

	constexpr bool operator()(const UiCheckType* window) const { return true; }
};

// ������������
template <typename DecoType>
class UiMsgInRegion : public DecoType
{
public:
	using UiCheckType = typename DecoType::UiCheckType;
public:
	constexpr UiMsgInRegion(int x, int y)
		: m_x(x), m_y(y) { }
	~UiMsgInRegion() = default;

	bool operator()(const UiCheckType* window) const			// inline implicit
	{ 
		return window->getMsgRegion().Contains(m_x, m_y) && DecoType::DecoType()(window);
	}

private:
	int m_x;	// x ����
	int m_y;	// y ����
};

// �����ж�ID��ͬ
template <typename DecoType, typename IDType>
class UiIdEqualCheck : public DecoType
{
public:
	using UiCheckType = typename DecoType::UiCheckType;
public:
	UiIdEqualCheck(IDType id)
		: m_id(id)
	{

	}
	~UiIdEqualCheck() = default;

	bool operator()(const UiCheckType* window) const			// inline implicit
	{
		return window->getId() == m_id && DecoType::DecoType()(window); 
	}

private:
	IDType m_id;
};

// �ж��ڱ༭�����Ƿ���Ա༭
template <typename DecoType>
class UiShow : public DecoType
{
public:
	using UiCheckType = typename DecoType::UiCheckType;
public:
	UiShow() = default;
	~UiShow() = default;

	bool operator()(const UiCheckType* window) const		// inline implicit 
	{
		return window->isUiShow() && DecoType::DecoType()(window); 
	}
};

// �ж��Ƿ�������Ӷ���
template <typename DecoType>
class UiContainer : public DecoType
{
public:
	using UiCheckType = typename DecoType::UiCheckType;
public:
	UiContainer() = default;
	~UiContainer() = default;

	bool operator()(const UiCheckType* window) const		// inline implicit
	{
		return window->isContainerWnd() && DecoType::DecoType()(window); 
	}
};


// ����һЩ��������
using Check_Default = UiNoCheck<>;
using Check_UiInMsgRegion = UiMsgInRegion<UiNoCheck<>>;
using Check_UiEditable = UiShow<UiNoCheck<>>;
using Check_UiContainer = UiContainer<UiNoCheck<>>;
using Check_UiIdEqual = UiIdEqualCheck<UiNoCheck<>, ID_TYPE>;

#endif	// EDITOR_WINDOW_CHECK_H
