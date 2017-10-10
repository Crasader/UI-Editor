#ifndef DROP_WINDOW_COMMAND_H
#define DROP_WINDOW_COMMAND_H

/*
 * �ļ���: DropWindowCommand
 * ���ã���������������һ�����ڣ������ô�������Ϊ��ǰ����
 */

#include "InsertWindowCommand.h"
#include "CurrentWindowCommand.h"

namespace Command
{
	class ChangeManager;

	template <typename T>
	class DropWindowCommand : public wxCommand
	{
	public:
		DropWindowCommand(T t, AbstractEditorWindow* insertWnd, AbstractEditorWindow* parentWnd, AbstractEditorWindow* lastCurWnd)
			: m_insertCommand(t, insertWnd, parentWnd), m_curWinCommand(t, lastCurWnd, insertWnd)
		{

		}
		~DropWindowCommand() override {}

		// �Ƿ���Ի���
		bool CanUndo() const override { return true; }
		// �ع�ִ��
		bool Do() override;
		// �ع�ȡ��ִ��
		bool Undo() override;

	private:
		InsertWindowCommand<T> m_insertCommand;
		CurrentWindowCommand<T> m_curWinCommand;
	};

	template <typename T>
	bool DropWindowCommand<T>::Do()
	{
		bool flag = m_insertCommand.Do();
		flag = flag && m_curWinCommand.Do();
		return flag;
	}

	template <typename T>
	bool DropWindowCommand<T>::Undo()
	{
		bool flag = m_curWinCommand.Undo();
		flag = flag && m_insertCommand.Do();
		return flag;
	}
}

#endif	// DROP_WINDOW_COMMAND_H