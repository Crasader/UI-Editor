#include "DrawControlManager.h"
#include "d3dEngine/d3dEngine.h"
#include "Controls/StaticControl.h"
#include "Controls/ButtonControl.h"

#include "../EditorWindow/EditorManageWindow.h"
#include "../EditorWindow/EditorLabel.h"
#include "../EditorWindow/EditorButton.h"

const D3DCOLOR MANAGER_ENABLE_COLOR = D3DCOLOR_RGBA(0, 255, 0, 255);

DrawControlManager::DrawControlManager(HWND mainWndId)
{
	initEngine(mainWndId);
	initControls();
}

DrawControlManager::~DrawControlManager()
{

}

// ���ƿؼ�֮ǰ׼��
void DrawControlManager::drawWindowsBefore()
{
	m_engine->RenderControlsBefore();
}

// ���ƿؼ�֮����
void DrawControlManager::drawWindowsAfter()
{
	m_engine->RenderControlsEnd();
}

// ���ƹ���ؼ�����
void DrawControlManager::drawWindow(const EditorManageWindow* manageWindow, int absX, int absY)
{
	int width = manageWindow->getWidth();
	int height = manageWindow->getHeight();
	RECT drawRegion = { absX, absY, absX + width, absY + height };
	
	m_engine->DrawRectLine(&drawRegion, MANAGER_ENABLE_COLOR);
}

// ����Static����
void DrawControlManager::drawWindow(const EditorLabel* label, int absX, int absY)
{
	resetControl(label, m_staticControl.get(), absX, absY);
	// ���Ƹÿؼ�
	m_staticControl->Render(m_engine.get(), m_elapsedTime);
}

// ����Button����
void DrawControlManager::drawWindow(const EditorButton* button, int absX, int absY)
{
	resetControl(button, m_buttonControl.get(), absX, absY);
	m_buttonControl->SetPressed(button->isPressed());
	m_buttonControl->SetMouseOver(button->isMouseOver());
	// ���Ƹÿؼ�
	m_buttonControl->Render(m_engine.get(), m_elapsedTime);
}

// ��ʼ�������õ�Engine
void DrawControlManager::initEngine(HWND mainWndId)
{
	m_engine.reset(new D3DEngine(mainWndId, D3DDEVTYPE_HAL, D3DCREATE_HARDWARE_VERTEXPROCESSING));
}

// ��ʼ�����ֻ����õĿؼ�
void DrawControlManager::initControls()
{
	m_staticControl.reset(new StaticControl());
	m_engine->InitControl(m_staticControl.get());
	m_buttonControl.reset(new ButtonControl());
	m_engine->InitControl(m_buttonControl.get());
}
