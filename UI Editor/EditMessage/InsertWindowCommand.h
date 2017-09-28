#ifndef INSERT_WINDOW_COMMAND_H
#define INSERT_WINDOW_COMMAND_H

/*
 * �ļ�����InsertWindowCommand
 * ���ã����һ�����ڶ���
 */

#include <wx/cmdproc.h>
#include "../EditorWindow/WindowInterface.h"

namespace Command
{
	template <typename T>
	class InsertWindowCommand : public wxCommand
	{
	public:
		InsertWindowCommand(T* winMgr) : m_winMgr(winMgr) {}
		InsertWindowCommand(AbstractEditorWindow* insertWnd, ID_TYPE id)
			: m_insertWnd(insertWnd), m_id(id) {}
		~InsertWindowCommand() override {}

		// �Ƿ���Ի���
		bool CanUndo() const override { return true; }
		// ִ��
		bool Do() override;
		// ����
		bool Undo() override;

	protected:
		// ������¼�����Ĵ���
		AbstractEditorWindow* m_insertWnd = nullptr;
		// ������¼����ID��Doʱ����ʾ�����ڵ�ID��Undo��ʱ��������¼�Ӵ��ڵ�ID
		ID_TYPE m_id = -1;
		// �����Ĵ�����
		T* m_winMgr = nullptr;
	};

	template <typename T>
	inline bool InsertWindowCommand<T>::Do()
	{
		m_winMgr->pushBackWindow(m_id, m_insertWnd);
		m_id = m_insertWnd->getId();
	}

	template <typename T>
	inline bool InsertWindowCommand<T>::Undo()
	{
		return false;
	}
}

#endif	// INSERT_WINDOW_COMMAND_H
