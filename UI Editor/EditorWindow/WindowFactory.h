#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include "AbstractWindowFactory.h"

namespace inner
{
	template <typename T>
	class SimpleLabel;
}

class EditorLabel;

class WindowFactory : AbstractWindowFactory
{
public:
	using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;
public:
	static AbstractWindowFactory* winFactoryInst();

	WindowFactory() {}
	~WindowFactory() {}

	// 根据拷贝的窗口数据，构造窗口
	AbstractEditorWindow* createCopyObjectWnd(CopyWindowValue winObject,
		AbstractEditorWindow* parent, int relX, int relY, int width = -1, int height = -1) override;

	//// 创建一个Static
	//EditorLabel* createStatic() const override;
	//// 创建一个Button
	//EditorButton* createButton() const override;

private:
	static AbstractWindowFactory* s_factoryInst;
};

namespace WindowFactoryImpl
{
	// 根据窗口名获取对应的窗口对象
	AbstractEditorWindow* createEditorWnd(const wxString& winName,
		AbstractEditorWindow* parent, int relX, int relY, int width, int height);
}

inline AbstractWindowFactory* WindowFactory::winFactoryInst()
{
	if (s_factoryInst == nullptr)
	{
		s_factoryInst = new WindowFactory();
	}

	return s_factoryInst;
}

#endif	// WINDOW_FACTORY_H
