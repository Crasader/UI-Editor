#include "EditorContainerWindow.h"

namespace inner
{
	// �����鿴��ӦID�Ŀؼ�
	SimpleWindow<EditorFunc>* ContainerWindow<EditorContainerFunc>::findMatchWnd(ID_TYPE findId)
	{
		// �鿴�ÿؼ�ID�Ƿ�����
		if (getId() == findId)
		{
			return this;
		}
		// �鿴�ӿؼ��Ƿ���������
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

	// ���øÿؼ��Ƿ�༭ʱ��ʾ����ʵ�ֿ����Ż�������resetMsgRegion����
	void ContainerWindow<EditorContainerFunc>::setEditShow(bool editShow)
	{
		//for (auto chp : getConstChildren())
		//{
		//	chp->setEditShow(editShow);
		//}

		ContainerWindow<EditorEditableFunc>::setEditShow(editShow);
	}
}