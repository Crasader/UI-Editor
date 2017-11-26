#include "EditorFrame.h"
#include "../DrawEngine/DrawControlManager.h"

// ���¿ؼ�����������Ϣ
void EditorFrame::updateWinAttr(const wxString & attrName, const wxAny & value)
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
void EditorFrame::editDraw(int absX, int absY, DrawControlManager * drawManager)
{
	drawManager->drawWindow(this, absX, absY);
}

const EditorFrame::ATTR_HANDLE_MAP &EditorFrame::getEditorAttrHandles()
{
	// ���������Դ�����Map
	static ATTR_HANDLE_MAP s_attrHandles = initEditorAttrHanldes();
	return s_attrHandles;
}

// ��ʼ�����Դ�����Map
EditorFrame::ATTR_HANDLE_MAP EditorFrame::initEditorAttrHanldes()
{
	ATTR_HANDLE_MAP attrHandles;
	auto attrsRef = EditorFunc::getEditorAttrHandles();
	for (const auto& value : attrsRef)
	{
		attrHandles.insert(value);
	}
	return attrHandles;
}
