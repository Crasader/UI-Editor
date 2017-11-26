#ifndef FORM_OBJECT_VIEW_DEFINE_H
#define FORM_OBJECT_VIEW_DEFINE_H

#include <wx/clntdata.h>
#include "../EditorWindow/EditorFunc.h"

class EditorWindowID : public wxClientData
{
public:
	EditorWindowID(ID_TYPE editorWinId)
		: m_editorWinId(editorWinId)
	{

	}
	~EditorWindowID() override { }

	// ��ȡ�ڵ��Ӧ�Ŀؼ�ID
	ID_TYPE getEditorWinId() const { return m_editorWinId; }
private:
	ID_TYPE m_editorWinId;
};

#endif	// FORM_OBJECT_VIEW_DEFINE_H