#ifndef CURRENT_WINDOW_COMMAND_H
#define CURRENT_WINDOW_COMMAND_H

/*
 * �ļ�����CurrentWindowCommand
 * ���ã����õ�ǰ�༭�Ŀؼ�
 * ˵�������༭��ʼ�ջ����һ����ǰ�༭�Ŀؼ����ÿؼ�Ҫô���û������Ŀؼ���Ҫô�ǹ���ؼ���
 * ���й���ؼ������Ա༭����
 */

#include <stdexcept>
#include <wx/cmdproc.h>
#include "../EditorWindow/EditorWindowInterface.h"

namespace Command
{
	template <typename T>
	class CurrentWindowCommand : public wxCommand
	{
	public:
		CurrentWindowCommand(T mgr, EditorAbstractWindow* newCurWnd)
			: wxCommand(true),
			m_mgr(mgr), m_toSetCurWnd(newCurWnd)
		{
			if (mgr == nullptr || newCurWnd == nullptr)
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
		// ������¼��������Ϊ��ǰ�༭�Ĵ���
		EditorAbstractWindow* m_toSetCurWnd = nullptr;
	};

	template <typename T>
	bool CurrentWindowCommand<T>::Do()
	{
		return m_mgr->changeCurrentWnd(m_toSetCurWnd);
	}

	template <typename T>
	bool CurrentWindowCommand<T>::Undo()
	{
		return m_mgr->changeCurrentWnd(m_toSetCurWnd);
	}
}

#endif	// CURRENT_WINDOW_COMMAND_H