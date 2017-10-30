#ifndef CURRENT_WINDOW_COMMAND_H
#define CURRENT_WINDOW_COMMAND_H

/*
 * �ļ�����CurrentWindowCommand
 * ���ã����õ�ǰѡ�еĴ���
 * ˵�������༭��ʼ�ջ����һ����ǰѡ�еĴ��ڣ��ô���Ҫô���û������Ĵ��ڣ�Ҫô�ǹ����ڣ�
 * ���й����ڲ����Ա༭����
 */

#include <wx/cmdproc.h>
#include <stdexcept>
#include "../EditorWindow/EditorWindowInterface.h"

namespace Command
{
	template <typename T>
	class CurrentWindowCommand : public wxCommand
	{
	public:
		CurrentWindowCommand(T winMgr, EditorAbstractWindow* lastCurWnd, EditorAbstractWindow* newCurWnd)
			: m_winMgr(winMgr), m_lastCurWnd(lastCurWnd), m_newCurWnd(newCurWnd)
		{
			if (winMgr == nullptr || lastCurWnd == nullptr || newCurWnd == nullptr)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr, lastCurWnd and newCurWnd shouldn't be nullptr"));
			}
		}
		~CurrentWindowCommand() { }

		// �Ƿ���Ի���
		bool CanUndo() const override { return true; }

		// �ع�ִ�к���
		bool Do() override;
		// �ع�ȡ������
		bool Undo() override;

	private:
		T m_winMgr;
		EditorAbstractWindow* m_lastCurWnd = nullptr;
		EditorAbstractWindow* m_newCurWnd = nullptr;
	};

	template <typename T>
	bool CurrentWindowCommand<T>::Do()
	{
		m_winMgr->changeSelectWnd(m_lastCurWnd, m_newCurWnd);
		return true;
	}

	template <typename T>
	bool CurrentWindowCommand<T>::Undo()
	{
		m_winMgr->changeSelectWnd(m_newCurWnd, m_lastCurWnd);
		return true;
	}
}

#endif	// CURRENT_WINDOW_COMMAND_H