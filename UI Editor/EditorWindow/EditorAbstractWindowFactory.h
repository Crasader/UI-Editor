#ifndef EDITOR_ABSTRACT_WINDOW_FACTORY_H
#define EDITOR_ABSTRACT_WINDOW_FACTORY_H

#include "SimpleWindow/SimpleWindow.h"
#include "../CopyDrop/CopyWinObject.h"
#include "EditorWindowInterface.h"


class EditorAbstractWindowFactory
{
public:
	static EditorAbstractWindowFactory* winFactoryInst() { return nullptr; }

	EditorAbstractWindowFactory() {}
	virtual ~EditorAbstractWindowFactory() {}

	// ���ݿ����Ŀؼ����ݣ�����ؼ�
	virtual EditorAbstractWindow* createCopyObjectWnd(CopyWindowInfo winObject,
		EditorAbstractWindow* parent, int relX, int relY, int width = -1, int height = -1) { return nullptr; }

	// ����һ������ؼ�
	virtual EditorAbstractWindow* createManageWnd(int width, int height) { return nullptr; }

	//virtual inner::SimpleWindow<T>* createStatic() const = 0;
	//virtual SimpleWindow<T>* createButton() const = 0;
};

#endif	// EDITOR_ABSTRACT_WINDOW_FACTORY_H
