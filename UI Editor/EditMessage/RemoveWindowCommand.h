#ifndef REMOVE_WINDOW_COMMAND_H
#define REMOVE_WINDOW_COMMAND_H

/*
 * �ļ�����RemoveWindowCommand
 * ���ã�����ʵ���Ƴ�һ���ؼ�������
 * ˵��������ӿؼ������뵽���ؼ��У��򸸿ؼ������ӿؼ���ɾ��
 * �����������ӿؼ���ɾ��
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
