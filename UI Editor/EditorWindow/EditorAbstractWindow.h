#ifndef EDITOR_ABSTRACT_WINDOW_H
#define EDITOR_ABSTRACT_WINDOW_H

#include "EditorFunc.h"
#include "EditorWindowDefine.h"
#include "SimpleWindow/SimpleWindow.h"

class SaveInfo;

namespace inner
{
	template <>
	class SimpleWindow<EditorEditableFunc> : public SimpleWindow<EditorFunc>
	{
	public:
		using SELF_TYPE = SimpleWindow<EditorEditableFunc>;
	public:
		using SimpleWindow<EditorFunc>::SimpleWindow;
		~SimpleWindow<EditorEditableFunc>() override = default;

		// ��������Ϣ���浽����������У����replaceΪtrue����ʾֱ���޸�parentInfo��������Ϊ�Ӷ���
		void appendMySelf(SaveInfo& parentInfo, bool replace = false) const;

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
