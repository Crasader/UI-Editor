#ifndef EDITOR_WORK_AREA_H
#define EDITOR_WORK_AREA_H

#include "WorkArea.h"
#include <wx/msw/wrapwin.h>		// ��wxWidgets�����<Windows.h>
#include <wx/mdi.h>
#include <wx/panel.h>
#include <wx/dnd.h>
#include "../EditorWindow/WindowInterface.h"
#include "../EditorWindow/EditorWindowCheck.h"

class D3DEngine;
class CopyWindowInfo;
class wxMDIParentFrame;
class wxMDIChildFrame;

class EditorWorkArea : public WorkArea
{
public:
	EditorWorkArea(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	~EditorWorkArea();

	// ��ȡ�ö����е�������
	wxWindow* getBench() override;
	// ΪID�Ĵ������һ���Ӵ���
	bool pushBackWindow(ID_TYPE parentId, AbstractEditorWindow* insertWnd);
	// ���ض�ID���Ӵ����Ƴ�
	bool removeWindow(ID_TYPE removeId);

public:
	// ����ÿ֡����
	void updateFrame(float dt);

	// ��������Drop�¼�
	void onDrop(wxCoord x, wxCoord y, const CopyWindowInfo& winValue);

private:
	// �������������µļ���
	void updateScene(float dt);
	// ����ÿ֡����
	void drawScene();

	// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
	HWND getHandle();

private:
	// ����ָ��λ�ý�����Ϣ�Ĵ���
	template <typename T = UiEditable<AbstractEditorWindow>>
	AbstractEditorWindow* findWnd(wxCoord x, wxCoord y);
	// ����һ�����ڶ���
	void createWndObject(AbstractEditorWindow* parent, int absX, int absY, const CopyWindowInfo& winValue);
	// ��ʼ��������
	void initManageWnd();

private:
	wxMDIChildFrame *m_bench;

	// ����D3D������
	D3DEngine* m_d3dEngine;
	// �����洢�����Ĵ���
	AbstractEditorWindow* m_editorWins = nullptr;
};

// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
inline HWND EditorWorkArea::getHandle()
{ 
	return static_cast<HWND>(getBench()->GetHandle()); 
}

// ����ָ��λ�ý�����Ϣ�Ĵ���
template<typename T>
inline AbstractEditorWindow * EditorWorkArea::findWnd(wxCoord x, wxCoord y)
{
	int relX = narrow_cast<int>(x);
	int relY = narrow_cast<int>(y);
}

#endif	// EDITOR_WORK_AREA_H