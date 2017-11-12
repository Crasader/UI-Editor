#include "EditorManageWindow.h"
#include "../DrawEngine/DrawControlManager.h"

EditorManageWindow::EditorManageWindow(int relX, int relY, int width, int height)
	: inner::ContainerWindow<inner::EditorContainerFunc>(nullptr, relX, relY, width, height)
{
	
}

EditorManageWindow::~EditorManageWindow()
{
}


//�ڱ༭�����ϻ���
void EditorManageWindow::editDraw(int absX, int absY, DrawControlManager* drawManager)
{
	drawManager->drawWindow(this, absX, absY);
}