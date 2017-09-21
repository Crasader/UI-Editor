#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include "AbstractWindowFactory.h"

namespace inner
{
	template <typename T>
	class SimpleLabel;
}

class EditorLabel;

class WindowFactory : AbstractWindowFactory <inner::EditorFunc>
{
public:
	using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;
public:
	WindowFactory() {}
	~WindowFactory() {}

	// ���ݿ����Ĵ������ݣ����촰��
	AbstractEditorWindow* createCopyObjectWnd(const CopyWindowValue& winObject,
		AbstractEditorWindow* parent, int relX, int relY, int width, int height) override;

	//// ����һ��Static
	//EditorLabel* createStatic() const override;
	//// ����һ��Button
	//EditorButton* createButton() const override;

private:
	// ���ݴ�������ȡ��Ӧ�Ĵ��ڶ���
	AbstractEditorWindow* createEditorWnd(const wxString& winName,
		AbstractEditorWindow* parent, int relX, int relY, int width, int height) const;
};

#endif	// WINDOW_FACTORY_H
