#ifndef REMOVE_WINDOW_COMMAND_H
#define REMOVE_WINDOW_COMMAND_H

/*
 * �ļ�����RemoveWindowCommand
 * ���ã�����ʵ���Ƴ�һ�����ڵ�����
 */

#include "InsertWindowCommand.h"

namespace Command
{
	template <typename T>
	class RemoveWindowCommand : public InsertWindowCommand<T>
	{
	public:
		RemoveWindowCommand(T* winMgr):InsertWindowCommand<T>(winMgr) {}
		~RemoveWindowCommand() override {}

		// �ع�Do��������InsertWindowCommand�����෴
		bool Do() override { return false; }
		// �ع�Undo��������InsertWindowCommand�����෴
		bool Undo() override { return false; }

	private:
		// ������¼�ڸ������е�λ��
		int m_index = 0;
	};
}

#endif	// REMOVE_WINDOW_COMMAND_H
