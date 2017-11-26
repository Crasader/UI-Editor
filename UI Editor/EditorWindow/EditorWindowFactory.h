#ifndef EDITOR_WINDOW_FACTORY_H
#define EDITOR_WINDOW_FACTORY_H

#include <map>
#include "EditorAbstractWindowFactory.h"

namespace inner
{
	template <typename T>
	class SimpleLabel;
}

class EditorLabel;

class EditorWindowFactory : public EditorAbstractWindowFactory
{
public:
	using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;
public:
	static EditorAbstractWindowFactory* winFactoryInst();

	EditorWindowFactory() {}
	~EditorWindowFactory() {}

	// ���ݿ����Ŀؼ����ݣ�����ؼ�
	EditorAbstractWindow* createCopyObjectWnd(CopyWindowInfo winObject,
		EditorAbstractWindow* parent, int relX, int relY, int width = -1, int height = -1) override;

	// ����һ������ؼ�
	EditorAbstractWindow* createManageWnd(int width, int height) override;

	//// ����һ��Static
	//EditorLabel* createStatic() const override;
	//// ����һ��Button
	//EditorButton* createButton() const override;

private:
	// ���ݿ����ؼ��������¿ؼ�ȡһ������
	void changeWindowName(wxString& winName);

private:
	static EditorAbstractWindowFactory* s_factoryInst;
	// ������¼ÿ�����͵Ĵ�����������������ɾ����
	std::map<wxString, long> m_winTypeToNums;
};

namespace WindowFactoryImpl
{
	// ���ݿؼ�����ȡ��Ӧ�Ŀؼ�����
	EditorAbstractWindow* createEditorWnd(const wxString& winName,
		EditorAbstractWindow* parent, int relX, int relY, int width, int height);
}

inline EditorAbstractWindowFactory* EditorWindowFactory::winFactoryInst()
{
	if (s_factoryInst == nullptr)
	{
		s_factoryInst = new EditorWindowFactory();
	}

	return s_factoryInst;
}

#endif	// EDITOR_WINDOW_FACTORY_H
