#ifndef SIMPLE_WINDOW_INL
#define SIMPLE_WINDOW_INL

#include "SimpleWindow.h"

namespace inner
{
	template <typename T>
	SimpleWindow<T>::SimpleWindow(SimpleWindow<T>* parent, int relX, int relY, int width, int height)
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
			throw std::runtime_error("parnet is not a Container window");
		}
		parent->pushChild(this);
	}

	template <typename T>
	SimpleWindow<T>::~SimpleWindow()
	{

	}

	// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
	template<typename T>
	inline void SimpleWindow<T>::pushChild(SimpleWindow<T>* child)
	{
	}
}

#endif		// SIMPLE_WINDOW_INL