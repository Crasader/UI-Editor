#ifndef CONTAINER_WINDOW_H
#define CONTAINER_WINDOW_H

#include "SimpleWindow.h"

namespace inner
{
	template <typename T>
	class ContainerWindow : public SimpleWindow<T>
	{
	public:
		ContainerWindow(SimpleWindow<T>* parent, int relX, int relY, int width, int height);
		~ContainerWindow() override;

		// ��ȡ��Ϣ����ķ�Χ
		wxRegion getMsgRegion() const override { return m_msgRegion; }

		// ��ȡ�����Ƿ�������Ӵ��ڶ���
		bool isContainerWnd() const override { return true; }
		//���ڱ�����غ���
		// �������һ���Ӵ���
		void addChild(SimpleWindow<T>* child);
		// ������before����֮ǰ���һ���Ӵ���
		bool insertChild(SimpleWindow<T>* child, const SimpleWindow<T>* before);
		// �����Ƴ�һ���Ӵ���
		bool removeChild(SimpleWindow<T>* child);
		// ��ȡ�ô��ڸ��������һ���Ӵ��ڣ�����ô���Ϊ��һ���Ӵ��ڣ��򷵻�nullptr
		// complexity: linear
		SimpleWindow<T>* getPrevSibling() const;
		// ��ȡ�ô��ڸ��������һ���Ӵ���,����ô���Ϊ���һ���Ӵ��ڣ��򷵻�nullptr
		//	complexity: linear
		SimpleWindow<T>* getNextSibling() const;

	protected:
		// �������һ���Ӵ��ڶ��󣬸ú������������Ķ����Ƿ��Ѿ����˸�����
		void pushChild(SimpleWindow<T>* child) override;
		// ���¸ô����ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ô�����
		void incrMsgRegion(const wxRegion& childRange) override;
		// ���ô�����Ϣ��ΧΪ�����Ӵ��ڷ�Χ�������Ӵ��ڷ����仯������ı�
		void resetMsgRegion() override;

	protected:
		// ������¼���е��Ӵ���
		std::vector<SimpleWindow*> m_children;
		// ����������Ϣ����Χ
		wxRegion m_msgRegion;
	};
}

#include "ContainerWindow.inl"

#endif	// CONTAINER_WINDOW_H
