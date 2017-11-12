#ifndef EDITOR_BUTTON_H
#define EDITOR_BUTTON_H

/*
 * �ļ�����EditorButton
 * ���ã���SimpleButton�Ļ����ϣ�ʵ�����ڱ༭����ع���
 * ���ú����޸ĸö�������ԣ������ͬʱ�޸������б��е�ֵ����Ҫʹ��updateWinAttr����
 */

#include "SimpleWindow/SimpleButton.h"
#include "EditorWindowInterface.h"


class EditorButton : public inner::SimpleButton<inner::EditorEditableFunc>
{
public:
	EditorButton(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
	~EditorButton() override;

	// ������ȡ����������
	virtual wxString getWindowClassName() const { return EDITOR_BUTTON_TYPE; }
	// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
	EditorButton* getConstructWindow() override { return this; }

	// ���´��ڶ���������Ϣ
	void updateWinAttr(const wxString& attrName, const wxAny& value) override;

	// ��ȡ�����Ƿ��ڰ���״̬
	bool isPressed() const { return m_state == EDITOR_STATE_PRESSED; }
	// ��ȡ����Ƿ��ڴ�����
	bool isMouseOver() const { return m_state == EDITOR_STATE_MOUSE_OVER; }

	//�ڱ༭�����ϻ���
	void editDraw(int absX, int absY, DrawControlManager* drawManager) override;

protected:
	// ���崦����Ϣ�����ͣ�����ֵ��ʾ�Ƿ��޸������ԣ�true��ʾ�޸ģ�false��ʾδ�޸�
	using CHANGE_ATTR_FUNC = std::function<bool(EditorButton*, const wxAny&)>;
	using ATTR_HANDLE_MAP = std::map<const wxString, CHANGE_ATTR_FUNC>;
	// ��ȡ���������Դ�����Map
	static const ATTR_HANDLE_MAP& getEditorAttrHandles();

private:
	// ��ʼ�����Դ�����Map
	static ATTR_HANDLE_MAP initEditorAttrHanldes();

	// ��¼���ڵ����״̬
	EDITOR_WINDOW_STATE m_state;
};

#endif	// EDITOR_BUTTON_H
