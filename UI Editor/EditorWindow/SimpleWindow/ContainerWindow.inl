#ifndef CONTAINER_WINDOW_INL
#define CONTAINER_WINDOW_INL

#include <cassert>
#include "ContainerWindow.h"
#include "../Util/ArithmeticUtil.h"

namespace inner
{
	template<typename T>
	ContainerWindow<T>::ContainerWindow(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height)
		: SimpleWindow<T>(parent, relX, relY, width, height)
	{
	}

	template <typename T>
	ContainerWindow<T>::~ContainerWindow()
	{
		for (auto value : m_children)
		{
			delete value;
		}
	}

	// �������һ���Ӵ���
	template <typename T>
	void ContainerWindow<T>::addChild(SIMPLE_WINDOW_TYPE* child)
	{
		assert(child != nullptr);

		// �ȴӸô��ڵĸ��������Ƴ�����Ӵ���
		if (child->hasParent())
		{
			// �����Ӵ��ڣ���һ����ContainerWindow
			child->getParent()->removeChild(child);
		}
		m_children.push_back(child);
		child->setParent(this);
		incrMsgRegion(child->getMsgRegion());
	}

	// ������ĳ������֮ǰ���һ���Ӵ���
	template <typename T>
	bool ContainerWindow<T>::insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before)
	{
		assert(child != nullptr);

		// �ȴӸô��ڵĸ��������Ƴ�����Ӵ���
		if (child->hasParent())
		{
			// �����Ӵ��ڣ���һ����ContainerWindow
			child->getParent()->removeChild(child);
		}
		const auto it = std::find(m_children.cbegin(), m_children.cend(), before);
		if (it != m_children.cend())
		{
			m_children.insert(it, child);
			child->setParent(this);
			incrMsgRegion(child->getMsgRegion());
			return true;
		}

		return false;
	}

	// �����Ƴ�һ���Ӵ���
	template <typename T>
	bool ContainerWindow<T>::removeChild(SIMPLE_WINDOW_TYPE* child)
	{
		assert(child != nullptr);

		for (auto it = m_children.cbegin(); it != m_children.cend(); ++it)
		{
			if (*it == child)
			{
				m_children.erase(it);
				child->setParent(nullptr);
				resetMsgRegion();
				return true;
			}
		}

		return false;
	}

	// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
	template<typename T>
	inline void ContainerWindow<T>::pushChild(SIMPLE_WINDOW_TYPE* child)
	{
		assert(child != nullptr);

		m_children.push_back(child);
		incrMsgRegion(child->getMsgRegion());
	}

	// ���¸������ж���Ϣ�ķ�Χ
	template<typename T>
	inline void ContainerWindow<T>::incrMsgRegion(const wxRegion& childRegion)
	{
		// ��¼֮ǰ�ķ�Χ
		auto oldRange = m_msgRegion;
		// �����Ӵ��ڷ�Χ����ǰ����
		auto adjustRect = childRegion;
		adjustRect.Offset(narrow_cast<wxCoord>(m_relX), narrow_cast<wxCoord>(m_relY));

		// �Ӵ��ڷ�Χ���ڸ�����֮��
		m_msgRegion.Union(adjustRect);
		if (oldRange != m_msgRegion)
		{
			SimpleWindow<T>::incrMsgRegion(m_msgRegion);
		}
	}

	// ���ô�����Ϣ��ΧΪ�����Ӵ��ڷ�Χ
	template<typename T>
	inline void ContainerWindow<T>::resetMsgRegion()
	{
		// ��¼֮ǰ�ķ�Χ
		auto oldRegion = m_msgRegion;
		// ���Ӵ�������ϵΪ�ο�
		wxRegion region;
		for (auto chp : m_children)
		{
			region.Union(chp->getMsgRegion());
		}
		region.Union(wxRect(0, 0, narrow_cast<wxCoord>(m_width), narrow_cast<wxCoord>(m_height)));
		m_msgRegion = std::move(region);
		// ƫ�Ƶ���ǰ����ϵ
		m_msgRegion.Offset(narrow_cast<wxCoord>(m_relX), narrow_cast<wxCoord>(m_relY));
		// ������߷�Χ��ͬ�������ϴ���
		if (oldRegion != m_msgRegion)
		{
			SimpleWindow<T>::resetMsgRegion();
		}
	}
}

#endif	// CONTAINER_WINDOW_INL