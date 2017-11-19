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

	// ��ȡ��Ϣ����ķ�Χ
	template<typename T>
	inline wxRegion ContainerWindow<T>::getMsgRegion() const
	{
		if (isHandleMsg())
		{
			return m_msgRegion;
		}
		else
		{
			return wxRegion();
		}
	}

	template <typename T>
	ContainerWindow<T>::~ContainerWindow()
	{
		for (auto value : m_children)
		{
			delete value;
		}
	}

	// �������һ���ӿؼ�
	template <typename T>
	void ContainerWindow<T>::addChild(SIMPLE_WINDOW_TYPE* child)
	{
		assert(child != nullptr);

		// �ȴӸÿؼ��ĸ��������Ƴ�����ӿؼ�
		if (child->hasParent())
		{
			// �����ӿؼ�����һ����ContainerWindow
			child->getParent()->removeChild(child);
		}
		m_children.push_back(child);
		setParent(this, child);

		incrMsgRegion(child->getMsgRegion());
	}

	// ������ĳ���ؼ�֮ǰ���һ���ӿؼ�
	template <typename T>
	bool ContainerWindow<T>::insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before)
	{
		assert(child != nullptr);

		// �ȴӸÿؼ��ĸ��������Ƴ�����ӿؼ�
		if (child->hasParent())
		{
			// �����ӿؼ�����һ����ContainerWindow
			child->getParent()->removeChild(child);
		}
		const auto it = std::find(m_children.cbegin(), m_children.cend(), before);
		if (it != m_children.cend())
		{
			return insertChild(child, it);
		}

		return false;
	}

	// ������iter֮ǰ����ӿؼ�
	template<typename T>
	inline bool ContainerWindow<T>::insertChild(SIMPLE_WINDOW_TYPE* child, ConstChildIterator iter)
	{
		m_children.insert(iter, child);
		setParent(this, child);

		incrMsgRegion(child->getMsgRegion());

		return true;
	}

	// �����Ƴ�һ���ӿؼ�
	template <typename T>
	bool ContainerWindow<T>::removeChild(SIMPLE_WINDOW_TYPE* child)
	{
		assert(child != nullptr);

		for (auto it = m_children.cbegin(); it != m_children.cend(); ++it)
		{
			if (*it == child)
			{
				m_children.erase(it);
				setParent(nullptr, child);
				if (child->isHandleMsg())
				{
					resetMsgRegion();
				}
				return true;
			}
		}

		return false;
	}

	// �������һ���ӿؼ����󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
	template<typename T>
	inline void ContainerWindow<T>::pushChild(SIMPLE_WINDOW_TYPE* child)
	{
		assert(child != nullptr);

		m_children.push_back(child);

		incrMsgRegion(child->getMsgRegion());
	}

	// ���¸ÿؼ��ж���Ϣ�ķ�Χ����childRange��ӵ��ÿؼ�����Ϣ����Χ�����øú������жϸÿؼ��Ƿ�����Ϣ��
	// ���ж��ӿؼ��Ƿ�����Ϣ
	template<typename T>
	inline void ContainerWindow<T>::incrMsgRegion(const wxRegion& childRegion)
	{
		// ��¼֮ǰ�ķ�Χ
		auto oldRange = m_msgRegion;
		// �����ӿؼ���Χ����ǰ����
		auto adjustRect = childRegion;
		adjustRect.Offset(narrow_cast<wxCoord>(m_relX), narrow_cast<wxCoord>(m_relY));

		m_msgRegion.Union(adjustRect);
		// �ÿؼ���Χ��Ϊ������childRegion�������˸ı�
		if (oldRange != m_msgRegion)
		{
			SimpleWindow<T>::incrMsgRegion(m_msgRegion);
		}
	}

	// ���ÿؼ���Ϣ��ΧΪ�����ӿؼ���Χ�������ӿؼ������仯�����øú������жϸÿؼ��Ƿ�����Ϣ
	// ���ж��ӿؼ��Ƿ�����Ϣ
	template<typename T>
	inline void ContainerWindow<T>::resetMsgRegion()
	{
		// ��¼֮ǰ�ķ�Χ
		auto oldRegion = m_msgRegion;
		// ���ӿؼ�����ϵΪ�ο�
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