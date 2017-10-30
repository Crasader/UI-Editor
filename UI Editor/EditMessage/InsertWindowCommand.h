#ifndef INSERT_WINDOW_COMMAND_H
#define INSERT_WINDOW_COMMAND_H

/*
 * �ļ�����InsertWindowCommand
 * ���ã����һ�����ڶ���
 * ˵��������Ӵ��ڱ���ӵ��������У��򸸴��ڸ�������Ӵ��ڵ�ɾ����
 * �����������Ӵ��ڵ�ɾ�����ж�����hasParent
 */

#include <wx/cmdproc.h>
#include <stdexcept>
#include "../EditorWindow/EditorWindowInterface.h"

namespace Command
{
	class ChangeManager;

	const size_t INSERT_DEF_IDX = -1;		// ��ʾ���뵽���

	template <typename T>
	class InsertWindowCommand : public wxCommand
	{
	public:
		InsertWindowCommand(T winMgr, EditorAbstractWindow* insertWnd, EditorAbstractWindow* parentWnd)
			: m_winMgr(winMgr), m_insertWnd(insertWnd), m_parentWnd(parentWnd)
		{
			if (winMgr == NULL || insertWnd == NULL || parentWnd == NULL)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr, insertWnd and parentWnd shouldn't be nullptr"));
			}
		}
		~InsertWindowCommand() override;

		// ���ò�������
		void setInsertIdx(size_t idx) { m_idx = idx; }
		// ��ȡ��������
		size_t getInsertIdx() const { return m_idx; }

		// �Ƿ���Ի���
		bool CanUndo() const override { return true; }
		// ִ��
		bool Do() override;
		// ����
		bool Undo() override;

	protected:
		// ������¼�����Ĵ���
		EditorAbstractWindow* m_insertWnd = nullptr;
		// ������¼����ĸ�����
		EditorAbstractWindow* m_parentWnd = nullptr;
		// ��������
		size_t m_idx = INSERT_DEF_IDX;
		// �����Ĵ�����
		T m_winMgr;
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
		return m_winMgr->removeWindow(m_insertWnd);
	}


	template <typename T>
	InsertWindowCommand<T>::~InsertWindowCommand()
	{
		// �����������������Ĵ���Ϊ�������ڣ������ɾ��
		if (!m_insertWnd->hasParent())
		{
			delete m_insertWnd;
			m_insertWnd = nullptr;
		}
	}
}

#endif	// INSERT_WINDOW_COMMAND_H
