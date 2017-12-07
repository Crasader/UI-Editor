#ifndef CUR_WINDOW_SELECT_COMMAND_H
#define CUR_WINDOW_SELECT_COMMAND_H

/*
 * �ļ�����CurWindowSelectCommand
 * ���ã�ѡ���µĴ���Ϊ��ǰ�༭���ڣ����ҽ��ô�������ΪΨһѡ�д���
 * ˵����ʹ��CurWindowCommand��SelectWindowsCommandʵ��
 */

#include "CurrentWindowCommand.h"
#include "SelectWindowsCommand.h"

namespace Command
{
	template <typename T>
	class CurWindowSelectCommand : public wxCommand
	{
	public:
		CurWindowSelectCommand(T t, EditorAbstractWindow* curWindow)
			: wxCommand(true), m_curWinCommand(t, curWindow),
			m_selWindowsCommand(t, std::unordered_set<ID_TYPE>{curWindow->getId()})
		{

		}
		~CurWindowSelectCommand() override {}

		// �ع�ִ��
		bool Do() override;
		// �ع�ȡ��ִ��
		bool Undo() override;

	private:
		CurrentWindowCommand<T> m_curWinCommand;
		SelectWindowsCommand<T> m_selWindowsCommand;
	};

	// ִ��
	template<typename T>
	inline bool CurWindowSelectCommand<T>::Do()
	{
		bool flag = m_curWinCommand.Do();
		if (flag)
		{
			flag = m_selWindowsCommand.Do();
		}
		return flag;
	}

	// ȡ��ִ��
	template<typename T>
	inline bool CurWindowSelectCommand<T>::Undo()
	{
		bool flag = m_selWindowsCommand.Undo();
		if (flag)
		{
			flag = m_curWinCommand.Undo();
		}
		return flag;
	}
}

#endif	// CUR_WINDOW_SELECT_COMMAND_H