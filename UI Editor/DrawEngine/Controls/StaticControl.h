#ifndef STATIC_CONTROL_H
#define STATIC_CONTROL_H

/*
 * �ļ�����StaticControl
 * ���ã�ʵ��Static���ʹ��ڵ���Ⱦ
 * ˵���������ļ���ʵ�֣�ʹ����Microsoft��DXUT�е����ʵ�֣��������޸�
 * ʹ���߿����Ƴ��ò��ִ��룬ͬʱ�����Լ���������������Ⱦ����
 */

#include "WindowControl.h"

class StaticControl : public WindowControl
{
public:
	StaticControl();
	~StaticControl() override {}

	// ��д��Ⱦ����
	void Render(AbstractEngine* engine, float fElapsedTime) override;

	// ��ȡ��������
	CONTROL_TYPE GetControlType() const override { return CONTROL_STATIC; }

	const LABEL_TYPE* GetText()
	{
		return m_strText;
	}

	// ����Static�����ݣ�������������
	// ע�⣺��ǰʵ����DrawControlManager�п��ܴ�����������
	HRESULT SetText(const LABEL_TYPE* strText);

protected:
	const LABEL_TYPE* m_strText;		// Window text
};

inline HRESULT StaticControl::SetText(const LABEL_TYPE* strText)
{
	if (strText == nullptr)
	{
		m_strText = nullptr;
		return S_OK;
	}

	m_strText = strText;
	return S_OK;
}

#endif	// STATIC_CONTROL_H
