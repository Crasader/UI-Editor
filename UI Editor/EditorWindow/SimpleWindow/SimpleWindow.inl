#ifndef SIMPLE_WINDOW_INL
#define SIMPLE_WINDOW_INL

#include "SimpleWindow.h"

namespace inner
{
	template <typename T>
	SimpleWindow<T>::SimpleWindow(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height)
		: T(),
		m_parent(parent), m_relX(relX), m_relY(relY), m_width(width), m_height(height),
		m_enable(true)
	{
		if (parent == nullptr)
		{
			return;
		}
		// �����Ϊ������Ŀؼ����ܴ洢�ӿؼ�
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

	// �������һ���ӿؼ�
	template<typename T>
	inline void SimpleWindow<T>::addChild(SIMPLE_WINDOW_TYPE* child)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__); 
	}

	// ������before�ؼ�֮ǰ���һ���ӿؼ�
	template <typename T>
	bool SimpleWindow<T>::insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__);
		return false;
	}

	// ������iter֮ǰ����ӿؼ�
	template<typename T>
	inline bool SimpleWindow<T>::insertChild(SIMPLE_WINDOW_TYPE * child, ConstChildIterator iter)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__);
		return false;
	}

	// �����Ƴ�һ���ӿؼ�
	template <typename T>
	bool SimpleWindow<T>::removeChild(SIMPLE_WINDOW_TYPE* child)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__);
		return false;
	}

	// ��ȡ�ÿؼ����������һ���ӿؼ�������ÿؼ�Ϊ��һ���ӿؼ����򷵻�nullptr
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

	// ��ȡ�ÿؼ����������һ���ӿؼ�,����ÿؼ�Ϊ���һ���ӿؼ����򷵻�nullptr
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

	// �������һ���ӿؼ����󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
	template<typename T>
	inline void SimpleWindow<T>::pushChild(SIMPLE_WINDOW_TYPE* child)
	{
		throw std::runtime_error(std::string("SimpleWindow can't invoke ") + __func__); 
	}

	// ��ȡ�ӿؼ��б�
	template <typename T>
	const typename SimpleWindow<T>::CHILDREN_CONTAINER& SimpleWindow<T>::getConstChildren() const
	{
		return s_defChildrenRet;
	}

	// ��Ҫ�ӿؼ��б���ص�Ĭ�Ϸ���ֵ
	template<typename T>
	const typename SimpleWindow<T>::CHILDREN_CONTAINER SimpleWindow<T>::s_defChildrenRet;

	// ��Ҫ�ӿؼ��б���ص�Ĭ�Ϸ���ֵ
	template<typename T>
	typename SimpleWindow<T>::CHILDREN_CONTAINER SimpleWindow<T>::s_defChildrenRetV;


	// ���øÿؼ��ĸ��ؼ�����
	template <typename T>
	inline void SimpleWindow<T>::setParent(SIMPLE_WINDOW_TYPE* parent, SIMPLE_WINDOW_TYPE* child)
	{
		if (parent && !parent->isContainerWnd())
		{
			throw std::runtime_error("parent is not a Container window");
		}
		child->m_parent = parent;
	}


	// �����������X
	template <typename T>
	inline void SimpleWindow<T>::updateRelX(int x)
	{
		// ���ж��Ƿ����ı�
		if (m_relX == x)
		{
			return;
		}

		m_relX = x;
		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// �����������Y
	template <typename T>
	inline void SimpleWindow<T>::updateRelY(int y)
	{
		// ���ж��Ƿ����ı�
		if (m_relY == y)
		{
			return;
		}

		m_relY = y;

		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// �����������X��Y
	template <typename T>
	inline void SimpleWindow<T>::updateRelPos(int x, int y)
	{
		// ���ж��Ƿ����ı�
		if (make_tuple(m_relX, m_relY) == make_tuple(x, y))
		{
			return;
		}

		m_relX = x;
		m_relY = y;
		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// ��ȡ��������X
	template <typename T>
	inline int SimpleWindow<T>::getAbsX() const
	{
		if (hasParent())
		{
			return getParent()->getAbsX() + getRelX();
		}
		return getRelX();
	}

	// ��ȡ��������Y
	template <typename T>
	inline int SimpleWindow<T>::getAbsY() const
	{
		if (hasParent())
		{
			return getParent()->getAbsY() + getRelY();
		}
		return getRelY();
	}

	// ���¿ؼ���ȴ�С
	template <typename T>
	inline void SimpleWindow<T>::updateWidth(int width)
	{
		// ���ж��Ƿ����ı�
		if (m_width == width)
		{
			return;
		}

		m_width = width;

		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// ���¿ؼ��߶ȴ�С
	template <typename T>
	inline void SimpleWindow<T>::updateHeight(int height)
	{
		// ���ж��Ƿ����ı�
		if (m_height == height)
		{
			return;
		}

		m_height = height;

		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// ���¿ؼ���С
	template <typename T>
	inline void SimpleWindow<T>::updateSize(int width, int height)
	{
		// ���ж��Ƿ����ı�
		if (make_tuple(m_width, m_height) == make_tuple(width, height))
		{
			return;
		}

		m_width = width;
		m_height = height;

		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// ���¿ؼ���Χ
	template <typename T>
	inline void SimpleWindow<T>::updateRange(int x, int y, int width, int height)
	{
		// ���ж��Ƿ����ı�
		if (make_tuple(m_relX, m_relY, m_width, m_height)
			== make_tuple(x, y, width, height))
		{
			return;
		}

		m_relX = x;
		m_relY = y;
		m_width = width;
		m_height = height;

		if (isHandleMsg())
		{
			// ���麯��
			updateParentMsgRect();
		}
	}

	// ��ȡ��Ϣ����ķ�Χ����Է�Χ��������Լ�
	template <typename T>
	inline wxRegion SimpleWindow<T>::getMsgRegion() const
	{
		if (isHandleMsg())
		{
			return wxRegion(0, 0, narrow_cast<wxCoord>(m_width), narrow_cast<wxCoord>(m_height));
		}
		else
		{
			return wxRegion();
		}
	}

	// ���¸��ؼ���Ϣ����Χ
	template <typename T>
	inline void SimpleWindow<T>::updateParentMsgRect()
	{
		if (hasParent())
		{
			getParent()->resetMsgRegion();
		}
	}
}

#endif		// SIMPLE_WINDOW_INL