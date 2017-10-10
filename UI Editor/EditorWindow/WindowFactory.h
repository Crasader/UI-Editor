#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include <map>
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

	// ���ݿ����Ĵ������ݣ����촰��
	AbstractEditorWindow* createCopyObjectWnd(CopyWindowInfo winObject,
		AbstractEditorWindow* parent, int relX, int relY, int width = -1, int height = -1) override;

	// ����һ��������
	AbstractEditorWindow* createManageWnd(int width, int height) override;

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
