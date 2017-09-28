#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

/*
 * �ļ�����EditorWindow
 * ���ã�����ʵ�ִ��ڵĻ�������
 */

#include <vector>
#include <iterator>
#include <wx/string.h>
#include <wx/region.h>
#include <stdexcept>
#include "../../Util/ArithmeticUtil.h"

namespace inner
{
	template <typename T>
	class SimpleWindow : public T
	{
	public:
		// ����һ�����ͱ�ʶ��
		using FuncType = typename T::FuncBaseType;
		using SIMPLE_WINDOW_TYPE = SimpleWindow<FuncType>;
		using CHILDREN_CONTAINER = std::vector<SIMPLE_WINDOW_TYPE*>;
		using ConstChildIterator = typename CHILDREN_CONTAINER::const_iterator;
		using ChildIterator = typename CHILDREN_CONTAINER::iterator;
	public:
		SimpleWindow(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		virtual ~SimpleWindow();

		// forbidden the copy constructor and copy assignment
		SimpleWindow(const SimpleWindow<T>& right) = delete;
		SimpleWindow<T>& operator=(const SimpleWindow<T>& right) = delete;

		// ��ȡ�����Ƿ�������Ӵ��ڶ���
		virtual bool isContainerWnd() const { return false; }
		// ��ȡ�ô��ڵĸ�����
		SIMPLE_WINDOW_TYPE* getParent() const { return m_parent; }
		// ��ʶ����û�и����ڣ����ж�
		bool hasParent() const { return m_parent != nullptr; }
		// ���øô��ڵĸ����ڶ���
		void setParent(SIMPLE_WINDOW_TYPE* parent);

		// �������һ���Ӵ���
		virtual void addChild(SIMPLE_WINDOW_TYPE* child);
		// ������before����֮ǰ���һ���Ӵ���
		virtual bool insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before);
		// �����Ƴ�һ���Ӵ���
		virtual bool removeChild(SIMPLE_WINDOW_TYPE* child);
		// ��ȡ�Ӵ����б���cbegin��Ӧ��iterator
		virtual ConstChildIterator getChildrencConstBeg() const { return s_defChildrenRet.cbegin(); }
		// ��ȡ�Ӵ����б���cend��Ӧ��iterator
		virtual ConstChildIterator getChildrenConstEnd() const { return s_defChildrenRet.cend(); }


		// ��ȡ�ô��ڸ��������һ���Ӵ��ڣ�����ô���Ϊ��һ���Ӵ��ڣ��򷵻�nullptr
		// complexity: linear
		SIMPLE_WINDOW_TYPE* getPrevSibling() const;
		// ��ȡ�ô��ڸ��������һ���Ӵ���,����ô���Ϊ���һ���Ӵ��ڣ��򷵻�nullptr
		//	complexity: linear
		SIMPLE_WINDOW_TYPE* getNextSibling() const;

		// ���ڵĻ�������
		// ���ô��ڶ��������
		void setWindowObjectName(const wxString& objectName) { m_windowObjectName = objectName; }
		// ������ȡ���ڶ�������
		wxString getWindowObjectName() { return m_windowObjectName; }
		// ������ȡ����������
		virtual wxString getWindowClassName() const { return wxS("SimpleWindow"); }

		// �༭���ڷ�Χ
		// �����������X
		void updateRelX(int x);
		// ��ȡ�������X
		int getRelX() const { return m_relX;  }
		// ��ȡ��������X
		int getAbsX() const;
		// �����������Y
		void updateRelY(int y);
		// ��ȡ�������Y
		int getRelY() const { return m_relY;  }
		// ��ȡ��������Y
		int getAbsY() const;
		// �����������X��Y
		void updateRelPos(int x, int y);
		// ���´��ڿ�ȴ�С
		void updateWidth(int width);
		// ��ȡ���ڿ�ȴ�С
		int getWidth() const { return m_width;  }
		// ���´��ڸ߶ȴ�С
		void updateHeight(int height);
		// ��ȡ�߶ȴ�С
		int getHeight() const { return m_height;  }
		// ���´��ڴ�С
		void updateSize(int width, int height);
		// ���´��ڷ�Χ
		void updateRange(int x, int y, int width, int height);

		// ���ô����Ƿ�ΪEnable
		void setEnable(bool enable) { m_enable = enable; }
		// ���ô����Ƿ�ɼ�
		void setVisible(bool visible) { m_visible = visible; }
		// ���ô����Ƿ��ܹ��ɼ�
		void setVisibleEnable(bool visibleEnable) { m_visibleEnable = visibleEnable; }

		// �ڽ����ϻ���
		virtual void draw() = 0;

		// ��ȡ��Ϣ����ķ�Χ����Է�Χ
		virtual wxRegion getMsgRegion() const;


	protected:
		// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
		virtual void pushChild(SIMPLE_WINDOW_TYPE* child);
		// ���¸ô����ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ô�����
		virtual void incrMsgRegion(const wxRegion& childRect) { if (hasParent()) { getParent()->incrMsgRegion(childRect); } }
		// ���ô�����Ϣ��ΧΪ�����Ӵ��ڷ�Χ�������Ӵ��ڷ����仯������ı�
		virtual void resetMsgRegion() { if (hasParent()) { getParent()->resetMsgRegion(); } }

		// ��ȡ�Ӵ����б�
		virtual const CHILDREN_CONTAINER& getConstChildren() const;

	protected:
		// ���ڵĸ�����
		SIMPLE_WINDOW_TYPE* m_parent;

		// ���ڶ�������
		wxString m_windowObjectName;

		// ��������
		// ���ڷ�Χ
		int m_relX;
		int m_relY;
		int m_width;
		int m_height;

		// �����Ƿ�Enable
		bool m_enable;
		// ���ô����Ƿ�ɼ�
		bool m_visible;
		// ���ô����Ƿ��ܹ��ɼ�
		bool m_visibleEnable;

		const static CHILDREN_CONTAINER s_defChildrenRet;

	private:
		// ���¸�������Ϣ����Χ
		void updateParentMsgRect();
	};

	// ���øô��ڵĸ����ڶ���
	template <typename T>
	inline void SimpleWindow<T>::setParent(SIMPLE_WINDOW_TYPE* parent)
	{
		if (!parent->isContainerWnd())
		{
			throw std::runtime_error("parent is not a Container window");
		}
		m_parent = parent;
	}


	// �����������X
	template <typename T>
	inline void SimpleWindow<T>::updateRelX(int x)
	{
		m_relX = x;
		updateParentMsgRect();
	}

	// �����������Y
	template <typename T>
	inline void SimpleWindow<T>::updateRelY(int y)
	{
		m_relY = y;
		updateParentMsgRect();
	}

	// �����������X��Y
	template <typename T>
	inline void SimpleWindow<T>::updateRelPos(int x, int y)
	{
		m_relX = x;
		m_relY = y;
		updateParentMsgRect();
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

	// ���´��ڿ�ȴ�С
	template <typename T>
	inline void SimpleWindow<T>::updateWidth(int width)
	{
		m_width = width;
		updateParentMsgRect();
	}

	// ���´��ڸ߶ȴ�С
	template <typename T>
	inline void SimpleWindow<T>::updateHeight(int height)
	{
		m_height = height;
		updateParentMsgRect();
	}

	// ���´��ڴ�С
	template <typename T>
	inline void SimpleWindow<T>::updateSize(int width, int height)
	{
		m_width = width;
		m_height = height;
		updateParentMsgRect();
	}

	// ���´��ڷ�Χ
	template <typename T>
	inline void SimpleWindow<T>::updateRange(int x, int y, int width, int height)
	{
		m_relX = x;
		m_relY = y;
		m_width = width;
		m_height = height;
		updateParentMsgRect();
	}

	// ��ȡ��Ϣ����ķ�Χ����Է�Χ
	template <typename T>
	inline wxRegion SimpleWindow<T>::getMsgRegion() const 
	{
		return wxRegion(
			narrow_cast<wxCoord>(m_relX), narrow_cast<wxCoord>(m_relY),
			narrow_cast<wxCoord>(m_width), narrow_cast<wxCoord>(m_height));
	}

	// ���¸�������Ϣ����Χ
	template <typename T>
	inline void SimpleWindow<T>::updateParentMsgRect()
	{
		if (hasParent())
		{
			getParent()->incrMsgRegion(getMsgRegion());
		}
	}


	// ����Editorģ����
	class EditorEditableFunc;
	template <>
	class SimpleWindow<EditorEditableFunc>;
}

#include "SimpleWindow.inl"

#endif	// EDITOR_WINDOW_H
