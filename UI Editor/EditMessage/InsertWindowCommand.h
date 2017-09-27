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
	class InsertWindowCommand : public wxCommand
	{
	public:
		InsertWindowCommand(){}
		InsertWindowCommand(AbstractEditorWindow* insertWnd, ID_TYPE id)
			: m_insertWnd(insertWnd), m_id(id) {}
		~InsertWindowCommand() override {}

		// �Ƿ���Ի���
		bool CanUndo() const override { return true; }
		// ִ��
		bool Do() override;
		// ����
		bool Undo() override;

	private:
		// ������¼�����Ĵ���
		AbstractEditorWindow* m_insertWnd = nullptr;
		// ������¼����ID��Doʱ����ʾ�����ڵ�ID��Undo��ʱ��������¼�Ӵ��ڵ�ID
		ID_TYPE m_id = -1;
	};

	inline bool InsertWindowCommand::Do()
	{
		return false;
	}

	inline bool InsertWindowCommand::Undo()
	{
		return false;
	}
}

#endif	// INSERT_WINDOW_COMMAND_H
