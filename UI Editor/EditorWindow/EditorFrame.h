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

	// ���ػ��ƺ���
	void draw(int x, int y) const override {}
};

#endif	// EDITOR_FRAME_H
