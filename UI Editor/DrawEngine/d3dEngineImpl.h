#ifndef D3D_ENGINE_IMPL_H
#define D3D_ENGINE_IMPL_H

/*
 * �ļ�����d3dEngineImpl
 * ���ã��ṩһЩʵ��d3dEngine�Ĺ��ܺ���
 * ˵�����ò����ļ���ʵ�֣�ʹ����Microsoft��DXUT�е����ʵ�֣��������޸�
 * ʹ���߿����Ƴ��ò��ִ��룬ͬʱ�����Լ���������������Ⱦ����
 */

#include <array>
#include "d3d9ResourceManager.h"

class D3D9ResourceManager;

// Enums for pre-defined control types
enum CONTROL_TYPE
{
	CONTROL_BUTTON,
	CONTROL_STATIC,
	CONTROL_CHECKBOX,
	CONTROL_RADIOBUTTON,
	CONTROL_COMBOBOX,
	CONTROL_SLIDER,
	CONTROL_EDITBOX,
	CONTROL_LISTBOX,
	CONTROL_SCROLLBAR
};

enum CONTROL_STATE
{
	STATE_NORMAL = 0,
	STATE_DISABLED,
	STATE_HIDDEN,
	STATE_FOCUS,
	STATE_MOUSEOVER,
	STATE_PRESSED
};

const int MAX_CONTROL_STATES = 6;

struct BlendColor
{
	void Init(D3DCOLOR defaultColor, D3DCOLOR disabledColor = D3DCOLOR_ARGB(200, 128, 128, 128),
		D3DCOLOR hiddenColor = 0);
	void Blend(CONTROL_STATE iState, float fElapsedTime, float fRate = 0.7f);

	std::array<D3DCOLOR, MAX_CONTROL_STATES> States;		// Modulate colors for all possible control states
	D3DXCOLOR Current;
};

// Contains all the display tweakables for a sub-control
class FontTexElement
{
public:
	void SetTexture(UINT iTexture, RECT* prcTexture,
		D3DCOLOR defaultTextureColor = D3DCOLOR_ARGB(255, 255, 255, 255));
	void SetFont(UINT iFont, D3DCOLOR defaultFontColor = D3DCOLOR_ARGB(255, 255, 255, 255),
		DWORD dwTextFormat = DT_CENTER | DT_VCENTER);
	void Refresh();

	UINT iTexture;			// Index of the texture for this Element
	UINT iFont;				// Index of the font for this Element
	DWORD dwTextFormat;		// The format argument to DrawText

	RECT rcTexture;			// Bounding rect of this element on the composite texture

	BlendColor TextureColor;
	BlendColor FontColor;
};

// Contains all the display information for a given control type
struct ElementHolder
{
	UINT nControlType;
	UINT iElement;

	FontTexElement Element;
};

class D3DEngineImpl
{
public:
	D3DEngineImpl();
	~D3DEngineImpl();

	// ��ʼ��ʵ�ֵ���Ϣ
	void Init(D3D9ResourceManager* pManager, LPCTSTR pszTextureFilename);

	// Access the default display Elments used when adding new controls
	HRESULT SetDefaultElement(CONTROL_TYPE nControlType, UINT iElement, FontTexElement* pElement);
	FontTexElement* GetDefaultElement(CONTROL_TYPE nControlType, UINT iElement);

private:
	// ��ʼ��Ĭ��ʹ�õ��������ͼ��Ϣ
	void                InitDefaultElements();
	// ��ӹ����������Ϣ
	HRESULT SetFont(UINT index, LPCTSTR strFaceName, LONG height, LONG weight);
	FontNode9* GetFont(UINT index);
	// ��ӹ������ͼ��Ϣ
	HRESULT SetTexture(UINT index, LPCTSTR strFilename);
	TextureNode9* GetTexture(UINT index);
private:
	D3D9ResourceManager* m_pManager = nullptr;
	// m_TextureCache�е����
	CGrowableArray<int> m_Textures;
	// m_FontCache�е����
	CGrowableArray<int> m_Fonts;
	// ������¼���в�ͬ�ؼ�����Ĭ�ϵ�������ͼ��Ϣ
	CGrowableArray <ElementHolder*> m_DefaultElements;
};

#endif	// D3D_ENGINE_IMPL_H
