#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

/*
 * �ļ�����SimpleButton
 * ���ã�ʵ�ּ򵥵İ�ť����
 */

#include "SimpleWindow.h"
#include <wx/font.h>

namespace inner
{
	template <typename T>
	class SimpleButton : public SimpleWindow<T>
	{
	public:
		SimpleButton(SimpleWindow<T>* parent, int relX, int relY, int width, int height);
		~SimpleButton() override;

		// ������ʾ������
		void setLabel(const wxString& label) { m_label = label; }
		// ������ʾ�õ�����
		void setFont(wxFont font) { m_font = font; }

		// ���ػ��ƺ���
		void draw() override {}

	private:
		// ��ʾ��label
		wxString m_label;
		// ��ʾʹ�õ�����
		wxFont m_font;
	};
}

#include "SimpleButton.inl"

#endif	// SIMPLE_BUTTON_H