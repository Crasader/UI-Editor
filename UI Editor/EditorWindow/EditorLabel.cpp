#include "EditorLabel.h"

namespace inner
{
	EditorLabel::EditorLabel(AbstractEditorWindow* parent, int relX, int relY, int width, int height)
		: SimpleLabel<EditorFunc>(parent, relX, relY, width, height)
	{
	}

	EditorLabel::~EditorLabel()
	{
	}

	// ���´��ڶ���������Ϣ
	void EditorLabel::updateWinAttr(const wxString& attrName, const wxAny &value)
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
	const EditorLabel::ATTR_HANDLE_MAP & EditorLabel::getEditorAttrHandles()
	{
		// ���������Դ�����Map
		static ATTR_HANDLE_MAP s_attrHandles = initEditorAttrHanldes();
		return s_attrHandles;
	}

	// ��ʼ�����Դ�����Ma
	EditorLabel::ATTR_HANDLE_MAP EditorLabel::initEditorAttrHanldes()
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