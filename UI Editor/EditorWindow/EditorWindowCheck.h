#ifndef EDITOR_WINDOW_CHECK_H
#define EDITOR_WINDOW_CHECK_H

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
	UiNoCheck() = default;
	~UiNoCheck() = default;

	bool operator()(const UiCheckType* window) const { return true; }
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

	bool operator()(const UiCheckType* window) const { return window->getId() == m_id && DecoType::DecoType()(window); }

private:
	IDType m_id;
};

// �ж��ڱ༭�����Ƿ���Ա༭
template <typename DecoType>
class UiEditable : public DecoType
{
public:
	using UiCheckType = typename DecoType::UiCheckType;
public:
	UiEditable() = default;
	~UiEditable() = default;

	bool operator()(const UiCheckType* window) const { return window->isUiEditable() && DecoType::DecoType()(window); }
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

	bool operator()(const UiCheckType* window) const { return window->isContainerWnd() && DecoType::DecoType()(window); }
};

// ����һЩ��������
using Check_UiEditable = UiEditable<UiNoCheck<>>;
using Check_UiContainer = UiContainer<UiNoCheck<>>;
using Check_UiIdEqual = UiIdEqualCheck<UiNoCheck<>, ID_TYPE>;

#endif	// EDITOR_WINDOW_CHECK_H
