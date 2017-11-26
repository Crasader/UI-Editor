#include <wx/regex.h>
#include "EditorWindowFactory.h"
#include "EditorManageWindow.h"
#include "EditorLabel.h"
#include "EditorButton.h"
#include "EditorFrame.h"
#include "../ErrorHandle/ErrorHandle.h"

EditorAbstractWindowFactory* EditorWindowFactory::s_factoryInst = nullptr;

// ���ݿ����Ŀؼ����ݣ�����ؼ�
EditorAbstractWindow * EditorWindowFactory::createCopyObjectWnd(CopyWindowInfo winObject,
	EditorAbstractWindow* parent, int relX, int relY, int width, int height)
{
	EditorAbstractWindow* editorWnd = WindowFactoryImpl::createEditorWnd(winObject.getWinName(),
		parent, relX, relY, width, height);

	// ����Ϊ�������������ֵ
	auto& winAttrs = winObject.getWinAttrValues();
	// �޸�����ֵ�б�
	// �޸Ķ�����
	auto iter = winAttrs.find(OBJECT_NAME);
	if (iter != winAttrs.end() && !(iter->second).As<wxString>().empty())
	{
		wxString curName = iter->second.As<wxString>();
		changeWindowName(curName);
		iter->second = curName;
	}
	else
	{
		// ��Ĭ�ϵ�����
		 long winTypeNum = ++m_winTypeToNums[editorWnd->getWindowClassName()];
		 wxString objectName = editorWnd->getWindowClassName() + (wxString() << winTypeNum);
		 winAttrs[OBJECT_NAME] = objectName;
	}
	// �޸ķ�Χ��Ϣ
	winAttrs[WIN_POSX] = editorWnd->getRelX();
	winAttrs[WIN_POSY] = editorWnd->getRelY();
	winAttrs[WIN_SIZEX] = editorWnd->getWidth();
	winAttrs[WIN_SIZEY] = editorWnd->getHeight();

	for (const auto& value : winAttrs)
	{
		editorWnd->updateWinAttr(value.first, value.second);
	}

	return editorWnd;
}

// ����һ������ؼ�
EditorAbstractWindow * EditorWindowFactory::createManageWnd(int width, int height)
{
	return new EditorManageWindow(0, 0, width, height);
}

// ���ݿ����ؼ��������¿ؼ�ȡһ������
void EditorWindowFactory::changeWindowName(wxString & winName)
{
	wxString suffix;
	wxRegEx matchSuffix = "_[[:digit:]]*$";
	if (matchSuffix.Matches(winName))
	{
		suffix = matchSuffix.GetMatch(winName);
		if (suffix == "_")
		{
			winName += "1";
		}
		else
		{
			wxString numStr = suffix.Right(suffix.size() - 1);
			long num = 0;
			numStr.ToLong(&num);
			wxString newNum;
			newNum << (num + 1);
			winName.replace(winName.size() - suffix.size() + 1, suffix.size() - 1, newNum);
		}
	}
	else
	{
		winName += "_1";
	}
}

// ���ݿؼ�����ȡ��Ӧ�Ŀؼ�����
EditorAbstractWindow * WindowFactoryImpl::createEditorWnd(const wxString & winName,
	EditorAbstractWindow* parent, int relX, int relY, int width, int height)
{
	if (winName == EDITOR_LABEL_TYPE)
	{
		if (width <= 0 || height <= 0)
		{
			width = EDITOR_LABEL_WIDTH;
			height = EDITOR_LABEL_HEIGHT;
		}
		return new EditorLabel(parent, relX, relY, width, height);
	}
	else if (winName == EDITOR_BUTTON_TYPE)
	{
		if (width <= 0 || height <= 0)
		{
			width = EDITOR_BUTTON_WIDTH;
			height = EDITOR_BUTTON_HEIGHT;
		}
		return new EditorButton(parent, relX, relY, width, height);
	}
	else if (winName == EDITOR_FRAME_TYPE)
	{
		if (width <= 0 || height <= 0)
		{
			width = EDITOR_FRAME_WIDTH;
			height = EDITOR_FRAME_HEIGHT;
		}
		return new EditorFrame(parent, relX, relY, width, height);
	}

	if (width < 0 || height < 0)
	{
		width = EDITOR_WINDOW_WIDTH;
		height = EDITOR_WINDOW_HEIGHT;
	}

	throw ExtraExcept::unexpected_situation("WindowFactoryImpl::createEditorWnd will return nullptr");

	return nullptr;
}
