#ifndef FORM_WORK_AREA_H
#define FORM_WORK_AREA_H

#include <memory>
#include <wx/msw/wrapwin.h>		// ��wxWidgets�����<Windows.h>
#include <wx/panel.h>
#include <wx/dnd.h>
#include "WorkArea.h"
#include "../EditorWindow/EditorWindowInterface.h"

class DrawControlManager;
class CopyWindowInfo;
class wxMDIParentFrame;
class wxMDIChildFrame;

class FormWorkArea : public WorkArea
{
public:
	FormWorkArea(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	~FormWorkArea();

	// ��ȡ�ö����е�������
	wxWindow* getBench() override;
	// ��ȡ�ؼ���������ID
	ID_TYPE getManageWindowId() const;
	// ���õ�ǰѡ�еĿؼ�
	void setCurrentWindow(EditorAbstractWindow* currentWnd) { m_currentWnd = currentWnd; }
	// ��ȡ��ǰѡ�еĿؼ�
	EditorAbstractWindow* getCurrentWindow() const { return m_currentWnd; }
	// ΪparentWnd���һ���ӿؼ�
	bool pushBackWindow(EditorAbstractWindow* parenWnd, EditorAbstractWindow* insertWnd);
	// ΪparentWnd��ָ��λ�����һ���ӿؼ�
	bool insertWindow(EditorAbstractWindow* parentWnd, size_t idx, EditorAbstractWindow* insertWnd);
	// ���ض�ID���ӿؼ��Ƴ�
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
	void drawScene(float dt);
	//�����ӿؼ�
	void drawWindowRecur(EditorAbstractWindow* editorWindow, int absX, int absY);

	// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
	HWND getHandle();

private:
	// ����ָ��λ�ý�����Ϣ�Ŀؼ�
	template <typename T = UiEditable<EditorAbstractWindow>>
	EditorAbstractWindow* findWnd(wxCoord x, wxCoord y);
	// ����һ���ؼ�����
	void createWndObject(EditorAbstractWindow* parent, int absX, int absY, const CopyWindowInfo& winValue);

	// ��ʼ����ʾ����
	void initFrameWnd(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	// ��ʼ������ؼ�
	void initManageWnd();

private:
	wxPanel *m_bench;

	// ���Ƹñ༭����ؼ��Ķ���
	std::unique_ptr<DrawControlManager> m_drawManager;
	// �����洢�����Ŀؼ�
	EditorAbstractWindow* const m_winMgr = nullptr;
	// ��ǰѡ�еĿؼ�
	EditorAbstractWindow* m_currentWnd;
};

// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
inline HWND FormWorkArea::getHandle()
{ 
	return static_cast<HWND>(getBench()->GetHandle()); 
}

// ����ָ��λ�ý�����Ϣ�Ŀؼ�
template<typename T>
inline EditorAbstractWindow * FormWorkArea::findWnd(wxCoord x, wxCoord y)
{
	int relX = narrow_cast<int>(x);
	int relY = narrow_cast<int>(y);
}

#endif	// FORM_WORK_AREA_H