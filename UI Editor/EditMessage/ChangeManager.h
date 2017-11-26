#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

/*
 * �ļ�����ChangeManager
 * ���ã���1����¼Ŀ��͹۲��ߵ�ӳ���ϵ
 *		 ��2�������ض��ĸ��²���
 *		 ��3����Ŀ��ı�ʱ������������֮��صĹ۲���
 */

#include <memory>
#include <unordered_set>
#include "CommandStack.h"
#include "../EditorWindow/EditorWindowInterface.h"

class FormWorkArea;
class FormPropertyEditor;
class FormObjectView;
class WindowAttributeManager;

namespace Command
{
	class ChangeManager
	{
	public:
		ChangeManager();
		~ChangeManager();

		// �����ı�������
		static ChangeManager * const createInstance();
		// ������ȡ�ı�������
		static ChangeManager * const instance() { return s_changeManager; }

		// ������ȡ�����б�
		wxCommandProcessor& getCommandStack() { return m_commandStack; }
		const wxCommandProcessor& getCommandStack() const { return m_commandStack; }
		// �����鿴�����б�
		const wxCommandProcessor& checkCommandStack() const { return m_commandStack; }
		// ���һ���ؼ�
		bool pushBackWindow(EditorAbstractWindow* parentWnd, EditorAbstractWindow* insertWnd);
		// ����һ���ؼ�
		bool insertWindow(EditorAbstractWindow* parentWnd, size_t idx, EditorAbstractWindow* insertWnd);
		// �Ƴ�һ���ؼ�
		bool removeWindow(EditorAbstractWindow* removeWnd);
		// �޸ĵ�ǰ�༭�Ŀؼ�����֮ǰ�ı༭�ؼ����浽������
		bool changeCurrentWnd(EditorAbstractWindow* &toSetCurWnd);
		// �޸ĵ�ǰ�༭�Ŀؼ�����֮ǰ�ı༭�ؼ�ID���浽������
		bool changeCurrentWnd(ID_TYPE& toSetCurWndId);
		// �޸ĵ�ǰ�༭�Ŀؼ����ԣ���ԭ���Ա��浽����Ĳ�����
		void changeSelectWndAttr(const wxString& attrName, wxAny& toSetValue);
		// �޸ĵ�ǰѡ�еĿؼ�����ԭ��ѡ�е����пؼ�ID����
		bool changeSelectWnds(std::unordered_set<ID_TYPE>& toSelectIds);

		// �������������͹�����
		void setWorkArea(std::shared_ptr<FormWorkArea> workArea) { m_workArea = workArea; }
		void setPropertyEditor(std::shared_ptr<FormPropertyEditor> propertyEditor) { m_propertyEditor = propertyEditor; }
		void setObjectView(std::shared_ptr<FormObjectView> objectView) { m_objectView = objectView; }
		void setWindowAttrMgr(std::shared_ptr<WindowAttributeManager> winAttrMgr) { m_winAttrMgr = winAttrMgr; }
		// ��ȡ���������͹�����
		std::shared_ptr<FormWorkArea> getWorkArea() const { return m_workArea; }
		std::shared_ptr<FormPropertyEditor> getPropertyEditor() const { return m_propertyEditor; }
		std::shared_ptr<FormObjectView> getObjectView() const { return m_objectView; }

	private:
		// �޸ĵ�ǰ�༭����ʱ����������������Ĺ����������޸�
		void changeCurrentWndImpl(EditorAbstractWindow* toSetCurWnd);

	private:
		static ChangeManager* s_changeManager;
	private:
		std::shared_ptr<FormWorkArea> m_workArea;
		std::shared_ptr<FormPropertyEditor> m_propertyEditor;
		std::shared_ptr<FormObjectView> m_objectView;
		// �����б�
		std::shared_ptr<WindowAttributeManager> m_winAttrMgr;

		// �����洢�����б�
		CommandStack m_commandStack;
	};

	// �����ı�������
	inline ChangeManager * const ChangeManager::createInstance()
	{
		if (s_changeManager == nullptr)
		{
			s_changeManager = new ChangeManager;
		}

		return s_changeManager;
	}
}


#endif		// CHANGE_MANAGER_H
