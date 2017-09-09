#ifndef EDITOR_STATIC_H
#define EDITOR_STATIC_H

/*
 * �ļ�����EditorStatic
 * ���ã���SimpleStatic�Ļ����ϣ�ʵ�����ڱ༭����ع���
 */

#include "SimpleStatic.h"
#include "EditorFunc.h"
#include "WindowInterface.h"


//using EditorStatic = inner::SimpleStatic<inner::EditorFunc>;


namespace inner
{
	class EditorStatic : public SimpleStatic<EditorFunc>
	{
	public:
		EditorStatic(AbstractEditorWindow* parent, int relX, int relY, int width, int height);
		virtual ~EditorStatic();

		// ������ȡ�����Ĵ������ͣ��̳еĴ��ڷ�������
		SimpleStatic<EditorFunc>* getConstructWindow() override { return this;  }

	};
}

#include "SimpleStatic.inl"

#endif	// EDITOR_STATIC_H