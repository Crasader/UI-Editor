#ifndef SIMPLE_WINDOW_INL
#define SIMPLE_WINDOW_INL

#include "SimpleWindow.h"

namespace inner
{
	template <typename T>
	SimpleWindow<T>::SimpleWindow(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height)
		: T(),
		m_parent(parent), m_relX(relX), m_relY(relY), m_width(width), m_height(height),
		m_enable(true),
		m_visible(true),
		m_visibleEnable(true)
	{
		if (parent == nullptr)
		{
			return;
		}
		// �����Ϊ������Ĵ��ڲ��ܴ洢�Ӵ���
		if (!parent->isContainerWnd())
		{
			throw std::runtime_error("parent is not a Container window");
		}
		parent->pushChild(this);
	}

	template <typename T>
	SimpleWindow<T>::~SimpleWindow()
	{

	}

	// �������һ���Ӵ���
	template<typename T>
	inline void SimpleWindow<T>::addChild(SIMPLE_WINDOW_TYPE* child)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__); 
	}

	// ������before����֮ǰ���һ���Ӵ���
	template <typename T>
	bool SimpleWindow<T>::insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__);
		return false;
	}

	// ������iter֮ǰ����Ӵ���
	template<typename T>
	inline bool SimpleWindow<T>::insertChild(SIMPLE_WINDOW_TYPE * child, ConstChildIterator iter)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__);
		return false;
	}

	// �����Ƴ�һ���Ӵ���
	template <typename T>
	bool SimpleWindow<T>::removeChild(SIMPLE_WINDOW_TYPE* child)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__);
		return false;
	}

	// ��ȡ�ô��ڸ��������һ���Ӵ��ڣ�����ô���Ϊ��һ���Ӵ��ڣ��򷵻�nullptr
	// complexity: linear
	template <typename T>
	inline typename SimpleWindow<T>::SIMPLE_WINDOW_TYPE* SimpleWindow<T>::getPrevSibling() const
	{
		auto parentWnd = getParent();
		if (parentWnd == nullptr)
		{
			return nullptr;
		}
		auto siblings = parentWnd->getConstChildren();
		auto myIt = std::find(siblings.cbegin(), siblings.cend(), this);
		// ������Ĭ�Ͽ����ҵ�
		if (myIt != siblings.cbegin())
		{
			return *(--myIt);
		}

		return nullptr;
	}

	// ��ȡ�ô��ڸ��������һ���Ӵ���,����ô���Ϊ���һ���Ӵ��ڣ��򷵻�nullptr
	//	complexity: linear
	template <typename T>
	inline typename SimpleWindow<T>::SIMPLE_WINDOW_TYPE* SimpleWindow<T>::getNextSibling() const
	{
		auto parentWnd = getParent();
		if (parentWnd == nullptr)
		{
			return nullptr;
		}
		auto siblings = parentWnd->getConstChildren();
		auto myIt = std::find(siblings.cbegin(), siblings.cend(), this);
		// ������Ĭ�Ͽ����ҵ�
		if (myIt != (--siblings.cend()))
		{
			return *(++myIt);
		}

		return nullptr;
	}

	// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
	template<typename T>
	inline void SimpleWindow<T>::pushChild(SIMPLE_WINDOW_TYPE* child)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__); 
	}

	// ��ȡ�Ӵ����б�
	template <typename T>
	const typename SimpleWindow<T>::CHILDREN_CONTAINER& SimpleWindow<T>::getConstChildren() const
	{
		return s_defChildrenRet;
	}


	// ��Ҫ�Ӵ����б���ص�Ĭ�Ϸ���ֵ
	template<typename T>
	const typename SimpleWindow<T>::CHILDREN_CONTAINER SimpleWindow<T>::s_defChildrenRet;
}

#endif		// SIMPLE_WINDOW_INL