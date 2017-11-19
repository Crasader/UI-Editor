#include "ChangeManager.h"
#include "WinAttrAndNameProtocol.h"
#include "../Form/FormWorkArea.h"
#include "../Form/FormObjectView.h"
#include "../Form/FormPropertyEditor.h"
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

	// ���һ���ؼ�
	bool ChangeManager::pushBackWindow(EditorAbstractWindow * parentWnd, EditorAbstractWindow * insertWnd)
	{
		// �޸���������
		bool flag = m_workArea->pushBackWindow(parentWnd, insertWnd);
		flag = flag && m_objectView->addWindowItem(parentWnd->getId(), insertWnd->getId(),
			insertWnd->getWinAttr(OBJECT_NAME).As<wxString>(), insertWnd->getWindowClassName());
		return flag;
	}

	// ����һ���ؼ�
	bool ChangeManager::insertWindow(EditorAbstractWindow * parentWnd, size_t idx, EditorAbstractWindow * insertWnd)
	{
		// �޸���������
		bool flag = m_workArea->insertWindow(parentWnd, idx, insertWnd);
		return flag;
	}

	// �Ƴ�һ���ؼ�
	bool ChangeManager::removeWindow(EditorAbstractWindow * removeWnd)
	{
		// �޸���������
		bool flag = m_workArea->removeWindow(removeWnd);
		return flag;
	}

	// �޸ĵ�ǰѡ�еĿؼ�
	void ChangeManager::changeSelectWnd(EditorAbstractWindow * lastCurWnd, EditorAbstractWindow * newCurWnd)
	{
		// �޸���������
		m_workArea->setCurrentWindow(newCurWnd);
		// ��ʾ��Ӧ���͵����Ա༭��
		m_propertyEditor->resetAttrs(newCurWnd->getWindowClassName());
		// �����ö�Ӧ�ؼ����Ե�Ĭ��ֵ
		const auto& winAttrDefValues = m_winAttrMgr->getWinDefValues(newCurWnd->getWindowClassName());
		m_propertyEditor->updateAttrs(winAttrDefValues);
		// ���ö�Ӧ�ؼ����޸ĵ�����ֵ
		m_propertyEditor->updateAttrs(newCurWnd->getWinAttrs());
		// �޸Ķ���鿴�е�ǰѡ����
		m_objectView->setCurSelect(newCurWnd->getId());
	}

	// �޸ĵ�ǰѡ�еĿؼ����ԣ���ԭ���Ա��浽����Ĳ�����
	void ChangeManager::changeSelectWndAttr(const wxString& attrName, wxAny& toSetValue)
	{
		auto curSelectWnd = m_workArea->getCurrentWindow();
		wxAny origValue = curSelectWnd->getWinAttr(attrName);
		// �����ﲻ�ж��¾�ֵ�Ƿ���ͬ����Ϊ�༭�������Ѿ��ж�
		curSelectWnd->updateWinAttr(attrName, toSetValue);
		// �޸Ķ���鿴������ʾ
		m_objectView->changeWinAttr(curSelectWnd->getId(), attrName, toSetValue);
		// ��֮ǰ��ֵ���Ƹ�
		toSetValue = origValue;
	}
}