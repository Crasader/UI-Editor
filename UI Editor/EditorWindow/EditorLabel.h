#ifndef EDITOR_LABEL_H
#define EDITOR_LABEL_H

/*
 * �ļ�����EditorLabel
 * ���ã���SimpleLabel�Ļ����ϣ�ʵ�����ڱ༭����ع���
 * ���ú����޸ĸö�������ԣ������ͬʱ�޸������б��е�ֵ����Ҫʹ��updateWinAttr����
 */

#include "SimpleWindow/SimpleLabel.h"
#include "EditorWindowInterface.h"


//using EditorLabel = inner::SimpleLabel<inner::EditorFunc>;


class EditorLabel : public inner::SimpleLabel<inner::EditorEditableFunc>
{
public:
	EditorLabel(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
	virtual ~EditorLabel();

	// ������ȡ����������
	wxString getWindowClassName() const override { return EDITOR_LABEL_TYPE; }
	// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
	EditorLabel* getConstructWindow() override { return this; }

	// ���´��ڶ���������Ϣ
	void updateWinAttr(const wxString& attrName, const wxAny& value) override;

	//�ڱ༭�����ϻ���
	void editDraw(int absX, int absY, DrawControlManager* drawManager) override;

protected:
	// ���崦����Ϣ�����ͣ�����ֵ��ʾ�Ƿ��޸������ԣ�true��ʾ�޸ģ�false��ʾδ�޸�
	using CHANGE_ATTR_FUNC = std::function<bool(EditorLabel*, const wxAny&)>;
	using ATTR_HANDLE_MAP = std::map<const wxString, CHANGE_ATTR_FUNC>;
	// ��ȡ���������Դ�����Map
	static const ATTR_HANDLE_MAP& getEditorAttrHandles();
	// �޸���ʾ���ֵĺ���
	bool ChangeText(const wxAny& value);

private:
	// ��ʼ�����Դ�����Map
	static ATTR_HANDLE_MAP initEditorAttrHanldes();
};

#endif	// EDITOR_LABEL_H