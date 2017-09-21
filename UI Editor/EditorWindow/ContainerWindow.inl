#ifndef CONTAINER_WINDOW_INL
#define CONTAINER_WINDOW_INL

#include "ContainerWindow.h"

namespace inner
{
	template<typename T>
	ContainerWindow<T>::ContainerWindow(SimpleWindow<T>* parent, int relX, int relY, int width, int height)
		: SimpleWindow<T>(parent, relX, relY, width, height)
	{
	}

	template <typename T>
	ContainerWindow<T>::~ContainerWindow()
	{

	}

	// �������һ���Ӵ���
	template <typename T>
	void ContainerWindow<T>::addChild(SimpleWindow<T>* child)
	{
		std::assert(child != nullptr);
		// �ȴӸô��ڵĸ��������Ƴ�����Ӵ���
		if (child->getParent() != nullptr)
		{
			child->getParent()->removeChild(child);
		}
		m_children.push_back(child);
		child->setParent(this);
	}

	// ������ĳ������֮ǰ���һ���Ӵ���
	template <typename T>
	bool ContainerWindow<T>::insertChild(SimpleWindow<T>* child, const SimpleWindow<T>* before)
	{
		std::assert(child != nullptr);
		// �ȴӸô��ڵĸ��������Ƴ�����Ӵ���
		if (child->getParent() != nullptr)
		{
			child->getParent()->removeChild(child);
		}
		const auto it = std::find(m_children.cbegin(), m_children.cend(), before);
		if (it != m_children.cend())
		{
			m_children.insert(it, child);
			child->setParent(this);
			return true;
		}

		return false;
	}

	// �����Ƴ�һ���Ӵ���
	template <typename T>
	bool ContainerWindow<T>::removeChild(SimpleWindow<T>* child)
	{
		for (auto it = m_children.cbegin(); it != m_children.cend(); ++it)
		{
			if (*it == child)
			{
				m_children.erase(it);
				child->setParent(nullptr);
				return true;
			}
		}

		return false;
	}

	// ��ȡ�ô��ڸ��������һ���Ӵ��ڣ�����ô���Ϊ��һ���Ӵ��ڣ��򷵻�nullptr
	// complexity: linear
	template <typename T>
	SimpleWindow<T>* ContainerWindow<T>::getPrevSibling() const
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
	SimpleWindow<T>* ContainerWindow<T>::getNextSibling() const
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

	// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
	template<typename T>
	void ContainerWindow<T>::pushChild(SimpleWindow<T>* child)
	{
		m_children.push_back(child);
	}
}

#endif	// CONTAINER_WINDOW_INL