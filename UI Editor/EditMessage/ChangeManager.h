#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

/*
 * 文件名：ChangeManager
 * 作用：（1）记录目标和观察者的映射关系
 *		 （2）定义特定的更新策略
 *		 （3）在目标改变时，更新所有与之相关的观察者
 */

#include <memory>
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

		// 创建改变管理对象
		static ChangeManager * const createInstance();
		// 用来获取改变管理对象
		static ChangeManager * const instance() { return s_changeManager; }

		// 用来获取命令列表
		wxCommandProcessor& getCommandStack() { return m_commandStack; }
		const wxCommandProcessor& getCommandStack() const { return m_commandStack; }
		// 用来查看命令列表
		const wxCommandProcessor& checkCommandStack() const { return m_commandStack; }
		// 添加一个控件
		bool pushBackWindow(EditorAbstractWindow* parentWnd, EditorAbstractWindow* insertWnd);
		// 插入一个控件
		bool insertWindow(EditorAbstractWindow* parentWnd, size_t idx, EditorAbstractWindow* insertWnd);
		// 移除一个控件
		bool removeWindow(EditorAbstractWindow* removeWnd);
		// 修改当前选中的控件
		void changeSelectWnd(EditorAbstractWindow* lastCurWnd, EditorAbstractWindow* newCurWnd);
		// 修改当前选中的控件属性，将原属性保存到传入的参数中
		void changeSelectWndAttr(const wxString& attrName, wxAny& toSetValue);

		// 设置主工作区和功能区
		void setWorkArea(std::shared_ptr<FormWorkArea> workArea) { m_workArea = workArea; }
		void setPropertyEditor(std::shared_ptr<FormPropertyEditor> propertyEditor) { m_propertyEditor = propertyEditor; }
		void setObjectView(std::shared_ptr<FormObjectView> objectView) { m_objectView = objectView; }
		void setWindowAttrMgr(std::shared_ptr<WindowAttributeManager> winAttrMgr) { m_winAttrMgr = winAttrMgr; }
		// 获取主工作区和功能区
		std::shared_ptr<FormWorkArea> getWorkArea() const { return m_workArea; }
		std::shared_ptr<FormPropertyEditor> getPropertyEditor() const { return m_propertyEditor; }
		std::shared_ptr<FormObjectView> getObjectView() const { return m_objectView; }

	private:
		static ChangeManager* s_changeManager;
	private:
		std::shared_ptr<FormWorkArea> m_workArea;
		std::shared_ptr<FormPropertyEditor> m_propertyEditor;
		std::shared_ptr<FormObjectView> m_objectView;
		// 属性列表
		std::shared_ptr<WindowAttributeManager> m_winAttrMgr;

		// 用来存储命令列表
		CommandStack m_commandStack;
	};

	// 创建改变管理对象
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
