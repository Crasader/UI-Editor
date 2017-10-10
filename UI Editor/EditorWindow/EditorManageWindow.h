#ifndef EDITOR_MANAGE_WINDOW_H
#define EDITOR_MANAGE_WINDOW_H

/*
 * �ļ�����EditorManageWindow
 * ���ã�����EditorWorkArea�ϣ���Ϊ���ϲ�Ĵ��ڣ������򻯴���
 */

#include "WindowInterface.h"
#include "SimpleWindow/ContainerWindow.h"

class EditorManageWindow : public inner::ContainerWindow<inner::EditorContainerFunc>
{
public:
	EditorManageWindow(int relX, int relY, int width, int height);
	~EditorManageWindow();

	// ���������Ƿ���Ա༭
	bool isAttrEditable() override { return false; }
	// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
	virtual SimpleWindow<EditorFunc>* getConstructWindow() { return this; }
	// ��ȡ��Ϣ����ķ�Χ����ȡ�������õķ�Χ�������÷�Χ����Ϣ������
	wxRegion getMsgRegion() const override;
	// ���ô����ڱ༭ʱ�Ƿ���ʾ
	void setEditShow(bool editShow) override { EditorFunc::setEditShow(editShow); }

	// ������ȡ����������
	virtual wxString getWindowClassName() const { return wxS("EditorManageWindow"); }

	// �ڽ����ϻ���
	void draw() override {}

protected:
	// ���¸ô����ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ô�����
	void incrMsgRegion(const wxRegion& childRange) override {}
	// ���ô�����Ϣ��ΧΪ�����Ӵ��ڷ�Χ�������Ӵ��ڷ����仯������ı�
	void resetMsgRegion() override {}

	// �ô����Ƿ�������Ϣ
	bool isHandleMsg() const override { return true; }
};

// ��ȡ��Ϣ����ķ�Χ
inline wxRegion EditorManageWindow::getMsgRegion() const
{
	return wxRegion(narrow_cast<wxCoord>(getRelX()), narrow_cast<wxCoord>(getRelY()),
		narrow_cast<wxCoord>(getWidth()), narrow_cast<wxCoord>(getHeight()));
}

#endif	// EDITOR_MANAGE_WINDOW_H
