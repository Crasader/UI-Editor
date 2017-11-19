#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

/*
 * �ļ�����SimpleButton
 * ���ã�ʵ�ּ򵥵İ�ť����
 */

#include <wx/font.h>
#include "SimpleWindow.h"
#include "UiEditorProtocol.h"

namespace inner
{
	template <typename T>
	class SimpleButton : public SimpleWindow<T>
	{
	public:
		using SIMPLE_WINDOW_TYPE = typename SimpleWindow<T>::SIMPLE_WINDOW_TYPE;
	public:
		SimpleButton(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height);
		~SimpleButton() override;

		// ����button��ʾ������
		template <typename T>
		void setText(T&& text) { m_text = text; }
		// ��ȡbutton��ʾ������
		const LABEL_TYPE& getText() const { return m_text; }
		// ������ʾ�õ�����
		void setFont(wxFont font) { m_font = font; }

		// ���ػ��ƺ���
		void draw(int x, int y) const override {}

	private:
		// ��ʾ��label
		LABEL_TYPE m_text;
		// ��ʾʹ�õ�����
		wxFont m_font;
	};
}

#include "SimpleButton.inl"

#endif	// SIMPLE_BUTTON_H