#ifndef EDITOR_WORK_AREA_HELP_H
#define EDITOR_WORK_AREA_HELP_H

/*
 * �ļ�����EditorWorkAreaHelp
 * ���ã�ΪEditorWorkArea�ṩһЩ���ܺ���
 */

#include <type_traits>
#include "../EditorWindow/EditorWindowInterface.h"
#include "../EditorWindow/EditorWindowCheck.h"

namespace WorkAreaHelp
{
	// �ж�ʱ����Ҫ�����������������Ż��ж��Ӵ����Ƿ�������������������ڲ����㣬���Ӵ��ڲ��ж�
	// �ú���ʵ�ֿ�������Ϣ����Χ��������ҵ㲻�ڴ�����Ϣ����Χ���򲻴���
	// ���������Ϊ�����ڲο�����
	template <typename T = Check_UiEditable/*, bool = std::is_class<T>::value*/>
	EditorAbstractWindow* getMatchWindow(EditorAbstractWindow* searchWnd, wxCoord x, wxCoord y, T&& t = T());
}

template <typename T>
EditorAbstractWindow* WorkAreaHelp::getMatchWindow(EditorAbstractWindow* searchWnd, wxCoord x, wxCoord y, T&& t)
{
	x -= narrow_cast<wxCoord>(searchWnd->getRelX());
	y -= narrow_cast<wxCoord>(searchWnd->getRelY());
	// ����ô��ڲ����Ա༭�����Ӵ��ڶ������Ա༭
	if (!t(searchWnd))
	{
		return nullptr;
	}
	// �ж��Ƿ�����Ϣ��Χ��
	wxRegion msgRegion = searchWnd->getMsgRegion();
	if (!msgRegion.Contains(x, y))
	{
		return nullptr;
	}
	// ������ҵĴ�����Container���ڣ����Ȳ鿴�Ӵ���
	if (searchWnd->isContainerWnd())
	{
		auto beg = searchWnd->getChildrencConstBeg();
		auto end = searchWnd->getChildrenConstEnd();
		for (; beg != end; ++beg)
		{
			auto ret = getMatchWindow(*beg, x, y, std::forward<T>(t));
			if (ret != nullptr)
			{
				return ret;
			}
		}
	}
	return searchWnd;
}

#endif	// EDITOR_WORK_AREA_HELP_H
