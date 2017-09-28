#ifndef INSERT_WINDOW_COMMAND_H
#define INSERT_WINDOW_COMMAND_H

/*
 * �ļ�����InsertWindowCommand
 * ���ã����һ�����ڶ���
 */

#include <wx/cmdproc.h>
#include <stdexcept>
#include "../EditorWindow/WindowInterface.h"

namespace Command
{
	const int INSERT_POS_DEF_X = 5;
	const int INSERT_POS_DEF_Y = 5;
	const int INSERT_DEF_IDX = -1;		// ��ʾ���뵽���

	template <typename T>
	class InsertWindowCommand : public wxCommand
	{
	public:
		InsertWindowCommand(T* winMgr, AbstractEditorWindow* insertWnd, AbstractEditorWindow* parentWnd)
			: m_winMgr(winMgr), m_insertWnd(insertWnd), m_parentWnd(parentWnd)
		{
			if (winMgr == NULL || insertWnd == NULL || parentWnd == NULL)
			{
				throw std::invalid_argument("InsertWindowCommand: winMgr, insertWnd and parentWnd shouldn't be nullptr");
			}
		}
		~InsertWindowCommand() override {}

		// ���ò����λ��
		void setInsertPos(int x, int y) { m_reX = x; m_relY = y; }
		// ���ò�������
		void setInsertIdx(size_t idx) { m_idx = idx; }

		// �Ƿ���Ի���
		bool CanUndo() const override { return true; }
		// ִ��
		bool Do() override;
		// ����
		bool Undo() override;

	protected:
		// ������¼�����Ĵ���
		AbstractEditorWindow* m_insertWnd = nullptr;
		// ������¼����ĸ�����
		AbstractEditorWindow* m_parentWnd = nullptr;
		// �����λ��
		int m_relX = INSERT_POS_DEF_X;
		// �����λ��
		int m_relY = INSERT_POS_DEF_Y;
		// ��������
		size_t m_idx = INSERT_DEF_IDX;
		// �����Ĵ�����
		T* m_winMgr = nullptr;
	};

	template <typename T>
	inline bool InsertWindowCommand<T>::Do()
	{
		if (m_idx == INSERT_DEF_IDX)
		{
			return m_winMgr->pushBackWindow(m_parentWnd, m_insertWnd);
		}
		else
		{
			return m_winMgr->insertWindow(m_parentWnd, m_idx, m_insertWnd);
		}
	}

	template <typename T>
	inline bool InsertWindowCommand<T>::Undo()
	{
		m_winMgr->removeWindow(m_insertWnd);
	}
}

#endif	// INSERT_WINDOW_COMMAND_H
