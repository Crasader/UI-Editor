#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

/*
 * �ļ�����EditorWindow
 * ���ã�����ʵ�ִ��ڵĻ�������
 */

#include <vector>
#include <wx/string.h>

namespace inner
{
	template <typename T>
	class SimpleWindow : public T
	{
	public:
		// ����һ�����ͱ�ʶ��
		using FuncType = T;
		//using ConstChildIterator = std::list<SimpleWindow*>::const_iter;
		//using ChildIterator = std::list<SimpleWindow*>::iterator;
	public:
		SimpleWindow(SimpleWindow<T>* parent, int relX, int relY, int width, int height);
		virtual ~SimpleWindow();

		//���ڱ�����غ���
		// ��ȡ�ô��ڵĸ�����
		SimpleWindow<T>* getParent() const { return m_parent; }
		// �������һ���Ӵ���
		void AddChild(SimpleWindow<T>* child);
		// ������before����֮ǰ���һ���Ӵ���
		bool InsertChild(SimpleWindow<T>* child, const SimpleWindow<T>* before);
		// �����Ƴ�һ���Ӵ���
		bool RemoveChild(SimpleWindow<T>* child);
		// ��ȡ�ô��ڸ��������һ���Ӵ��ڣ�����ô���Ϊ��һ���Ӵ��ڣ��򷵻�nullptr
		// complexity: linear
		SimpleWindow<T>* getPrevSibling() const;
		// ��ȡ�ô��ڸ��������һ���Ӵ���,����ô���Ϊ���һ���Ӵ��ڣ��򷵻�nullptr
		//	complexity: linear
		SimpleWindow<T>* getNextSibling() const;

		// ���ڵĻ�������
		// ���ô��ڶ��������
		void setWindowObjectName(const wxString& objectName) { m_windowObjectName = objectName; }
		// ������ȡ���ڶ�������
		wxString getWindowObjectName() { return m_windowObjectName; }
		// ������ȡ����������
		virtual wxString getWindowClassName() { return "EditorWindow"; }

		// �༭���ڷ�Χ
		// �����������X
		void updateRelX(int x) { m_relX = x; }
		// �����������Y
		void updateRelY(int y) { m_relY = y; }
		// �����������X��Y
		void updateRelPos(int x, int y) { m_relX = x, m_relY = y; }
		// ���´��ڿ�ȴ�С
		void updateWidth(int width) { m_width = width; }
		// ���´��ڸ߶ȴ�С
		void updateHeight(int height) { m_height = height; }
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
		// ���ڵĸ��Ӽ�
		SimpleWindow* m_parent;
		std::vector<SimpleWindow*> m_children;

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
