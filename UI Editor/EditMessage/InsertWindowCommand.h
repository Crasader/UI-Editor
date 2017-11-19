#ifndef INSERT_WINDOW_COMMAND_H
#define INSERT_WINDOW_COMMAND_H

/*
 * �ļ�����InsertWindowCommand
 * ���ã����һ���ؼ�����
 * ˵��������ӿؼ�����ӵ����ؼ��У��򸸿ؼ���������ӿؼ���ɾ����
 * �����������ӿؼ���ɾ�����ж�����hasParent
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
		InsertWindowCommand(T mgr, EditorAbstractWindow* insertWnd, EditorAbstractWindow* parentWnd)
			: wxCommand(true),
			m_mgr(mgr), m_insertWnd(insertWnd), m_parentWnd(parentWnd)
		{
			if (mgr == NULL || insertWnd == NULL || parentWnd == NULL)
			{
				throw std::invalid_argument(__func__ + std::string(": winMgr, insertWnd and parentWnd shouldn't be nullptr"));
			}
		}
		~InsertWindowCommand() override;

		// ���ò�������
		void setInsertIdx(size_t idx) { m_idx = idx; }
		// ��ȡ��������
		size_t getInsertIdx() const { return m_idx; }

		// ִ��
		bool Do() override;
		// ����
		bool Undo() override;

	protected:
		// ������¼�����Ŀؼ�
		EditorAbstractWindow* m_insertWnd = nullptr;
		// ������¼����ĸ��ؼ�
		EditorAbstractWindow* m_parentWnd = nullptr;
		// ��������
		size_t m_idx = INSERT_DEF_IDX;
		// �����Ĺ�����
		T m_mgr;
	};

	template <typename T>
	inline bool InsertWindowCommand<T>::Do()
	{
		if (m_idx == INSERT_DEF_IDX)
		{
			return m_mgr->pushBackWindow(m_parentWnd, m_insertWnd);
		}
		else
		{
			return m_mgr->insertWindow(m_parentWnd, m_idx, m_insertWnd);
		}
	}

	template <typename T>
	inline bool InsertWindowCommand<T>::Undo()
	{
		return m_mgr->removeWindow(m_insertWnd);
	}


	template <typename T>
	InsertWindowCommand<T>::~InsertWindowCommand()
	{
		// �����������������Ŀؼ�Ϊ�����ؼ��������ɾ��
		if (!m_insertWnd->hasParent())
		{
			delete m_insertWnd;
			m_insertWnd = nullptr;
		}
	}
}

#endif	// INSERT_WINDOW_COMMAND_H
