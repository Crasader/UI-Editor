#include "CommandFactory.h"
#include "ChangeManager.h"

namespace Command
{
	CommandFactory* CommandFactory::s_factory = nullptr;

	DropWindowCommand<ChangeManager*> * CommandFactory::createDropWindowCommand(EditorAbstractWindow * insertWnd,
		EditorAbstractWindow * parentWnd) const
	{
		return new DropWindowCommand<ChangeManager*>(ChangeManager::instance(), insertWnd, parentWnd);
	}

	// ����һ��ChangeWinAttrCommand����
	ChangeWinAttrCommand<ChangeManager*>* CommandFactory::createChangeWinAttrCommand(const wxString& attrName, const wxAny& toSetValue) const
	{
		return new ChangeWinAttrCommand<ChangeManager*>(ChangeManager::instance(), attrName, toSetValue);
	}

	// ����һ��ѡ��ǰ�ؼ�����
	CurrentWindowCommand<ChangeManager*>* CommandFactory::createCurrentWindowCommand(EditorAbstractWindow * curWnd) const
	{
		return new CurrentWindowCommand<ChangeManager*>(ChangeManager::instance(), curWnd);
	}

	// ����һ��ѡ��ǰ�ؼ�ID����
	CurrentWindowIdCommand<ChangeManager*>* CommandFactory::createCurrentWindowIdCommand(ID_TYPE curWndId) const
	{
		return new CurrentWindowIdCommand<ChangeManager*>(ChangeManager::instance(), curWndId);
	}

	// ����һ��ѡ��ǰ�ؼ���������ΪΨһѡ�������
	CurWindowSelectCommand<ChangeManager*>* CommandFactory::createCurWindowSelectCommand(EditorAbstractWindow * curWnd) const
	{
		return new CurWindowSelectCommand<ChangeManager*>(ChangeManager::instance(), curWnd);
	}
}

