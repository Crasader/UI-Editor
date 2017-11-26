#ifndef EDITOR_MANAGE_WINDOW_H
#define EDITOR_MANAGE_WINDOW_H

/*
 * �ļ�����EditorManageWindow
 * ���ã�����FormWorkArea�ϣ���Ϊ���ϲ�Ŀؼ��������򻯴���
 */


#include "SimpleWindow/ContainerWindow.h"
#include "EditorWindowInterface.h"

class EditorManageWindow : public inner::ContainerWindow<inner::EditorContainerFunc>
{
public:
	EditorManageWindow(int relX, int relY, int width, int height);
	~EditorManageWindow();

	// ���������Ƿ���Ա༭
	bool isAttrEditable() override { return false; }
	// ������ȡ�����Ŀؼ����ͣ��̳еĿؼ���������
	EditorManageWindow* getConstructWindow() override { return this; }
	// ��ȡ��Ϣ����ķ�Χ����ȡ�������õķ�Χ�������÷�Χ����Ϣ��������Է�Χ��������Լ�
	wxRegion getMsgRegion() const override;
	// ���ÿؼ��ڱ༭ʱ�Ƿ���ʾ
	void setEditShow(bool editShow) override { EditorFunc::setEditShow(editShow); }

	// ������ȡ�ؼ�������
	virtual wxString getWindowClassName() const { return wxS("EditorManageWindow"); }

	//�ڱ༭�����ϻ���
	void editDraw(int absX, int absY, DrawControlManager* drawManager) override;

protected:
	// ���¸ÿؼ��ж���Ϣ�ķ�Χ����childRect����Ϣ����Χ��ӵ��ÿؼ���
	void incrMsgRegion(const wxRegion& childRange) override {}
	// ���ÿؼ���Ϣ��ΧΪ�����ӿؼ���Χ�������ӿؼ������仯������ı�
	void resetMsgRegion() override {}

	// �ÿؼ��Ƿ���ؼ���Ϣ
	bool isHandleMsg() const override { return true; }
};

// ��ȡ��Ϣ����ķ�Χ����Է�Χ��������Լ�
inline wxRegion EditorManageWindow::getMsgRegion() const
{
	return wxRegion(narrow_cast<wxCoord>(getRelX()), narrow_cast<wxCoord>(getRelY()),
		narrow_cast<wxCoord>(getWidth()), narrow_cast<wxCoord>(getHeight()));
}

#endif	// EDITOR_MANAGE_WINDOW_H
