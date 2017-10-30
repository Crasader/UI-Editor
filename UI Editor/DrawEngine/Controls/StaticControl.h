#ifndef STATIC_CONTROL_H
#define STATIC_CONTROL_H

/*
 * �ļ�����StaticControl
 * ���ã�ʵ��Static���ʹ��ڵ���Ⱦ
 * ˵���������ļ���ʵ�֣�ʹ����Microsoft��DXUT�е����ʵ�֣��������޸�
 * ʹ���߿����Ƴ��ò��ִ��룬ͬʱ�����Լ���������������Ⱦ����
 */

#include "WindowControl.h"
#include <tchar.h>

class StaticControl : public WindowControl
{
public:
	StaticControl();
	~StaticControl() override {}

	// ��д��Ⱦ����
	void Render(AbstractEngine* engine, float fElapsedTime) override;

	HRESULT GetTextCopy(__out_ecount(bufferCount) LPTSTR strDest,
		UINT bufferCount);

	LPCTSTR GetText()
	{
		return m_strText;
	}

	HRESULT SetText(LPCTSTR strText);

protected:
	TCHAR m_strText[MAX_PATH];		// Window text
};

inline HRESULT StaticControl::GetTextCopy(__out_ecount(bufferCount) LPTSTR strDest,
	UINT bufferCount)
{
	// Validate incoming parameters
	if (strDest == nullptr || bufferCount == 0)
	{
		return E_INVALIDARG;
	}

	// Copy the window text
	_tcscpy_s(strDest, bufferCount, m_strText);

	return S_OK;
}

inline HRESULT StaticControl::SetText(LPCTSTR strText)
{
	if (strText == nullptr)
	{
		m_strText[0] = 0;
		return S_OK;
	}

	_tcscpy_s(m_strText, MAX_PATH, strText);
	return S_OK;
}

#endif	// STATIC_CONTROL_H
