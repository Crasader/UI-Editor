#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

/*
 * �ļ�����DrawManager
 * ���ã��������ӻ��ƹ��ܺʹ��ڶ���ʵ�ִ��ڶ���Ļ���
 */

#include <memory>
#include "../EditorWindow/EditorWindowInterface.h"
#include "AbstractEngine.h"

class StaticControl;
class ButtonControl;

class DrawManager
{
public:
	DrawManager();
	~DrawManager();

private:
	// ��ʼ�������õ�Engine
	void initEngine();
	// ��ʼ�����ֻ����õĿؼ�
	void initControls();
private:
	// �����õ�Engine
	std::unique_ptr<AbstractEngine> m_engine;
	// �����õĸ��ֿؼ�
	std::unique_ptr<StaticControl> m_staticControl;
	std::unique_ptr<ButtonControl> m_buttonControl;
};

#endif	// DRAW_MANAGER_H
