#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

/*
 * �ļ�����ChangeManager
 * ���ã���1����¼Ŀ��͹۲��ߵ�ӳ���ϵ
 *		 ��2�������ض��ĸ��²���
 *		 ��3����Ŀ��ı�ʱ������������֮��صĹ۲���
 */

#include <memory>
#include "CommandStack.h"
#include "../EditorWindow/EditorWindowInterface.h"

class EditorWorkArea;
class EditorToolPropertyEditor;
class EditorToolObjectView;
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
		// ���һ������
		bool pushBackWindow(EditorAbstractWindow* parentWnd, EditorAbstractWindow* insertWnd);
		// ����һ������
		bool insertWindow(EditorAbstractWindow* parentWnd, size_t idx, EditorAbstractWindow* insertWnd);
		// �Ƴ�һ������
		bool removeWindow(EditorAbstractWindow* removeWnd);
		// �޸ĵ�ǰѡ�еĴ���
		void changeSelectWnd(EditorAbstractWindow* lastCurWnd, EditorAbstractWindow* newCurWnd);
		// �޸ĵ�ǰѡ�еĴ������ԣ���ԭ���Ա��浽����Ĳ�����
		void changeSelectWndAttr(const wxString& attrName, wxAny& toSetValue);

		// �������������͹��ߴ���
		void setWorkArea(std::shared_ptr<EditorWorkArea> workArea) { m_workArea = workArea; }
		void setPropertyEditor(std::shared_ptr<EditorToolPropertyEditor> propertyEditor) { m_propertyEditor = propertyEditor; }
		void setObjectView(std::shared_ptr<EditorToolObjectView> objectView) { m_objectView = objectView; }
		void setWindowAttrMgr(std::shared_ptr<WindowAttributeManager> winAttrMgr) { m_winAttrMgr = winAttrMgr; }
		// ��ȡ���������͹��ߴ���
		std::shared_ptr<EditorWorkArea> getWorkArea() const { return m_workArea; }
		std::shared_ptr<EditorToolPropertyEditor> getPropertyEditor() const { return m_propertyEditor; }
		std::shared_ptr<EditorToolObjectView> getObjectView() const { return m_objectView; }

	private:
		static ChangeManager* s_changeManager;
	private:
		std::shared_ptr<EditorWorkArea> m_workArea;
		std::shared_ptr<EditorToolPropertyEditor> m_propertyEditor;
		std::shared_ptr<EditorToolObjectView> m_objectView;
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
