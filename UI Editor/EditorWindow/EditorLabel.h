#ifndef EDITOR_LABEL_H
#define EDITOR_LABEL_H

/*
 * �ļ�����EditorLabel
 * ���ã���SimpleLabel�Ļ����ϣ�ʵ�����ڱ༭����ع���
 */

#include "SimpleWindow/SimpleLabel.h"
#include "WindowInterface.h"


//using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;


namespace inner
{
	class EditorLabel : public SimpleLabel<EditorEditableFunc>
	{
	public:
		EditorLabel(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		virtual ~EditorLabel();

		// ������ȡ����������
		virtual wxString getWindowClassName() const { return wxS("EditorLabel"); }
		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		SimpleLabel<EditorEditableFunc>* getConstructWindow() override { return this;  }

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