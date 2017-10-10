#ifndef REMOVE_WINDOW_COMMAND_H
#define REMOVE_WINDOW_COMMAND_H

/*
 * �ļ�����RemoveWindowCommand
 * ���ã�����ʵ���Ƴ�һ�����ڵ�����
 * ˵��������Ӵ��ڱ����뵽�������У��򸸴��ڸ����Ӵ��ڵ�ɾ��
 * �����������Ӵ��ڵ�ɾ��
 */

#include "InsertWindowCommand.h"

namespace Command
{
	template <typename T>
	class RemoveWindowCommand : public InsertWindowCommand<T>
	{
	public:
		RemoveWindowCommand(T* winMgr, AbstractEditorWindow* removeWnd, AbstractEditorWindow* parentWnd)
			: InsertWindowCommand<T>(winMgr, removeWnd, parentWnd) { }
		~RemoveWindowCommand() override {}


		// �ع�Do��������InsertWindowCommand�����෴
		bool Do() override { return false; }
		// �ع�Undo��������InsertWindowCommand�����෴
		bool Undo() override { return false; }

	};

	template <typename T>
	inline bool RemoveWindowCommand<T>::Do()
	{
		return InsertWindowCommand<T>::Undo();
	}

	template <typename T>
	inline bool InsertWindowCommand<T>::Do()
	{
		return InsertWindowCommand<T>::Do();
	}
}

#endif	// REMOVE_WINDOW_COMMAND_H
