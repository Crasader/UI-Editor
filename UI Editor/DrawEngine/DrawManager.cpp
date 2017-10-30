#include "DrawManager.h"
#include "d3dEngine/d3dEngine.h"
#include "Controls/StaticControl.h"
#include "Controls/ButtonControl.h"

DrawManager::DrawManager()
{
	initControls();
}

DrawManager::~DrawManager()
{

}

// ��ʼ�������õ�Engine
void DrawManager::initEngine()
{
	
}

// ��ʼ�����ֻ����õĿؼ�
void DrawManager::initControls()
{
	m_staticControl.reset(new StaticControl());
	m_buttonControl.reset(new ButtonControl());
}
