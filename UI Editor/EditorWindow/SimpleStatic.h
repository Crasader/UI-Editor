#ifndef SIMPLE_STATIC_H
#define SIMPLE_STATIC_H

/*
 * �ļ�����SimpleStatic
 * ���ã�����ʵ�ּ�label��ʾ�Ĵ���
 */

#include "SimpleWindow.h"
#include <wx/font.h>

namespace inner
{
	template <typename T>
	class SimpleStatic : public SimpleWindow<T>
	{
	public:
		SimpleStatic(SimpleWindow<T>* parent, int relX, int relY, int width, int height);
		~SimpleStatic() override;

		// ������ʾ������
		void setLabel(const wxString& label) { m_label = label; }
		// ������ʾ�õ�����
		void setFont(wxFont font) { m_font = font; }

	private:
		// ��ʾ��label
		wxString m_label;
		// ��ʾʹ�õ�����
		wxFont m_font;
	};
}

#include "SimpleStatic.inl"

#endif	// SIMPLE_STATIC_H
