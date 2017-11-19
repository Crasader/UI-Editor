#ifndef EDITOR_ABSTRACT_WINDOW_H
#define EDITOR_ABSTRACT_WINDOW_H

#include "EditorFunc.h"
#include "EditorWindowDefine.h"
#include "SimpleWindow/SimpleWindow.h"

namespace inner
{
	template <>
	class SimpleWindow<EditorEditableFunc> : public SimpleWindow<EditorFunc>
	{
	public:
		using SimpleWindow<EditorFunc>::SimpleWindow;
		~SimpleWindow<EditorEditableFunc>() override = default;

		// ��д�������ú��������޸ļ�¼�������б���


	protected:
		// ���øÿؼ��Ƿ�༭ʱ��ʾ
		void setEditShow(bool editShow) override;
		// �ÿؼ��Ƿ���ؼ���Ϣ
		bool isHandleMsg() const override { return getEditShow(); }
	};

	// ���øÿؼ��Ƿ�༭ʱ��ʾ
	inline void SimpleWindow<EditorEditableFunc>::setEditShow(bool editShow)
	{
		if (editShow != getEditShow())
		{
			// ���ñ༭ʱ�Ƿ������ʾ
			EditorFunc::setEditShow(editShow);
			// �������ؼ�����Ϣ������Χ
			SimpleWindow<EditorFunc>::resetMsgRegion();
		}
	}
}

#endif	// EDITOR_ABSTRACT_WINDOW_H
