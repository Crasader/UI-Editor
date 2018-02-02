#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

/*
 * �ļ�����EditorWindow
 * ���ã�����ʵ�ֿؼ��Ļ�������
 * ˵����
 * 1.�ؼ�����Ϣ��Ӧ��Χ�ɸÿؼ��Ƿ���Ա༭���������ܿؼ��Ƿ񼤻�Ӱ��
 * 2.��Ӧ��Ϣʱ���Ӹ��ؼ����ӿؼ��жϣ�������ؼ���������Ϣ�����ߴ�����Ϣ��Χ���������������ж��ӿؼ��Ƿ���
 * 3.������ؼ����أ����ӿؼ�Ҳһ������
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
		using ChildrenSize = typename CHILDREN_CONTAINER::size_type;
	public:
		SimpleWindow(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		virtual ~SimpleWindow();

		// forbidden the copy constructor and copy assignment
		SimpleWindow(const SimpleWindow<T>& right) = delete;
		SimpleWindow<T>& operator=(const SimpleWindow<T>& right) = delete;

		// ��ȡ�ؼ��Ƿ�������ӿؼ�����
		virtual bool isContainerWnd() const { return false; }
		// ��ȡ�ÿؼ��ĸ��ؼ�
		SIMPLE_WINDOW_TYPE* getParent() const { return m_parent; }
		// ��ʶ�ؼ�û�и��ؼ������ж�
		bool hasParent() const { return m_parent != nullptr; }

		// �������һ���ӿؼ�
		virtual void addChild(SIMPLE_WINDOW_TYPE* child);
		// ������before�ؼ�֮ǰ���һ���ӿؼ�
		virtual bool insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before);
		// ������iter֮ǰ����ӿؼ�
		virtual bool insertChild(SIMPLE_WINDOW_TYPE* child, ConstChildIterator iter);
		// �����Ƴ�һ���ӿؼ�
		virtual bool removeChild(SIMPLE_WINDOW_TYPE* child);
		// ��ȡ�ӿؼ��б���cbegin��Ӧ��iterator
		virtual ConstChildIterator getChildrenConstBeg() const { return s_defChildrenRet.cbegin(); }
		// ��ȡ�ӿؼ��б���cend��Ӧ��iterator
		virtual ConstChildIterator getChildrenConstEnd() const { return s_defChildrenRet.cend(); }
		// ��ȡ�ӿؼ�����
		virtual ChildrenSize getChildrenSize() const { return 0; }


		// ��ȡ�ÿؼ����������һ���ӿؼ�������ÿؼ�Ϊ��һ���ӿؼ����򷵻�nullptr
		// complexity: linear
		SIMPLE_WINDOW_TYPE* getPrevSibling() const;
		// ��ȡ�ÿؼ����������һ���ӿؼ�,����ÿؼ�Ϊ���һ���ӿؼ����򷵻�nullptr
		//	complexity: linear
		SIMPLE_WINDOW_TYPE* getNextSibling() const;

		// �ؼ��Ļ�������

		// �༭�ؼ���Χ
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
		// ���¿ؼ���ȴ�С
		void updateWidth(int width);
		// ��ȡ�ؼ���ȴ�С
		int getWidth() const { return m_width;  }
		// ���¿ؼ��߶ȴ�С
		void updateHeight(int height);
		// ��ȡ�߶ȴ�С
		int getHeight() const { return m_height;  }
		// ���¿ؼ���С
		void updateSize(int width, int height);
		// ���¿ؼ���Χ
		void updateRange(int x, int y, int width, int height);

		// �����Ƿ񼤻�
		void setEnable(bool enable) { m_enable = enable; }
		// ��ȡ�Ƿ񼤻�
		bool getEnable() const { return m_enable; }

		// �ڽ����ϻ���
		virtual void draw(int x, int y) const = 0;

		// ��ȡ��Ϣ����ķ�Χ����Է�Χ��������Լ�
		virtual wxRegion getMsgRegion() const;
		// �ÿؼ��Ƿ���ؼ���Ϣ
		virtual bool isHandleMsg() const { return true; }

	protected:
		// ���øÿؼ��ĸ��ؼ����󣬸ú������ò���ı丸�ؼ�����Ϣ��Ӧ��Χ
		void setParent(SIMPLE_WINDOW_TYPE* parent, SIMPLE_WINDOW_TYPE* child);
		// �������һ���ӿؼ����󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
		virtual void pushChild(SIMPLE_WINDOW_TYPE* child);
		// ���¸ÿؼ��ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ÿؼ���
		virtual void incrMsgRegion(const wxRegion& childRect) { if (hasParent()) { getParent()->incrMsgRegion(childRect); } }
		// ���ÿؼ���Ϣ��ΧΪ�����ӿؼ���Χ�����������ӿؼ������仯������ı�
		virtual void resetMsgRegion() { if (hasParent()) { getParent()->resetMsgRegion(); } }

		// ��ȡ�ӿؼ��б�
		virtual const CHILDREN_CONTAINER& getConstChildren() const;
		// ��ȡ�ӿؼ��б���begin��Ӧ��iterator
		virtual ChildIterator getChildrenBeg() { return s_defChildrenRetV.begin(); }
		// ��ȡ�ӿؼ��б���end��Ӧ��iterator
		virtual ChildIterator getChildrenEnd() { return s_defChildrenRetV.end(); }

	protected:
		// �ؼ��ĸ�����
		SIMPLE_WINDOW_TYPE* m_parent;

		// �ؼ�����
		// �ؼ���Χ
		int m_relX;
		int m_relY;
		int m_width;
		int m_height;

		// �Ƿ��ڼ���״̬
		bool m_enable;

		const static CHILDREN_CONTAINER s_defChildrenRet;
		static CHILDREN_CONTAINER s_defChildrenRetV;

	private:
		// ���¸��ؼ���Ϣ����Χ
		void updateParentMsgRect();
	};

	// ����Editorģ����
	class EditorEditableFunc;
	template <>
	class SimpleWindow<EditorEditableFunc>;
}

#include "SimpleWindow.inl"

#endif	// EDITOR_WINDOW_H
