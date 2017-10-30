#include "EditorWindowFactory.h"
#include "../Form/EditorToolWidgetSelectDefine.h"
#include "EditorLabel.h"
#include "EditorButton.h"
#include "EditorManageWindow.h"

AbstractWindowFactory* EditorWindowFactory::s_factoryInst = nullptr;

// ���ݿ����Ĵ������ݣ����촰��
EditorAbstractWindow * EditorWindowFactory::createCopyObjectWnd(CopyWindowInfo winObject,
	EditorAbstractWindow* parent, int relX, int relY, int width, int height)
{
	EditorAbstractWindow* editorWnd = WindowFactoryImpl::createEditorWnd(winObject.getWinName(),
		parent, relX, relY, width, height);
	long winTypeNum = ++m_winTypeToNums[editorWnd->getWindowClassName()];
	editorWnd->setWindowObjectName(editorWnd->getWindowClassName() + (wxString() << winTypeNum));

	editorWnd->resetWinAttrs();
	auto& winAttrs = winObject.getWinAttrValues();
	for (const auto& value : winAttrs)
	{
		editorWnd->updateWinAttr(value.first, value.second);
	}

	return editorWnd;
}

// ����һ����������
EditorAbstractWindow * EditorWindowFactory::createManageWnd(int width, int height)
{
	return new EditorManageWindow(0, 0, width, height);
}

// ���ݴ�������ȡ��Ӧ�Ĵ��ڶ���
EditorAbstractWindow * WindowFactoryImpl::createEditorWnd(const wxString & winName,
	EditorAbstractWindow* parent, int relX, int relY, int width, int height)
{
	if (winName == EDITOR_LABEL_TYPE)
	{
		if (width < 0 || height < 0)
		{
			width = EDITOR_LABEL_WIDTH;
			height = EDITOR_LABEL_HEIGHT;
		}
		return new inner::EditorLabel(parent, relX, relY, width, height);
	}
	else if (winName == EDITOR_BUTTON_TYPE)
	{
		if (width < 0 || height < 0)
		{
			width = EDITOR_BUTTON_WIDTH;
			height = EDITOR_BUTTON_HEIGHT;
		}
		return new inner::EditorButton(parent, relX, relY, width, height);
	}

	if (width < 0 || height < 0)
	{
		width = EDITOR_WINDOW_WIDTH;
		height = EDITOR_WINDOW_HEIGHT;
	}

	return nullptr;
}