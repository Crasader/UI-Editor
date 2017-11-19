#include "EditorFunc.h"
#include "SimpleWindow/SimpleWindow.h"

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

	// �����鿴��ӦID�Ŀؼ�
	SimpleWindow<EditorFunc>* EditorFunc::findMatchWnd(ID_TYPE findId)
	{
		if (getId() == findId)
		{
			return getConstructWindow();
		}
		return nullptr;
	}

	// �޸ı༭ʱ�Ƿ���ʾ
	bool EditorFunc::changeEditShow(const wxAny& value)
	{
		return ChangeWndAttrValue<bool>(value, &SimpleWindow<EditorFunc>::getEditShow,
			&SimpleWindow<EditorFunc>::setEditShow, __func__);
	}

	// �޸�X����
	bool EditorFunc::changePosX(const wxAny & value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getRelX,
			&SimpleWindow<EditorFunc>::updateRelX, __func__);
	}

	// �޸�Y����
	bool EditorFunc::changePosY(const wxAny &value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getRelY,
			&SimpleWindow<EditorFunc>::updateRelY, __func__);
	}

	// �޸�sizeX
	bool EditorFunc::changeSizeX(const wxAny & value)
	{
		return ChangeWndAttrValue<int>(value, &SimpleWindow<EditorFunc>::getWidth,
			&SimpleWindow<EditorFunc>::updateWidth, __func__);
	}

	// �޸�sizeY
	bool EditorFunc::changeSizeY(const wxAny & value)
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
		handles.insert(std::make_pair(EDITOR_SHOW, &EditorFunc::changeEditShow));
		handles.insert(std::make_pair(WIN_POSX, &EditorFunc::changePosX));
		handles.insert(std::make_pair(WIN_POSY, &EditorFunc::changePosY));
		handles.insert(std::make_pair(WIN_SIZEX, &EditorFunc::changeSizeX));
		handles.insert(std::make_pair(WIN_SIZEY, &EditorFunc::changeSizeY));
		return handles;
	}
}