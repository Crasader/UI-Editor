#ifndef EDITOR_WINDOW_FACTORY_H
#define EDITOR_WINDOW_FACTORY_H

#include <map>
#include "AbstractWindowFactory.h"

namespace inner
{
	template <typename T>
	class SimpleLabel;
}

class EditorLabel;

class EditorWindowFactory : AbstractWindowFactory
{
public:
	using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;
public:
	static AbstractWindowFactory* winFactoryInst();

	EditorWindowFactory() {}
	~EditorWindowFactory() {}

	// ���ݿ����Ĵ������ݣ����촰��
	EditorAbstractWindow* createCopyObjectWnd(CopyWindowInfo winObject,
		EditorAbstractWindow* parent, int relX, int relY, int width = -1, int height = -1) override;

	// ����һ��������
	EditorAbstractWindow* createManageWnd(int width, int height) override;

	//// ����һ��Static
	//EditorLabel* createStatic() const override;
	//// ����һ��Button
	//EditorButton* createButton() const override;

private:
	static AbstractWindowFactory* s_factoryInst;
	// ������¼ÿ�����͵Ĵ�����������������ɾ����
	std::map<wxString, long> m_winTypeToNums;
};

namespace WindowFactoryImpl
{
	// ���ݴ�������ȡ��Ӧ�Ĵ��ڶ���
	EditorAbstractWindow* createEditorWnd(const wxString& winName,
		EditorAbstractWindow* parent, int relX, int relY, int width, int height);
}

inline AbstractWindowFactory* EditorWindowFactory::winFactoryInst()
{
	if (s_factoryInst == nullptr)
	{
		s_factoryInst = new EditorWindowFactory();
	}

	return s_factoryInst;
}

#endif	// EDITOR_WINDOW_FACTORY_H
