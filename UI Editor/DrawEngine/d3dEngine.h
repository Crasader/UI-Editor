#ifndef D3D_ENGINE_H
#define D3D_ENGINE_H

#include <map>
#include "d3dUtil.h"
#include "GameTimer.h"
#include "../Settings/WindowEnumAttrDefine.h"
#include "../ErrorHandle/ErrorHandle.h"

class D3DEngine
{
public:
	D3DEngine(HWND mainWndId, D3DDEVTYPE devType, DWORD requestedVP);
	~D3DEngine();

	// ��ȡD3D�����Ӧ����
	HWND getMainWnd() const;
	// �����Ӧ���ڴ�С�ı�
	void handlgeSizeChange(UINT width, UINT height);

	// ��ȡ�豸
	IDirect3DDevice9* getDevice() { return m_d3dDevice;  }
	// ��ȡ��Ӧ������
	ID3DXFont* getFont(FONT_TYPE fontType) const;

	// ������ܵ��豸��ʧ
	bool checkDeviceLost();

private:
	// �����豸ǰ������
	void onLostDevice();
	// �����豸��Ĵ���
	void onResetDevice();
	// �����豸֡����Ϣ
	void CalculateFrameStats();

	// ���D3D������ʼ��
	void initDirect3D();
	// ��ʼ��D3D����
	void initD3DFont();
	// ������ͬ��С�ʹ�ϸ������
	void createHeightWeightFont(FONT_TYPE fontType, int height, int weight, D3DXFONT_DESC& fontDesc);

private:
	// D3D�����Ӧ�Ĵ���ID
	HWND m_mainWnd;
	// D3D�豸����
	D3DDEVTYPE m_devType;
	// D3DҪ��Ķ��㴦��
	DWORD m_requestedVP;
	// D3D����
	IDirect3D9* m_d3dObject;
	// D3D���ֲ���
	D3DPRESENT_PARAMETERS m_d3dPP;
	// D3D�豸
	IDirect3DDevice9* m_d3dDevice;
	// �����������������
	std::map<FONT_TYPE, ID3DXFont*> m_fonts;

	// ʱ�������
	GameTimer m_timer;
	// ÿ��֡��
	float m_fps;
	// ÿ֡���ú�����
	float m_mspf;
};

// ��ȡD3D��Ӧ����
inline HWND D3DEngine::getMainWnd() const
{
	return m_mainWnd;
}

// ��ȡ��Ӧ������
inline ID3DXFont* D3DEngine::getFont(FONT_TYPE fontType) const
{
	auto it = m_fonts.find(fontType);
	if (it != m_fonts.cend())
	{
		return it->second;
	}

	throw ExtraExcept::unexpected_situation("D3DEngine::getFont: font should be found here.");
}

#endif	// D3D_ENGINE_H
