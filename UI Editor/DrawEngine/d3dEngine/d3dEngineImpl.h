#ifndef D3D_ENGINE_IMPL_H
#define D3D_ENGINE_IMPL_H

/*
 * �ļ�����d3dEngineImpl
 * ���ã��ṩһЩʵ��d3dEngine�Ĺ��ܺ���
 * ˵�����ò����ļ���ʵ�֣�ʹ����Microsoft��DXUT�е����ʵ�֣��������޸�
 * ʹ���߿����Ƴ��ò��ִ��룬ͬʱ�����Լ���������������Ⱦ����
 */

#include "../AbstractEngineImpl.h"
#include "d3d9ResourceManager.h"

class D3D9ResourceManager;

class D3DEngineImpl : public AbstractEngineImpl
{
public:
	D3DEngineImpl();
	~D3DEngineImpl() override;

	// ��ʼ��ʵ�ֵ���Ϣ���ö�����pManagerָ����������
	void Init(D3D9ResourceManager* pManager, LPCTSTR pszTextureFilename);

	// Access the default display Elments used when adding new controls
	HRESULT SetDefaultElement(CONTROL_TYPE nControlType, UINT iElement, FontTexElement* pElement);
	FontTexElement* GetDefaultElement(CONTROL_TYPE nControlType, UINT iElement);

	// ��ʼ���ؼ�����ͼ��������
	HRESULT InitControl(WindowControl* pControl) override;
	// ���ƺ���
	HRESULT DrawRectLine(RECT* pRect, D3DCOLOR color) override;
	HRESULT DrawRect(RECT* pRect, D3DCOLOR color) override;
	HRESULT DrawPolyLine(POINT* apPoints, UINT nNumPoints, D3DCOLOR color) override;
	HRESULT DrawSprite(FontTexElement* pElement, RECT* prcDest) override;
	HRESULT CalcTextRect(LPCTSTR strText, FontTexElement* pElement, RECT* prcDest, int nCount) override;
	// ��ָ��λ�û�������
	HRESULT DrawRectText(LPCTSTR strText, FontTexElement* pElement, RECT* prcDest, bool bShadow = false,
		int nCount = -1) override;

	// ��Ⱦ�ؼ�֮ǰ׼��
	void RenderControlsBefore() override;
	// ��Ⱦ�ؼ�֮��Ĵ���
	void RenderControlsEnd() override;

private:
	// ��ʼ��Ĭ��ʹ�õ��������ͼ��Ϣ
	void InitDefaultElements();
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

	ID3DXFont* mFont = nullptr;
};

#endif	// D3D_ENGINE_IMPL_H
