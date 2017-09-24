#ifndef EDITOR_WORK_AREA_H
#define EDITOR_WORK_AREA_H

#include "WorkArea.h"
#include <wx/msw/wrapwin.h>		// ��wxWidgets�����<Windows.h>
#include <wx/mdi.h>
#include <wx/panel.h>
#include <wx/dnd.h>
#include "../EditorWindow/WindowInterface.h"

class D3DEngine;
class CopyWindowValue;
class wxMDIParentFrame;
class wxMDIChildFrame;

class EditorWorkArea : public WorkArea
{
public:
	EditorWorkArea(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	~EditorWorkArea();

	// ��ȡ�ö����е�������
	wxWindow* getBench() override;

	// ����ÿ֡����
	void updateFrame(float dt);

	// ��������Drop�¼�
	void onDrop(wxCoord x, wxCoord y, const CopyWindowValue& winValue);

private:
	// �������������µļ���
	void updateScene(float dt);
	// ����ÿ֡����
	void drawScene();

	// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
	HWND getHandle();

	// ����һ�����ڶ���
	void createWndObject(AbstractEditorWindow* parent, int absX, int absY, const CopyWindowValue& winValue);
	// ��ʼ��D3D��Ա
	void initD3DMember();

private:
	wxMDIChildFrame *m_bench;

	// ����D3D������
	D3DEngine* m_d3dEngine;
	//// �����洢�����Ĵ���
	//AbstractEditorWindow* m_editorWins = nullptr;
};

// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
inline HWND EditorWorkArea::getHandle()
{ 
	return static_cast<HWND>(getBench()->GetHandle()); 
}

#endif	// EDITOR_WORK_AREA_H
