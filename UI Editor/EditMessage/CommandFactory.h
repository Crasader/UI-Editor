#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "../EditorWindow/EditorWindowInterface.h"
#include "DropWindowCommand.h"
#include "ChangeWinAttrCommand.h"
#include "CurrentWindowIdCommand.h"

namespace Command
{
	class ChangeManager;

	class CommandFactory
	{
	public:
		CommandFactory(ChangeManager* chgMgr): m_chgMgr(chgMgr){ }
		~CommandFactory() {}

		static const CommandFactory* const createInstance(ChangeManager* chgMgr);
		static const CommandFactory* const instance() { return s_factory; }

		// ����һ��DropWindowCommand����
		DropWindowCommand<ChangeManager*>* createDropWindowCommand(EditorAbstractWindow* insertWnd, 
			EditorAbstractWindow* parentWnd) const;
		// ����һ��ChangeWinAttrCommand����
		ChangeWinAttrCommand<ChangeManager*>* createChangeWinAttrCommand(const wxString& attrName, const wxAny& toSetValue) const;
		// ����һ��ѡ��ǰ�ؼ�����
		CurrentWindowCommand<ChangeManager*>* createCurrentWindowCommand(EditorAbstractWindow* curWnd) const;
		// ����һ��ѡ��ǰ�ؼ�ID����
		CurrentWindowIdCommand<ChangeManager*>* createCurrentWindowIdCommand(ID_TYPE curWndId) const;

	private:
		static CommandFactory* s_factory;
		ChangeManager* m_chgMgr;
	};

	inline const CommandFactory* const CommandFactory::createInstance(ChangeManager * chgMgr)
	{
		if (s_factory == nullptr)
		{
			s_factory = new CommandFactory(chgMgr);
		}

		return s_factory;
	}
}

#endif	// COMMAND_FACTORY_H
