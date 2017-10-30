#ifndef ABSTRACT_WINDOW_FACTORY_H
#define ABSTRACT_WINDOW_FACTORY_H

#include "SimpleWindow/SimpleWindow.h"
#include "../CopyDrop/CopyWinObject.h"
#include "EditorWindowInterface.h"


class AbstractWindowFactory
{
public:
	static AbstractWindowFactory* winFactoryInst() { return nullptr; }

	AbstractWindowFactory() {}
	virtual ~AbstractWindowFactory() {}

	// ���ݿ����Ĵ������ݣ����촰��
	virtual EditorAbstractWindow* createCopyObjectWnd(CopyWindowInfo winObject,
		EditorAbstractWindow* parent, int relX, int relY, int width = -1, int height = -1) { return nullptr; }

	// ����һ��������
	virtual EditorAbstractWindow* createManageWnd(int width, int height) { return nullptr; }

	//virtual inner::SimpleWindow<T>* createStatic() const = 0;
	//virtual SimpleWindow<T>* createButton() const = 0;
};

#endif	// ABSTRACT_WINDOW_FACTORY_H
