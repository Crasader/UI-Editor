#include "EditorContainerWindow.h"

namespace inner
{
	// �����鿴��ӦID�Ĵ���
	SimpleWindow<EditorFunc>* ContainerWindow<EditorContainerFunc>::findMatchWnd(ID_TYPE findId)
	{
		// �鿴�ô���ID�Ƿ�����
		if (getId() == findId)
		{
			return this;
		}
		// �鿴�Ӵ����Ƿ���������
		for (const auto& value : getConstChildren())
		{
			const auto wnd = value->findMatchWnd(findId);
			if (wnd != nullptr)
			{
				return wnd;
			}
		}

		return nullptr;
	}
}