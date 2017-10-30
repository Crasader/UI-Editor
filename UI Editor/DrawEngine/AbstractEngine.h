#ifndef ABSTRACT_ENGINE_H
#define ABSTRACT_ENGINE_H

/*
 * �ļ�����AbstractEngine
 * ���ã�����ͬһ���ؼ�����ͬ���ڣ����߲�ͬ����£�������Ҫʵ�ֲ�ͬ�Ļ���Ч����
 * �������ͬ��ʵ��Ч��
 */

#include "AbstractEngineImpl.h"
#include <memory>

class AbstractEngine
{
public:
	AbstractEngine() { }
	virtual ~AbstractEngine() {}

	// ���ƺ���
	virtual HRESULT DrawRect(RECT* pRect, D3DCOLOR color)
		{ return m_engineImpl->DrawRect(pRect, color); }
	virtual HRESULT DrawPolyLine(POINT* apPoints, UINT nNumPoints, D3DCOLOR color) 
		{ return m_engineImpl->DrawPolyLine(apPoints, nNumPoints, color); }
	virtual HRESULT DrawSprite(FontTexElement* pElement, RECT* prcDest) 
		{ return m_engineImpl->DrawSprite(pElement, prcDest); }
	virtual HRESULT CalcTextRect(LPCTSTR strText, FontTexElement* pElement, RECT* prcDest, int nCount) 
		{ return m_engineImpl->CalcTextRect(strText, pElement, prcDest, nCount); }
	// ��ָ��λ�û�������
	virtual HRESULT DrawRectText(LPCTSTR strText, FontTexElement* pElement, RECT* prcDest, bool bShadow = false,
		int nCount = -1) {
		return m_engineImpl->DrawRectText(strText, pElement, prcDest, bShadow, nCount);
	}

	// ��Ⱦ�ؼ�֮ǰ׼��
	virtual void RenderControlsBefore() 
	{
		m_engineImpl->RenderControlsBefore();
	}
	// ��Ⱦ�ؼ�֮��Ĵ���
	virtual void RenderControlsEnd() 
	{
		m_engineImpl->RenderControlsEnd();
	}

protected:
	void SetEngineImpl(AbstractEngineImpl* engineImpl) { m_engineImpl.reset(engineImpl); }

	const std::unique_ptr<AbstractEngineImpl>& GetEngineImpl() const { return m_engineImpl; }

protected:
	std::unique_ptr<AbstractEngineImpl> m_engineImpl;
};


#endif	// ABSTRACT_ENGINE_H
