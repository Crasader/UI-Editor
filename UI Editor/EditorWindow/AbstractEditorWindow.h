#ifndef ABSTRACT_EDITOR_WINDOW_H
#define ABSTRACT_EDITOR_WINDOW_H

#include "EditorFunc.h"
#include "SimpleWindow/SimpleWindow.h"

namespace inner
{
	template <>
	class SimpleWindow<EditorEditableFunc> : public SimpleWindow<EditorFunc>
	{
	public:
		using SimpleWindow<EditorFunc>::SimpleWindow;
		~SimpleWindow<EditorEditableFunc>() override = default;

		// ���øô����Ƿ�༭ʱ��ʾ

	};
}

#endif	// ABSTRACT_EDITOR_WINDOW_H
