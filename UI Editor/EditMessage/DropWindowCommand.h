#ifndef DROP_WINDOW_COMMAND_H
#define DROP_WINDOW_COMMAND_H

/*
 * �ļ���: DropWindowCommand
 * ���ã��������������һ���ؼ��������ÿؼ�����Ϊ��ǰ�ؼ�
 */

#include "InsertWindowCommand.h"
#include "CurrentWindowCommand.h"
#include "SelectWindowsCommand.h"

namespace Command
{
	template <typename T>
	class DropWindowCommand : public wxCommand
	{
	public:
		DropWindowCommand(T t, EditorAbstractWindow* insertWnd, EditorAbstractWindow* parentWnd)
			: wxCommand(true),
			m_insertCommand(t, insertWnd, parentWnd), m_curWinCommand(t, insertWnd),
			m_selWindowsCommand(t, std::unordered_set<ID_TYPE>{insertWnd->getId()})
		{

		}
		~DropWindowCommand() override {}

		// �ع�ִ��
		bool Do() override;
		// �ع�ȡ��ִ��
		bool Undo() override;

	private:
		InsertWindowCommand<T> m_insertCommand;
		CurrentWindowCommand<T> m_curWinCommand;
		SelectWindowsCommand<T> m_selWindowsCommand;
	};

	template <typename T>
	bool DropWindowCommand<T>::Do()
	{
		bool flag = m_insertCommand.Do();
		if (flag)
		{
			flag = m_curWinCommand.Do();
		}
		if (flag)
		{
			flag = m_selWindowsCommand.Do();
		}
		return flag;
	}

	template <typename T>
	bool DropWindowCommand<T>::Undo()
	{
		bool flag = m_selWindowsCommand.Undo();
		if (flag)
		{
			flag = m_curWinCommand.Undo();
		}
		if (flag)
		{
			flag = m_insertCommand.Undo();
		}
		return flag;
	}
}

#endif	// DROP_WINDOW_COMMAND_H
