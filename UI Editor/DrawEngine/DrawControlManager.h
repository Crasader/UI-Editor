#ifndef DRAW_CONTROL_MANAGER_H
#define DRAW_CONTROL_MANAGER_H

/*
 * �ļ�����DrawManager
 * ���ã�������������Control��������Control�������������н��пؼ�����Ⱦ
 */

#include <memory>
#include "UiEditorProtocol.h"
#include "../EditorWindow/EditorWindowInterface.h"
#include "AbstractEngine.h"

class StaticControl;
class ButtonControl;

class EditorManageWindow;
class EditorLabel;
class EditorButton;

class DrawControlManager
{
public:
	DrawControlManager(HWND mainWndId);
	~DrawControlManager();

	// ����ʱ����
	void setElapsedTime(float elapsedTime) { m_elapsedTime = elapsedTime; }

	// ���ƿؼ�֮ǰ׼��
	void drawWindowsBefore();
	// ���ƿؼ�֮����
	void drawWindowsAfter();
	// ÿ֡��⣬���Ϊtrue����˵�����ͨ��
	bool checkEveryFrame() const { return m_engine->checkEveryFrame(); }
	// ���ƿؼ�����
	template <typename T>
	void drawWindow(const T* window, int absX, int absY) { }
	// ���ƹ���ؼ�����
	void drawWindow(const EditorManageWindow* manageWindow, int absX, int absY);
	// ����Static����
	void drawWindow(const EditorLabel* label, int absX, int absY);
	// ����Button����
	void drawWindow(const EditorButton* button, int absX, int absY);

private:
	// ����control��һЩ����
	template <typename EditorWindowType, typename ControlType>
	void resetControl(const EditorWindowType* editorWindow, ControlType* control, int absX, int absY);
private:
	// ��ʼ�������õ�Engine
	void initEngine(HWND mainWndId);
	// ��ʼ�����ֻ����õĿؼ�
	void initControls();
private:
	// ÿ֡���
	float m_elapsedTime = 0.05f;
	// �����õ�Engine
	std::unique_ptr<AbstractEngine> m_engine;
	// �����õĸ��ֿؼ�
	std::unique_ptr<StaticControl> m_staticControl;
	std::unique_ptr<ButtonControl> m_buttonControl;
};

// ����control��һЩ����
template <typename EditorWindowType, typename ControlType>
inline void DrawControlManager::resetControl(const EditorWindowType* editorWindow, ControlType* control, int absX, int absY)
{
	// ���÷�Χ
	control->SetX(absX);
	control->SetY(absY);
	control->SetWidth(editorWindow->getWidth());
	control->SetHeight(editorWindow->getHeight());
	// ����Control�Ƿ񼤻�
	control->SetEnable(editorWindow->getEnable());
	control->SetText(&(editorWindow->getText()));
}

#endif	// DRAW_CONTROL_MANAGER_H
