#ifndef SIMPLE_STATIC_H
#define SIMPLE_STATIC_H

/*
 * �ļ�����SimpleLabel
 * ���ã�����ʵ�ּ�label��ʾ�Ĵ���
 */

#include "SimpleWindow.h"
#include <wx/font.h>

namespace inner
{
	template <typename T>
	class SimpleLabel : public SimpleWindow<T>
	{
	public:
		SimpleLabel(SimpleWindow<T>* parent, int relX, int relY, int width, int height);
		~SimpleLabel() override;

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

#include "SimpleLabel.inl"

#endif	// SIMPLE_STATIC_H
