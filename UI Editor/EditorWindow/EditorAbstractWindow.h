#ifndef EDITOR_ABSTRACT_WINDOW_H
#define EDITOR_ABSTRACT_WINDOW_H

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

	protected:
		// ���øô����Ƿ�༭ʱ��ʾ
		void setEditShow(bool editShow) override;
		// �ô����Ƿ�������Ϣ
		bool isHandleMsg() const override { return getEditShow(); }
	};

	// ���øô����Ƿ�༭ʱ��ʾ
	inline void SimpleWindow<EditorEditableFunc>::setEditShow(bool editShow)
	{
		// ���ñ༭ʱ�Ƿ������ʾ
		EditorFunc::setEditShow(editShow);
		// ���������ڵ���Ϣ������Χ
		SimpleWindow<EditorFunc>::resetMsgRegion();
	}
}

#endif	// EDITOR_ABSTRACT_WINDOW_H
