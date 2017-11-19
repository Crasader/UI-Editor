#ifndef SIMPLE_STATIC_H
#define SIMPLE_STATIC_H

/*
 * �ļ�����SimpleLabel
 * ���ã�����ʵ�ּ�label��ʾ�Ŀؼ�
 */

#include <wx/font.h>
#include "SimpleWindow.h"
#include "UiEditorProtocol.h"

namespace inner
{
	template <typename T>
	class SimpleLabel : public SimpleWindow<T>
	{
	public:
		using SIMPLE_WINDOW_TYPE = typename SimpleWindow<T>::SIMPLE_WINDOW_TYPE;
	public:
		SimpleLabel(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		~SimpleLabel() override;

		// ����Label��ʾ������
		template <typename T>
		void setText(T&& text) { m_text = text; }
		// ��ȡLabel��ʾ������
		const LABEL_TYPE& getText() const { return m_text; }
		// ������ʾ�õ�����
		void setFont(wxFont font) { m_font = font; }

		// ���ػ��ƺ���
		void draw(int x, int y) const override {}

	private:
		// ��¼label������
		LABEL_TYPE m_text;
		// ��ʾʹ�õ�����
		wxFont m_font;
	};
}

#include "SimpleLabel.inl"

#endif	// SIMPLE_STATIC_H
