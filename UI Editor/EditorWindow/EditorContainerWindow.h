#ifndef EDITOR_CONTAINER_WINDOW_H
#define EDITOR_CONTAINER_WINDOW_H

#include "EditorFunc.h"
#include "AbstractEditorWindow.h"
#include "SimpleWindow/ContainerWindow.h"

namespace inner
{
	template <>
	class ContainerWindow<EditorContainerFunc> : public ContainerWindow<EditorEditableFunc>
	{
	public:
		using ContainerWindow<EditorEditableFunc>::ContainerWindow;
		~ContainerWindow<EditorContainerFunc>() override {}

		// �����鿴��ӦID�Ĵ���
		SimpleWindow<EditorFunc>* findMatchWnd(ID_TYPE findId) override;
	};
}


#endif	// EDITOR_CONTAINER_WINDOW_H
