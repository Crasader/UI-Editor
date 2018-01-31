#include "EditorContainerWindow.h"
#include "EditorWindowCheck.h"

#include "../EditMessage/CommandFactory.h"
#include "../EditMessage/ChangeManager.h"

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

	// ������갴��
	bool ContainerWindow<EditorContainerFunc>::handleLMouseDown(int x, int y)
	{
		if (!Check_UiInMsgRegion(x, y)(this))
		{
			return false;
		}

		auto beg = getChildrenBeg();
		auto end = getChildrenEnd();
		for (; beg != end; ++beg)
		{
			auto childWnd = *beg;
			auto isHandle = childWnd->handleLMouseDown(x - childWnd->getRelX(), y - childWnd->getRelY());
			if (isHandle)
			{
				return isHandle;
			}
		}

		SIMPLE_WINDOW_TYPE::handleLMouseDown(x, y);

		return true;
	}
}