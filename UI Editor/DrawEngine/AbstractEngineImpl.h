#ifndef ABSTRACT_ENGINE_IMPL_H
#define ABSTRACT_ENGINE_IMPL_H

/*
 * �ļ�����AbstractEngineImpl
 * ���ã��ṩEngineImpl��ʹ�ýӿڣ����󻯲�ͬʵ���ܹ��ṩ�Ĺ���
 * �������ػ��ƹ���ʹ�õ�ϵͳʵ��
 */

#include <winerror.h>
#include "EngineImplDefine.h"

class AbstractEngineImpl
{
public:
	AbstractEngineImpl() {}
	virtual ~AbstractEngineImpl() {}

	// ���ƺ���
	virtual HRESULT DrawRect(RECT* pRect, D3DCOLOR color) { return S_OK; }
	virtual HRESULT DrawPolyLine(POINT* apPoints, UINT nNumPoints, D3DCOLOR color) { return S_OK; }
	virtual HRESULT DrawSprite(FontTexElement* pElement, RECT* prcDest) { return S_OK; }
	virtual HRESULT CalcTextRect(LPCTSTR strText, FontTexElement* pElement, RECT* prcDest, int nCount) { return S_OK; }
	// ��ָ��λ�û�������
	virtual HRESULT DrawRectText(LPCTSTR strText, FontTexElement* pElement, RECT* prcDest, bool bShadow = false,
		int nCount = -1) {
		return S_OK;
	}

	// ��Ⱦ�ؼ�֮ǰ׼��
	virtual void RenderControlsBefore() {}
	// ��Ⱦ�ؼ�֮��Ĵ���
	virtual void RenderControlsEnd() {}
};

#endif	// ABSTRACT_ENGINE_IMPL_H