#ifndef WORK_AREA_HELP_H
#define WORK_AREA_HELP_H

/*
 * �ļ�����EditorWorkAreaHelp
 * ���ã�ΪFormWorkArea�ṩһЩ���ܺ���
 */

#include <type_traits>
#include "../EditorWindow/EditorWindowInterface.h"
#include "../EditorWindow/EditorWindowCheck.h"

namespace WorkAreaHelp
{
	// �ж�ʱ����Ҫ���ؼ������������Ż��ж��ӿؼ��Ƿ�����������������ؼ������㣬���ӿؼ����ж�
	// �ú���ʵ�ֿ�������Ϣ����Χ��������ҵ㲻�ڿؼ���Ϣ����Χ���򲻴���
	// ���������Ϊ���ؼ��ο�����
	template <typename T = Check_UiEditable/*, bool = std::is_class<T>::value*/>
	const EditorAbstractWindow* getMatchWindow(const EditorAbstractWindow* searchWnd, wxCoord x, wxCoord y, T&& t = T());

	template <typename T = Check_UiEditable>
	EditorAbstractWindow* getMatchWindow(EditorAbstractWindow* searchWnd, wxCoord x, wxCoord y, T&& t = T())
	{
		const EditorAbstractWindow* ret = getMatchWindow(const_cast<const EditorAbstractWindow*>(searchWnd), x, y, t);
		return const_cast<EditorAbstractWindow*>(ret);
	}
}

template <typename T>
const EditorAbstractWindow* WorkAreaHelp::getMatchWindow(const EditorAbstractWindow* searchWnd, wxCoord x, wxCoord y, T&& t)
{
	x -= narrow_cast<wxCoord>(searchWnd->getRelX());
	y -= narrow_cast<wxCoord>(searchWnd->getRelY());
	// ����ÿؼ������Ա༭�����ӿؼ��������Ա༭
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
	// ������ҵĴ�����Container�ؼ������Ȳ鿴�ӿؼ�
	if (searchWnd->isContainerWnd())
	{
		auto beg = searchWnd->getChildrenConstBeg();
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

#endif	// WORK_AREA_HELP_H
