#ifndef EDITOR_BUTTON_H
#define EDITOR_BUTTON_H

/*
* �ļ�����EditorButton
* ���ã���SimpleButton�Ļ����ϣ�ʵ�����ڱ༭����ع���
*/

#include "SimpleWindow/SimpleButton.h"
#include "WindowInterface.h"

namespace inner
{
	class EditorButton : public SimpleButton<EditorEditableFunc>
	{
	public:
		EditorButton(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		~EditorButton() override;

		// ������ȡ����������
		virtual wxString getWindowClassName() const { return EDITOR_BUTTON_TYPE; }
		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		SimpleButton<EditorEditableFunc>* getConstructWindow() override { return this; }

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
