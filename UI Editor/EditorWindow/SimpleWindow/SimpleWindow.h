#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

/*
 * �ļ�����EditorWindow
 * ���ã�����ʵ�ִ��ڵĻ�������
 * ˵����
 * 1.���ڵ���Ϣ��Ӧ��Χ�ɸô����Ƿ���Ա༭���������ܴ����Ƿ񼤻�Ӱ��
 * 2.��Ӧ��Ϣʱ���Ӹ����ڵ��Ӵ����жϣ���������ڲ�������Ϣ�����ߴ�����Ϣ��Χ���������������ж��Ӵ����Ƿ���
 * 3.������������أ����Ӵ���Ҳһ������
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

		// ��ȡ�����Ƿ�������Ӵ��ڶ���
		virtual bool isContainerWnd() const { return false; }
		// ��ȡ�ô��ڵĸ�����
		SIMPLE_WINDOW_TYPE* getParent() const { return m_parent; }
		// ��ʶ����û�и����ڣ����ж�
		bool hasParent() const { return m_parent != nullptr; }

		// �������һ���Ӵ���
		virtual void addChild(SIMPLE_WINDOW_TYPE* child);
		// ������before����֮ǰ���һ���Ӵ���
		virtual bool insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before);
		// ������iter֮ǰ����Ӵ���
		virtual bool insertChild(SIMPLE_WINDOW_TYPE* child, ConstChildIterator iter);
		// �����Ƴ�һ���Ӵ���
		virtual bool removeChild(SIMPLE_WINDOW_TYPE* child);
		// ��ȡ�Ӵ����б���cbegin��Ӧ��iterator
		virtual ConstChildIterator getChildrenConstBeg() const { return s_defChildrenRet.cbegin(); }
		// ��ȡ�Ӵ����б���cend��Ӧ��iterator
		virtual ConstChildIterator getChildrenConstEnd() const { return s_defChildrenRet.cend(); }
		// ��ȡ�Ӵ��ڸ���
		virtual ChildrenSize getChildrenSize() const { return 0; }


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

		// �����Ƿ񼤻�
		void setEnable(bool enable) { m_enable = enable; }
		// ��ȡ�Ƿ񼤻�
		bool getEnable() const { return m_enable; }

		// �ڽ����ϻ���
		virtual void draw(int x, int y) const = 0;

		// ��ȡ��Ϣ����ķ�Χ����Է�Χ
		virtual wxRegion getMsgRegion() const;
		// �ô����Ƿ�������Ϣ
		virtual bool isHandleMsg() const { return true; }

	protected:
		// ���øô��ڵĸ����ڶ��󣬸ú������ò���ı丸���ڵ���Ϣ��Ӧ��Χ
		void setParent(SIMPLE_WINDOW_TYPE* parent, SIMPLE_WINDOW_TYPE* child);
		// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
		virtual void pushChild(SIMPLE_WINDOW_TYPE* child);
		// ���¸ô����ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ô�����
		virtual void incrMsgRegion(const wxRegion& childRect) { if (hasParent()) { getParent()->incrMsgRegion(childRect); } }
		// ���ô�����Ϣ��ΧΪ�����Ӵ��ڷ�Χ�����������Ӵ��ڷ����仯������ı�
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

		// �Ƿ��ڼ���״̬
		bool m_enable;

		const static CHILDREN_CONTAINER s_defChildrenRet;

	private:
		// ���¸�������Ϣ����Χ
		void updateParentMsgRect();
	};

	// ����Editorģ����
	class EditorEditableFunc;
	template <>
	class SimpleWindow<EditorEditableFunc>;
}

#include "SimpleWindow.inl"

#endif	// EDITOR_WINDOW_H
