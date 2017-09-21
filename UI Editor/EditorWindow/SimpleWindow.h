#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

/*
 * �ļ�����EditorWindow
 * ���ã�����ʵ�ִ��ڵĻ�������
 */

#include <vector>
#include <iterator>
#include <wx/string.h>

namespace inner
{
	template <typename T>
	class SimpleWindow : public T
	{
	public:
		// ����һ�����ͱ�ʶ��
		using FuncType = T;
		using ConstChildIterator = typename std::vector<SimpleWindow<T>*>::const_iterator;
		using ChildIterator = typename std::vector<SimpleWindow*>::iterator;
	public:
		SimpleWindow(SimpleWindow<T>* parent, int relX, int relY, int width, int height);
		virtual ~SimpleWindow();

		// forbidden the copy constructor and copy assignment
		SimpleWindow(const SimpleWindow<T>& right) = delete;
		SimpleWindow<T>& operator=(const SimpleWindow<T>& right) = delete;

		// ��ȡ�����Ƿ�������Ӵ��ڶ���
		virtual bool isContainerWnd() const { return false; }

		// ���ڵĻ�������
		// ���ô��ڶ��������
		void setWindowObjectName(const wxString& objectName) { m_windowObjectName = objectName; }
		// ������ȡ���ڶ�������
		wxString getWindowObjectName() { return m_windowObjectName; }
		// ������ȡ����������
		virtual wxString getWindowClassName() { return "SimpleWindow"; }

		// �༭���ڷ�Χ
		// �����������X
		void updateRelX(int x) { m_relX = x; }
		// ��ȡ�������X
		int getRelX() const { return m_relX;  }
		// �����������Y
		void updateRelY(int y) { m_relY = y; }
		// ��ȡ�������Y
		int getRelY() const { return m_relY;  }
		// �����������X��Y
		void updateRelPos(int x, int y) { m_relX = x, m_relY = y; }
		// ���´��ڿ�ȴ�С
		void updateWidth(int width) { m_width = width; }
		// ��ȡ���ڿ�ȴ�С
		int getWidth() const { return m_width;  }
		// ���´��ڸ߶ȴ�С
		void updateHeight(int height) { m_height = height; }
		// ��ȡ�߶ȴ�С
		int getHeight() const { return m_height;  }
		// ���´��ڷ�Χ
		void updateRange(int x, int y, int width, int height) { m_relX = x; m_relY = y; m_width = width; m_height = height; }

		// ���ô����Ƿ�ΪEnable
		void setEnable(bool enable) { m_enable = enable; }
		// ���ô����Ƿ�ɼ�
		void setVisible(bool visible) { m_visible = visible; }
		// ���ô����Ƿ��ܹ��ɼ�
		void setVisibleEnable(bool visibleEnable) { m_visibleEnable = visibleEnable; }

		// �����ڽ����ϻ��Ƶĺ���
		virtual void draw() = 0;

	protected:
		// ��ȡ�ô��ڵĸ�����
		SimpleWindow<T>* getParent() const { return m_parent; }
		// ���øô��ڵĸ����ڶ���
		void setParent(SimpleWindow<T>* parent) { m_parent = parent; }
		// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
		virtual void pushChild(SimpleWindow<T>* child);

	protected:
		// ���ڵĸ�����
		SimpleWindow* m_parent;

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
	};

}

#include "SimpleWindow.inl"

#endif	// EDITOR_WINDOW_H
