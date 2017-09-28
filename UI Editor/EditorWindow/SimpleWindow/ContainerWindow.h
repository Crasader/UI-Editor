#ifndef CONTAINER_WINDOW_H
#define CONTAINER_WINDOW_H

#include "SimpleWindow.h"

namespace inner
{
	template <typename T>
	class ContainerWindow : public SimpleWindow<T>
	{
	public:
		using SIMPLE_WINDOW_TYPE = typename SimpleWindow<T>::SIMPLE_WINDOW_TYPE;
	public:
		ContainerWindow(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		~ContainerWindow() override;

		// ��ȡ��Ϣ����ķ�Χ
		wxRegion getMsgRegion() const override { return m_msgRegion; }

		// ��ȡ�����Ƿ�������Ӵ��ڶ���
		bool isContainerWnd() const override { return true; }
		// ��ȡ�Ӵ����б���cbegin��Ӧ��iterator
		virtual ConstChildIterator getChildrencConstBeg() const { return m_children.cbegin(); }
		// ��ȡ�Ӵ����б���cend��Ӧ��iterator
		virtual ConstChildIterator getChildrenConstEnd() const { return m_children.cend(); }
		// ��ȡ�Ӵ��ڸ���
		virtual ChildrenSize getChildrenSize() const { return m_children.size(); }
		// �������һ���Ӵ���
		void addChild(SIMPLE_WINDOW_TYPE* child) override;
		// ������before����֮ǰ���һ���Ӵ���
		bool insertChild(SIMPLE_WINDOW_TYPE* child, const SIMPLE_WINDOW_TYPE* before) override;
		// ������iter֮ǰ����Ӵ���
		bool insertChild(SIMPLE_WINDOW_TYPE* child, ConstChildIterator iter) override;
		// �����Ƴ�һ���Ӵ���
		bool removeChild(SIMPLE_WINDOW_TYPE* child) override;

	protected:
		// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
		void pushChild(SIMPLE_WINDOW_TYPE* child) override;
		// ���¸ô����ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ô�����
		void incrMsgRegion(const wxRegion& childRange) override;
		// ���ô�����Ϣ��ΧΪ�����Ӵ��ڷ�Χ�������Ӵ��ڷ����仯������ı�
		void resetMsgRegion() override;

		const CHILDREN_CONTAINER& getConstChildren() const override { return m_children; }
		// ��ȡ�Ӵ����б�
		CHILDREN_CONTAINER& getChildren() { return m_children; }
		const CHILDREN_CONTAINER& getChildren() const { return m_children; }

	protected:
		// ������¼���е��Ӵ���
		CHILDREN_CONTAINER m_children;
		// ����������Ϣ����Χ
		wxRegion m_msgRegion;
	};

	// ����Editorģ����
	class EditorContainerFunc;
	template <>
	class ContainerWindow<EditorContainerFunc>;
}

#include "ContainerWindow.inl"

#endif	// CONTAINER_WINDOW_H
