#ifndef EDITOR_FRAME_H
#define EDITOR_FRAME_H

/*
 * �ļ�����EditorFrame
 * ���ã�����ʵ��һ���򵥵Ŀؼ��������ÿؼ�������������ؼ���ͬʱ��ʾ���ؼ�������Χ
 */

#include "EditorContainerWindow.h"

class EditorFrame : public inner::ContainerWindow<inner::EditorContainerFunc>
{
public:
	using ContainerWindow<inner::EditorContainerFunc>::ContainerWindow;
	~EditorFrame() override {}

	// ������ȡ�ؼ�������
	wxString getWindowClassName() const override { return EDITOR_FRAME_TYPE; }
	// ������ȡ�����Ŀؼ����ͣ��̳еĿؼ���������
	EditorFrame* getConstructWindow() override { return this; }

	// ���¿ؼ�����������Ϣ
	void updateWinAttr(const wxString& attrName, const wxAny& value) override;

	//�ڱ༭�����ϻ���
	void editDraw(int absX, int absY, DrawControlManager* drawManager) override;

protected:
	// ���崦����Ϣ�����ͣ�����ֵ��ʾ�Ƿ��޸������ԣ�true��ʾ�޸ģ�false��ʾδ�޸�
	using CHANGE_ATTR_FUNC = std::function<bool(EditorFrame*, const wxAny&)>;
	using ATTR_HANDLE_MAP = std::map<const wxString, CHANGE_ATTR_FUNC>;
	// ��ȡ���������Դ�����Map
	static const ATTR_HANDLE_MAP& getEditorAttrHandles();
private:
	// ��ʼ�����Դ�����Map
	static ATTR_HANDLE_MAP initEditorAttrHanldes();
};

#endif	// EDITOR_FRAME_H
