#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

/*
 * �ļ�����ChangeManager
 * ���ã���1����¼Ŀ��͹۲��ߵ�ӳ���ϵ
 *		 ��2�������ض��ĸ��²���
 *		 ��3����Ŀ��ı�ʱ������������֮��صĹ۲���
 */

#include <memory>

class EditorWorkArea;
class EditorToolPropertyEditor;
class EditorToolObjectView;

namespace Command
{
	class ChangeManager
	{
	public:
		ChangeManager() {}
		~ChangeManager() {}

		// �������������͹��ߴ���
		void setWorkArea(std::shared_ptr<EditorWorkArea> workArea) { m_workArea = workArea; }
		void setPropertyEditor(std::shared_ptr<EditorToolPropertyEditor> propertyEditor) { m_propertyEditor = propertyEditor; }
		void setObjectView(std::shared_ptr<EditorToolObjectView> objectView) { m_objectView = objectView; }
		// ��ȡ���������͹��ߴ���
		std::shared_ptr<EditorWorkArea> getWorkArea() const { return m_workArea; }
		std::shared_ptr<EditorToolPropertyEditor> getPropertyEditor() const { return m_propertyEditor; }
		std::shared_ptr<EditorToolObjectView> getObjectView() const { return m_objectView; }

	private:
		std::shared_ptr<EditorWorkArea> m_workArea;
		std::shared_ptr<EditorToolPropertyEditor> m_propertyEditor;
		std::shared_ptr<EditorToolObjectView> m_objectView;
	};
}


#endif		// CHANGE_MANAGER_H
