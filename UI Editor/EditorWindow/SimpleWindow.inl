#ifndef SIMPLE_WINDOW_INL
#define SIMPLE_WINDOW_INL

#include "SimpleWindow.h"

namespace inner
{
	template <typename T>
	SimpleWindow<T>::SimpleWindow(SimpleWindow<T>* parent, int relX, int relY, int width, int height)
		: m_parent(parent), m_relX(relX), m_relY(relY), m_width(width), m_height(height),
		m_enable(true),
		m_visible(true),
		m_visibleEnable(true)
	{

	}

	template <typename T>
	SimpleWindow<T>::~SimpleWindow()
	{

	}

	// �������һ���Ӵ���
	template <typename T>
	void SimpleWindow<T>::AddChild(SimpleWindow<T>* child)
	{
		m_children.push_back(child);
	}

	// ������ĳ������֮ǰ���һ���Ӵ���
	template <typename T>
	bool SimpleWindow<T>::InsertChild(SimpleWindow<T>* child, const SimpleWindow<T>* before)
	{
		const auto it = std::find(m_children.cbegin(), m_children.cend(), before);
		if (it != m_children.cend())
		{
			m_children.insert(it, child);
			return true;
		}

		return false;
	}

	// �����Ƴ�һ���Ӵ���
	template <typename T>
	bool SimpleWindow<T>::RemoveChild(SimpleWindow<T>* child)
	{
		for (auto it = m_children.cbegin(); it != m_children.cend(); ++it)
		{
			if (*it == child)
			{
				m_children.erase(it);
				return true;
			}
		}

		return false;
	}

	// ��ȡ�ô��ڸ��������һ���Ӵ��ڣ�����ô���Ϊ��һ���Ӵ��ڣ��򷵻�nullptr
	// complexity: linear
	template <typename T>
	SimpleWindow<T>* SimpleWindow<T>::getPrevSibling() const
	{
		auto parentWnd = getParent();
		if (parentWnd == nullptr)
		{
			return nullptr;
		}
		auto myIt = std::find(parentWnd->m_children.cbegin(), parentWnd->m_children.cend(), this);
		// ������Ĭ�Ͽ����ҵ�
		if (myIt != parentWnd->m_children.cbegin())
		{
			return *(--myIt);
		}

		return nullptr;
	}

	// ��ȡ�ô��ڸ��������һ���Ӵ���,����ô���Ϊ���һ���Ӵ��ڣ��򷵻�nullptr
	//	complexity: linear
	template <typename T>
	SimpleWindow<T>* SimpleWindow<T>::getNextSibling() const
	{
		auto parentWnd = getParent();
		if (parentWnd == nullptr)
		{
			return nullptr;
		}
		auto myIt = std::find(parentWnd->m_children.cbegin(), parentWnd->m_children.cend(), this);
		// ������Ĭ�Ͽ����ҵ�
		if (myIt != (--parentWnd->m_children.cend()))
		{
			return *(++myIt);
		}

		return nullptr;
	}
}

#endif		// SIMPLE_WINDOW_INL