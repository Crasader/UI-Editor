#ifndef COMMAND_STACK_H
#define COMMAND_STACK_H

/*
 * �ļ�����CommandStack
 * ���ã������洢undo/redo��Command�б�
 */

#include <wx/cmdproc.h>

namespace Command
{
	class CommandStack : public wxCommandProcessor
	{
	public:
		CommandStack(int maxCommands = -1);
		~CommandStack() override;

	private:

	};
}

#endif	// COMMAND_STACK_H
