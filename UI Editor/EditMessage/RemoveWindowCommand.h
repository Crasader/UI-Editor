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
		RemoveWindowCommand(T* mgr, EditorAbstractWindow* removeWnd, EditorAbstractWindow* parentWnd)
			: InsertWindowCommand<T>(mgr, removeWnd, parentWnd) { }
		~RemoveWindowCommand() override {}


		// �ع�Do��������InsertWindowCommand�����෴
		bool Do() override;
		// �ع�Undo��������InsertWindowCommand�����෴
		bool Undo() override;

	};

	template <typename T>
	inline bool RemoveWindowCommand<T>::Do()
	{
		return InsertWindowCommand<T>::Undo();
	}

	template<typename T>
	inline bool RemoveWindowCommand<T>::Undo()
	{
		return InsertWindowCommand<T>::Do();
	}
}

#endif	// REMOVE_WINDOW_COMMAND_H
