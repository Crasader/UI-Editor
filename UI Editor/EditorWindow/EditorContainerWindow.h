#ifndef EDITOR_CONTAINER_WINDOW_H
#define EDITOR_CONTAINER_WINDOW_H

/*
 * �ļ�����EditorContainerWindow
 * ����: ��Ϊ�ؼ��������������ؼ��ĸ��Ӳ㼶��ϵ
 */

#include "EditorFunc.h"
#include "EditorAbstractWindow.h"
#include "SimpleWindow/ContainerWindow.h"

namespace inner
{
	template <>
	class ContainerWindow<EditorContainerFunc> : public ContainerWindow<EditorEditableFunc>
	{
	public:
		using ContainerWindow<EditorEditableFunc>::ContainerWindow;
		~ContainerWindow<EditorContainerFunc>() override {}

		// �����鿴��ӦID�Ŀؼ�
		SimpleWindow<EditorFunc>* findMatchWnd(ID_TYPE findId) override;

	protected:
		// ���øÿؼ��Ƿ�༭ʱ��ʾ
		void setEditShow(bool editShow) override;
	};
}


#endif	// EDITOR_CONTAINER_WINDOW_H
