#ifndef CURRENT_WINDOW_COMMAND_H
#define CURRENT_WINDOW_COMMAND_H

/*
 * �ļ�����CurrentWindowCommand
 * ���ã����õ�ǰѡ�еĿؼ�
 * ˵�������༭��ʼ�ջ����һ����ǰѡ�еĿؼ����ÿؼ�Ҫô���û������Ŀؼ���Ҫô�ǹ���ؼ���
 * ���й���ؼ������Ա༭����
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
		CurrentWindowCommand(T mgr, EditorAbstractWindow* lastCurWnd, EditorAbstractWindow* newCurWnd)
			: wxCommand(true),
			m_mgr(mgr), m_lastCurWnd(lastCurWnd), m_newCurWnd(newCurWnd)
		{
			if (mgr == nullptr || lastCurWnd == nullptr || newCurWnd == nullptr)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr, lastCurWnd and newCurWnd shouldn't be nullptr"));
			}
		}
		~CurrentWindowCommand() { }

		// �ع�ִ�к���
		bool Do() override;
		// �ع�ȡ��ִ�к���
		bool Undo() override;

	private:
		T m_mgr;
		EditorAbstractWindow* m_lastCurWnd = nullptr;
		EditorAbstractWindow* m_newCurWnd = nullptr;
	};

	template <typename T>
	bool CurrentWindowCommand<T>::Do()
	{
		m_mgr->changeSelectWnd(m_lastCurWnd, m_newCurWnd);
		return true;
	}

	template <typename T>
	bool CurrentWindowCommand<T>::Undo()
	{
		m_mgr->changeSelectWnd(m_newCurWnd, m_lastCurWnd);
		return true;
	}
}

#endif	// CURRENT_WINDOW_COMMAND_H