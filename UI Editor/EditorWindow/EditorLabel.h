#ifndef EDITOR_LABEL_H
#define EDITOR_LABEL_H

/*
 * �ļ�����EditorLabel
 * ���ã���SimpleLabel�Ļ����ϣ�ʵ�����ڱ༭����ع���
 */

#include "SimpleLabel.h"
#include "EditorFunc.h"
#include "WindowInterface.h"


//using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;


namespace inner
{
	class EditorLabel : public SimpleLabel<EditorFunc>
	{
	public:
		EditorLabel(AbstractEditorWindow* parent, int relX, int relY, int width, int height);
		virtual ~EditorLabel();

		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		SimpleLabel<EditorFunc>* getConstructWindow() override { return this;  }

		// ���´��ڶ���������Ϣ
		void updateWinAttr(const wxString& attrName, const wxAny& value) override;

	protected:
		// ��ȡ���������Դ�����Map
		static const ATTR_HANDLE_MAP& getEditorAttrHandles();

	private:
		// ��ʼ�����Դ�����Map
		static ATTR_HANDLE_MAP initEditorAttrHanldes();
	};
}

#endif	// EDITOR_LABEL_H