#include "EditorLabel.h"
#include "../DrawEngine/DrawControlManager.h"
#include "../Settings/UsedWinAttrDefine.h"

EditorLabel::EditorLabel(SIMPLE_WINDOW_TYPE* parent, int relX, int relY, int width, int height)
	: SimpleLabel<inner::EditorEditableFunc>(parent, relX, relY, width, height)
{
	// ��ʱ���ڲ���
	updateWinAttr(LABEL_TEXT, wxString(L"label"));
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

//�ڱ༭�����ϻ���
void EditorLabel::editDraw(int absX, int absY, DrawControlManager * drawManager)
{
	drawManager->drawWindow(this, absX, absY);
}

// ��ȡ���������Դ�����Map
const EditorLabel::ATTR_HANDLE_MAP & EditorLabel::getEditorAttrHandles()
{
	// ���������Դ�����Map
	static ATTR_HANDLE_MAP s_attrHandles = initEditorAttrHanldes();
	return s_attrHandles;
}

// �޸���ʾ���ֵĺ���
bool EditorLabel::ChangeText(const wxAny & value)
{
	if (value.CheckType<wxString>())
	{
		auto v = wxStrToStdStr(value.As<wxString>());
		if (v != getText())
		{
			setText(v);
			return true;
		}
	}
	else
	{
		throw std::runtime_error("ChangeText" + std::string("'s parameter is not ") + typeid(wxString).name());
	}

	return false;
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
	attrHandles.insert(std::make_pair(LABEL_TEXT, &EditorLabel::ChangeText));
	return attrHandles;
}