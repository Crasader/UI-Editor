#ifndef EDITOR_WORK_AREA_H
#define EDITOR_WORK_AREA_H

#include "WorkArea.h"
#include <wx/mdi.h>
#include <Windows.h>

class D3DEngine;

class EditorWorkArea : public WorkArea
{
public:
	EditorWorkArea(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	~EditorWorkArea();

	// ��ȡ�ö����е�������
	wxWindow* getBench() { return m_bench;  }

	// ����ÿ֡����
	void updateFrame(float dt);

private:
	// �������������µļ���
	void updateScene(float dt);
	// ����ÿ֡����
	void drawScene();

	// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
	HWND getHandle();

	// ��ʼ��D3D��Ա
	void initD3DMember();

private:
	wxMDIChildFrame *m_bench;

	// ����D3D������
	D3DEngine* m_d3dEngine;
};

// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
inline HWND EditorWorkArea::getHandle()
{ 
	return static_cast<HWND>(getBench()->GetHandle()); 
}

#endif	// EDITOR_WORK_AREA_H
