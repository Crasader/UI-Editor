#ifndef EDITOR_FUNC_H
#define EDITOR_FUNC_H

/*
 * �ļ�����EditorFunc
 * ���ã�����ʵ�ִ��ڱ༭��صĹ���
 */

#include <map>
#include <utility>
#include <wx/string.h>

namespace inner
{
	template <typename T>
	class SimpleWindow;
}

class Visitor;

namespace inner
{
	class EditorFunc
	{
	public:
		EditorFunc();
		virtual ~EditorFunc();

		// ���ô����ڱ༭ʱ�Ƿ���ʾ
		void setEditShow(bool editShow) { m_editShow = editShow; }

		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		virtual SimpleWindow<EditorFunc>* getConstructWindow() = 0;

		// ���´��ڶ�����Ϣ
		template <typename ...Args>
		void updateAttr(Visitor* visitor, const wxString& attrName, Args&&... args);

	private:
		// �ڱ༭ʱ���ô����Ƿ���ʾ
		bool m_editShow;
		// ������¼���ڵĶ�������
		std::map<wxString, wxString> m_extraAttrs;
	};


	// ���´��ڶ�����Ϣ
	template <typename ...Args>
	void EditorFunc::updateAttr(Visitor* visitor, const wxString& attrName, Args&&... args)
	{
		visitor->updateAttr(getConstructWindow(), attrName, std::forward<Args>(args)...);
	}
}

#endif	// EDITOR_FUNC_H
