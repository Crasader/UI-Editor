#ifndef EDITOR_WORK_AREA_HELP_H
#define EDITOR_WORK_AREA_HELP_H

/*
 * �ļ�����EditorWorkAreaHelp
 * ���ã�ΪEditorWorkArea�ṩһЩ���ܺ���
 */

#include "../EditorWindow/WindowInterface.h"
#include "../EditorWindow/EditorWindowCheck.h"

namespace WorkAreaHelp
{
	template <typename T = UiEditable<AbstractEditorWindow>>
	AbstractEditorWindow* getMatchWindow(AbstractEditorWindow* searchWnd, int x, int y);
}

template <typename T>
AbstractEditorWindow* WorkAreaHelp::getMatchWindow(AbstractEditorWindow* searchWnd, int x, int y)
{
	// ��������ڲ����Ա༭�����Ӵ��ڶ������Ա༭
	if (!T(searchWnd))
	{
		return nullptr;
	}
	// ������ҵĴ�����Container���ڣ����Ȳ鿴�Ӵ���
	if (searchWnd->IsContainerWnd())
	{

	}
}

#endif	// EDITOR_WORK_AREA_HELP_H
