#include "ChangeManager.h"
#include "../Form/EditorWorkArea.h"
#include "../Form/EditorToolObjectView.h"
#include "../Form/EditorToolPropertyEditor.h"
#include "../Settings/WindowAttributeManager.h"

namespace Command
{
	const int MAX_COMMAND = 50;

	ChangeManager::ChangeManager()
		: m_commandStack(MAX_COMMAND)
	{
		
	}

	ChangeManager::~ChangeManager()
	{

	}

	ChangeManager* ChangeManager::s_changeManager = nullptr;

	// ���һ������
	bool ChangeManager::pushBackWindow(AbstractEditorWindow * parentWnd, AbstractEditorWindow * insertWnd)
	{
		// �޸���������
		bool flag = m_workArea->pushBackWindow(parentWnd, insertWnd);
		flag = flag && m_objectView->addWindowItem(parentWnd->getId(), insertWnd->getId(),
			insertWnd->getWindowObjectName(), insertWnd->getWindowClassName());
		return flag;
	}

	// ����һ������
	bool ChangeManager::insertWindow(AbstractEditorWindow * parentWnd, size_t idx, AbstractEditorWindow * insertWnd)
	{
		// �޸���������
		bool flag = m_workArea->insertWindow(parentWnd, idx, insertWnd);
		return flag;
	}

	// �Ƴ�һ������
	bool ChangeManager::removeWindow(AbstractEditorWindow * removeWnd)
	{
		// �޸���������
		bool flag = m_workArea->removeWindow(removeWnd);
		return flag;
	}

	// �޸ĵ�ǰѡ�еĴ���
	void ChangeManager::changeSelectWnd(AbstractEditorWindow * lastCurWnd, AbstractEditorWindow * newCurWnd)
	{
		// �޸���������
		m_workArea->setCurrentWindow(newCurWnd);
		// �޸����Ա༭��
		m_propertyEditor->resetAttrs(newCurWnd->getWindowClassName());
		// �����ö�Ӧ�������Ե�Ĭ��ֵ
		const auto& winAttrDefValues = m_winAttrMgr->getWinDefValues(newCurWnd->getWindowClassName());
		m_propertyEditor->updateAttrs(winAttrDefValues);
		// ���ö�Ӧ���ڵ��޸ĵ�����ֵ
		m_propertyEditor->updateAttrs(newCurWnd->getWinAttrs());
		// �޸Ķ���鿴�е�ǰѡ����

	}
}