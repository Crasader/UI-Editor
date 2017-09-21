#include "EditorButton.h"

namespace inner
{
	EditorButton::EditorButton(AbstractEditorWindow* parent, int relX, int relY, int width, int height)
		: SimpleButton<EditorFunc>(parent, relX, relY, width, height)
	{
	}

	EditorButton::~EditorButton()
	{

	}

	// ���´��ڶ���������Ϣ
	void EditorButton::updateWinAttr(const wxString& attrName, const wxAny &value)
	{
		EditorFunc::updateWinAttr(attrName, value);
		// �鿴�Ƿ���༭ʱ�������ʾ��أ�����ǣ��򵥶�����
		auto attrsRef = getEditorAttrHandles();
		const auto &it = attrsRef.find(attrName);
		if (it != attrsRef.cend())
		{
			(it->second)(this, value);
		}
	}

	// ��ȡ���������Դ�����Map
	const EditorButton::ATTR_HANDLE_MAP & EditorButton::getEditorAttrHandles()
	{
		// ���������Դ�����Map
		static ATTR_HANDLE_MAP s_attrHandles = initEditorAttrHanldes();
		return s_attrHandles;
	}

	// ��ʼ�����Դ�����Ma
	EditorButton::ATTR_HANDLE_MAP EditorButton::initEditorAttrHanldes()
	{
		ATTR_HANDLE_MAP attrHandles;
		auto attrsRef = EditorFunc::getEditorAttrHandles();
		for (const auto& value : attrsRef)
		{
			attrHandles.insert(value);
		}
		return attrHandles;
	}
}