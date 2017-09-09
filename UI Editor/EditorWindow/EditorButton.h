#ifndef EDITOR_BUTTON_H
#define EDITOR_BUTTON_H

/*
* �ļ�����EditorButton
* ���ã���SimpleButton�Ļ����ϣ�ʵ�����ڱ༭����ع���
*/

#include "SimpleButton.h"
#include "EditorFunc.h"
#include "WindowInterface.h"

namespace inner
{
	class EditorButton : SimpleButton<EditorFunc>
	{
	public:
		EditorButton(AbstractEditorWindow* parent, int relX, int relY, int width, int height);
		~EditorButton();


	};
}

#include "EditorButton.inl"

#endif	// EDITOR_BUTTON_H
