#include "EditorFunc.h"
#include <stdexcept>
#include "../Settings/UsedWinAttrDefine.h"
#include "SimpleWindow.h"

namespace inner
{
	EditorFunc::EditorFunc()
		: m_editShow(true),
		m_id(getNewId())
	{
	
	}

	EditorFunc::~EditorFunc()
	{
	}

	// �޸ı༭ʱ�Ƿ���ʾ
	bool EditorFunc::ChangeEditShow(const wxAny& value)
	{
		return ChangeWndAttrValue<bool>(value, &SimpleWindow<EditorFunc>::getEditShow,
			&SimpleWindow<EditorFunc>::setEditShow, __func__);
	}

	// �޸�X����
	bool EditorFunc::ChangePosX(const wxAny & value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getRelX,
			&SimpleWindow<EditorFunc>::updateRelX, __func__);
	}

	// �޸�Y����
	bool EditorFunc::ChangePosY(const wxAny &value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getRelY,
			&SimpleWindow<EditorFunc>::updateRelY, __func__);
	}

	// �޸�sizeX
	bool EditorFunc::ChangeSizeX(const wxAny & value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getWidth,
			&SimpleWindow<EditorFunc>::updateWidth, __func__);
	}

	// �޸�sizeY
	bool EditorFunc::ChangeSizeY(const wxAny & value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getHeight,
			&SimpleWindow<EditorFunc>::updateHeight, __func__);
	}

	// ��ȡ���������Դ�����Map
	const EditorFunc::ATTR_HANDLE_MAP& EditorFunc::getEditorAttrHandles()
	{
		// ���������Դ�����Map
		static auto s_attrHandles = initEditorAttrHanldes();
		return s_attrHandles;
	}

	ID_TYPE EditorFunc::s_id_generator = ID_BEG;

	// ��ʼ�����Դ�����Map
	EditorFunc::ATTR_HANDLE_MAP EditorFunc::initEditorAttrHanldes()
	{
		ATTR_HANDLE_MAP handles;
		handles.insert(std::make_pair(EDITOR_SHOW, &EditorFunc::ChangeEditShow));
		return handles;
	}
}
