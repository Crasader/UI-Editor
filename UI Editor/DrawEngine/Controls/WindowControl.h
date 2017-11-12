#ifndef WINDOW_CONTROL_H
#define WINDOW_CONTROL_H

/*
 * �ļ�����WindowControl
 * ���ã�����ʵ�ִ�����Ⱦ�Ĺ��ܣ�ͨ�����ô��ڵ�ֵ������Ⱦ��Ӧ�Ķ��󣬵���Ҫ�����ݺܶ�ʱ������ͨ��
 * ������Ҫ��Ⱦ���ڵ�ָ�룬���ö�Ӧ������ʵ��
 * ˵���������ļ���ʵ�֣�ʹ����Microsoft��DXUT�е����ʵ�֣��������޸�
 * ʹ���߿����Ƴ��ò��ִ��룬ͬʱ�����Լ���������������Ⱦ����
 */

#include <d3d9.h>
#include "../EngineImplDefine.h"
#include "../CGrowableArray.h"
#include "../../EditorFuncDefine.h"

class AbstractEngine;
class FontTexElement;

class WindowControl
{
public:
	WindowControl();
	virtual ~WindowControl();

	virtual HRESULT OnInit()
	{
		return S_OK;
	}

	virtual void Refresh();
	// ��Ⱦ����
	virtual void Render(AbstractEngine* engine, float fElapsedTime) { }

	// ��ȡ��������
	virtual CONTROL_TYPE GetControlType() const { return CONTROL_NULL; }

	void SetX(int x) { m_rcBoundingBox.left = x; }
	void SetY(int y) { m_rcBoundingBox.top = y; }
	void SetWidth(int width) { m_rcBoundingBox.right = m_rcBoundingBox.left + width; }
	void SetHeight(int height) { m_rcBoundingBox.bottom = m_rcBoundingBox.top + height; }
	void SetEnable(bool enable) { m_bEnabled = enable; }
	void SetRect(const RECT& boundingBox) { m_rcBoundingBox = boundingBox; }

	int GetX() const { return m_rcBoundingBox.left; }
	int GetY() const { return m_rcBoundingBox.right; }
	int GetWidth() const { return m_rcBoundingBox.right - m_rcBoundingBox.left; }
	int GetHeight() const { return m_rcBoundingBox.bottom - m_rcBoundingBox.top; }
	RECT& GetRect() { return m_rcBoundingBox; }
	bool GetEnabled() const { return m_bEnabled; }

	virtual void SetTextColor(D3DCOLOR Color);

	FontTexElement* GetElement(UINT iElement)
	{
		return m_Elements.GetAt(iElement);
	}

	HRESULT SetElement(UINT iElement, FontTexElement* pElement);

protected:
	// Rectangle defining the active region of the control
	RECT m_rcBoundingBox;
	// �Ƿ�ΪEnable״̬
	bool m_bEnabled;

	// All display elements
	CGrowableArray<FontTexElement*> m_Elements;
};

#endif	// WINDOW_CONTROL_H
