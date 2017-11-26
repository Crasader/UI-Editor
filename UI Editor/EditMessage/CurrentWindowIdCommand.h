#ifndef CURRENT_WINDOW_ID_COMMAND_H
#define CURRENT_WINDOW_ID_COMMAND_H

/*
* �ļ�����CurrentWindowIdCommand
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
	class CurrentWindowIdCommand : public wxCommand
	{
	public:
		CurrentWindowIdCommand(T mgr, ID_TYPE newCurWndId)
			: wxCommand(true),
			m_mgr(mgr), m_toSetCurWndId(newCurWndId)
		{
			if (mgr == nullptr)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr shouldn't be nullptr"));
			}
		}
		~CurrentWindowIdCommand() { }

		// �ع�ִ�к���
		bool Do() override;
		// �ع�ȡ��ִ�к���
		bool Undo() override;

	private:
		T m_mgr;
		// ������¼��������Ϊ��ǰ�༭�Ĵ���
		ID_TYPE m_toSetCurWndId;
	};

	template <typename T>
	bool CurrentWindowIdCommand<T>::Do()
	{
		return m_mgr->changeCurrentWnd(m_toSetCurWndId);
	}

	template <typename T>
	bool CurrentWindowIdCommand<T>::Undo()
	{
		return m_mgr->changeCurrentWnd(m_toSetCurWndId);
	}
}

#endif	// CURRENT_WINDOW_ID_COMMAND_H