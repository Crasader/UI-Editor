#ifndef EDITOR_WORK_AREA_H
#define EDITOR_WORK_AREA_H

#include "WorkArea.h"
#include <wx/msw/wrapwin.h>		// ��wxWidgets�����<Windows.h>
#include <wx/panel.h>
#include <wx/dnd.h>
#include "../EditorWindow/EditorWindowInterface.h"

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
	// ��ȡ���ڹ�������ID
	ID_TYPE getManageWindowId() const;
	// ���õ�ǰѡ�еĴ���
	void setCurrentWindow(EditorAbstractWindow* currentWnd) { m_currentWnd = currentWnd; }
	// ��ȡ��ǰѡ�еĴ���
	EditorAbstractWindow* getCurrentWindow() const { return m_currentWnd; }
	// ΪparentWnd���һ���Ӵ���
	bool pushBackWindow(EditorAbstractWindow* parenWnd, EditorAbstractWindow* insertWnd);
	// ΪparentWnd��ָ��λ�����һ���Ӵ���
	bool insertWindow(EditorAbstractWindow* parentWnd, size_t idx, EditorAbstractWindow* insertWnd);
	// ���ض�ID���Ӵ����Ƴ�
	bool removeWindow(EditorAbstractWindow* removeWnd);

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
	template <typename T = UiEditable<EditorAbstractWindow>>
	EditorAbstractWindow* findWnd(wxCoord x, wxCoord y);
	// ����һ�����ڶ���
	void createWndObject(EditorAbstractWindow* parent, int absX, int absY, const CopyWindowInfo& winValue);

	// ��ʼ����ʾ����
	void initFrameWnd(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	// ��ʼ��������
	void initManageWnd();

private:
	wxPanel *m_bench;

	// ����D3D������
	D3DEngine* m_d3dEngine;
	// �����洢�����Ĵ���
	EditorAbstractWindow* m_winMgr = nullptr;
	// ��ǰѡ�еĴ���
	EditorAbstractWindow* m_currentWnd;
};

// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
inline HWND EditorWorkArea::getHandle()
{ 
	return static_cast<HWND>(getBench()->GetHandle()); 
}

// ����ָ��λ�ý�����Ϣ�Ĵ���
template<typename T>
inline EditorAbstractWindow * EditorWorkArea::findWnd(wxCoord x, wxCoord y)
{
	int relX = narrow_cast<int>(x);
	int relY = narrow_cast<int>(y);
}

#endif	// EDITOR_WORK_AREA_H