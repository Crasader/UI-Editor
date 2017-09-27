#ifndef EDITOR_BUTTON_H
#define EDITOR_BUTTON_H

/*
* �ļ�����EditorButton
* ���ã���SimpleButton�Ļ����ϣ�ʵ�����ڱ༭����ع���
*/

#include "SimpleButton.h"
#include "EditorFunc.h"
#include "WindowInterface.h"

namespace inner
{
	class EditorButton : public SimpleButton<EditorFunc>
	{
	public:
		EditorButton(AbstractEditorWindow* parent, int relX, int relY, int width, int height);
		~EditorButton() override;

		// ������ȡ����������
		virtual wxString getWindowClassName() const { return wxS("EditorButton"); }
		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		SimpleButton<EditorFunc>* getConstructWindow() override { return this; }

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

#endif	// EDITOR_BUTTON_H
