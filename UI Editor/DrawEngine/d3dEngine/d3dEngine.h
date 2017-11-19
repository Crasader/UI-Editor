#ifndef D3D_ENGINE_H
#define D3D_ENGINE_H

/*
* �ļ�����DefaultEngine
* ���ã��ṩD3D9��ʽ�Ļ��ƹ���ʵ��
*/

#include <map>
#include <memory>
#include "../AbstractEngine.h"
#include "WindowEnumAttrDefine.h"
#include "d3dUtil.h"
#include "../GameTimer.h"

class D3D9ResourceManager;

class D3DEngine : public AbstractEngine
{
public:
	D3DEngine(HWND mainWndId, D3DDEVTYPE devType, DWORD requestedVP);
	~D3DEngine();

	// ÿ֡���״̬
	bool checkEveryFrame() { return !checkDeviceLost(); }

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
	// ��ʼ��EngineImpl
	void initEngineImpl();
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

	// �������ͼ����
	D3D9ResourceManager* m_resourceManager;
};

// ��ȡD3D��Ӧ����
inline HWND D3DEngine::getMainWnd() const
{
	return m_mainWnd;
}

#endif	// D3D_ENGINE_H
