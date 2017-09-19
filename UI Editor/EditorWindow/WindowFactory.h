#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include "AbstractWindowFactory.h"
#include "EditorStatic.h"

class EditorButton;

class WindowFactory : AbstractWindowFactory <inner::EditorFunc>
{
public:
	using EditorStatic = inner:: SimpleStatic<inner::EditorFunc>;
public:
	WindowFactory() {}
	~WindowFactory() {}

	// ���ݴ������������ڶ�Ӧ����

	// ����һ��Static
	EditorStatic* createStatic() const override;
	//// ����һ��Button
	//EditorButton* createButton() const override;
};

#endif	// WINDOW_FACTORY_H
