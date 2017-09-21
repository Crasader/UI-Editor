#include "WindowFactory.h"
#include "../Form/EditorToolWidgetSelectDefine.h"
#include "EditorLabel.h"
#include "EditorButton.h"

// ���ݿ����Ĵ������ݣ����촰��
AbstractEditorWindow * WindowFactory::createCopyObjectWnd(const CopyWindowValue& winObject,
	AbstractEditorWindow* parent, int relX, int relY, int width, int height)
{
	AbstractEditorWindow* editorWnd = createEditorWnd(winObject.getWinName(),
		parent, relX, relY, width, height);

	return editorWnd;
}

// ���ݴ�������ȡ��Ӧ�Ĵ��ڶ���
AbstractEditorWindow * WindowFactory::createEditorWnd(const wxString & winName, 
	AbstractEditorWindow* parent, int relX, int relY, int width, int height) const
{
	if (winName == EDITOR_LABEL_TYPE)
	{
		return new inner::EditorLabel(parent, relX, relY, width, height);
	}
	else if (winName == EDITOR_BUTTON_TYPE)
	{
		return new inner::EditorButton(parent, relX, relY, width, height);
	}

	return nullptr;
}
