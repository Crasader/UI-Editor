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
		// �޸Ķ���鿴��
		if (flag)
		{
			flag = m_objectView->addWindowItem(parentWnd->getId(), insertWnd->getId(),
				insertWnd->getWinAttr(OBJECT_NAME).As<wxString>(), insertWnd->getWindowClassName());
		}

		return flag;
	}

	// ����һ���ؼ�
	bool ChangeManager::insertWindow(EditorAbstractWindow * parentWnd, size_t idx, EditorAbstractWindow * insertWnd)
	{
		// �޸���������
		bool flag = m_workArea->insertWindow(parentWnd, idx, insertWnd);
		// �޸Ķ���鿴��
		if (flag)
		{

		}
		return flag;
	}

	// �Ƴ�һ���ؼ�
	bool ChangeManager::removeWindow(EditorAbstractWindow * removeWnd)
	{
		// �޸���������
		bool flag = m_workArea->removeWindow(removeWnd);
		// �޸Ķ���鿴��
		if (flag)
		{
			flag = m_objectView->delWindowItem(removeWnd->getId());
		}
		return flag;
	}

	// �޸ĵ�ǰ�༭�Ŀؼ�����֮ǰ�ı༭�ؼ����浽������
	bool ChangeManager::changeCurrentWnd(EditorAbstractWindow* &toSetCurWnd)
	{
		auto newCurWnd = toSetCurWnd;
		toSetCurWnd = m_workArea->getCurrentWindow();
		// �ж��Ƿ���ͬ
		if (newCurWnd == toSetCurWnd)
		{
			return false;
		}
		// �޸���������
		m_workArea->setCurrentWindow(newCurWnd);
		// �����Ա༭���Ͷ���鿴���޸�
		changeCurrentWndImpl(newCurWnd);

		return true;
	}

	// �޸ĵ�ǰ�༭�Ŀؼ�����֮ǰ�ı༭�ؼ�ID���浽������
	bool ChangeManager::changeCurrentWnd(ID_TYPE &toSetCurWndId)
	{
		auto newCurWndId = toSetCurWndId;
		toSetCurWndId = m_workArea->getCurrentWindowId();
		// �ж��Ƿ���ͬ
		if (newCurWndId == toSetCurWndId)
		{
			return false;
		}
		// �޸���������
		m_workArea->setCurrentWindowId(newCurWndId);
		// ��������������Ĺ����������޸�
		changeCurrentWndImpl(m_workArea->getCurrentWindow());

		return true;
	}

	// �޸ĵ�ǰ�༭�Ŀؼ����ԣ���ԭ���Ա��浽����Ĳ�����
	void ChangeManager::changeSelectWndAttr(const wxString& attrName, wxAny& toSetValue)
	{
		auto curSelectWnd = m_workArea->getCurrentWindow();
		auto origValue = curSelectWnd->getWinAttr(attrName);
		// ���������û������
		if (origValue.IsNull())
		{
			// ����ڴ��������в����ڣ���ʹ��Ĭ������
			auto attrValues = WindowAttributeManager::instance()->getWinDefValues(curSelectWnd->getWindowClassName());
			
			auto it = attrValues.find(attrName);
			if (it == attrValues.cend())
			{
				// �����߼���Ӧ�ó��ֵ����
				throw ExtraExcept::unexpected_situation("ChangeManager::changeSelectWndAttr can't find " + attrName.ToStdString());
			}
			else
			{
				origValue = it->second;
			}
		}
		// �����ﲻ�ж��¾�ֵ�Ƿ���ͬ����Ϊ�༭�������Ѿ��ж�
		curSelectWnd->updateWinAttr(attrName, toSetValue);
		// �޸Ķ���鿴������ʾ
		m_objectView->changeWinAttr(curSelectWnd->getId(), attrName, toSetValue);
		// ��֮ǰ��ֵ���Ƹ�
		toSetValue = origValue;
	}

	// �޸ĵ�ǰѡ�еĿؼ�����ԭ��ѡ�е����пؼ�ID����
	bool ChangeManager::changeSelectWnds(std::unordered_set<ID_TYPE>& toSelectIds)
	{
		// �޸������������޸���֮��toSelectIdsָ�����֮ǰѡ�е����пؼ�ID
		using std::swap;
		swap(toSelectIds, m_workArea->getSelectWndIds());
		// �޸Ķ���鿴�е�ѡ����
		m_objectView->setSelections(m_workArea->getSelectWndIds());

		return true;
	}

	// �޸ĵ�ǰ�༭����ʱ����������������Ĺ����������޸�
	void ChangeManager::changeCurrentWndImpl(EditorAbstractWindow * toSetCurWnd)
	{
		// ��ʾ��Ӧ���͵����Ա༭��
		if (!toSetCurWnd->isAttrEditable())
		{
			m_propertyEditor->clearAttrs();
		}
		else
		{
			m_propertyEditor->resetAttrs(toSetCurWnd->getWindowClassName());

			const auto& winAttrDefValues = WindowAttributeManager::instance()->getWinDefValues(toSetCurWnd->getWindowClassName());
			const auto& curAttrValues = toSetCurWnd->getWinAttrs();
			// �����ö�Ӧ�ؼ����Ե�Ĭ��ֵ
			if (winAttrDefValues.size() != curAttrValues.size())
			{
				m_propertyEditor->updateAttrs(winAttrDefValues);
			}
			// ���ö�Ӧ�ؼ����޸ĵ�����ֵ
			m_propertyEditor->updateAttrs(curAttrValues);
		}
	}
}