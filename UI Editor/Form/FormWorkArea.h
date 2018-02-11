#ifndef FORM_WORK_AREA_H
#define FORM_WORK_AREA_H

#include <memory>
#include <future>
#include <unordered_set>
#include <wx/msw/wrapwin.h>		// ��wxWidgets�����<Windows.h>
#include <wx/panel.h>
#include <wx/dnd.h>
#include "WorkArea.h"
#include "../EditorWindow/EditorWindowInterface.h"

class DrawControlManager;
class CopyWindowInfo;
class wxMDIParentFrame;
class wxMDIChildFrame;
class EditorSave;

class FormWorkArea : public WorkArea
{
public:
	FormWorkArea(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	~FormWorkArea();

	// ��ȡ�ö����е�������
	wxWindow* getBench() override;
	// ��ȡ�ؼ���������ID
	ID_TYPE getManageWindowId() const;
	// ��ȡ�ؼ�������������
	wxString getManageWindowName() const;
	// ���õ�ǰ�༭�Ŀؼ�
	void setCurrentWindow(EditorAbstractWindow* currentWnd) { m_currentWnd = currentWnd; }
	// ���õ�ǰ�༭�Ŀؼ�ID
	bool setCurrentWindowId(ID_TYPE curWndId);
	// ��ȡ��ǰ�༭�Ŀؼ�
	EditorAbstractWindow* getCurrentWindow() const { return m_currentWnd; }
	// ��ȡ��ǰ�༭�Ŀؼ�ID
	ID_TYPE getCurrentWindowId() const { return m_currentWnd->getId(); }
	// ��ȡ��ǰ����ѡ�еĴ���ID
	const std::unordered_set<ID_TYPE>& getSelectWndIds() const { return m_selectWndIds; }
	// ��ȡ��ǰ����ѡ�еĴ���ID
	std::unordered_set<ID_TYPE>& getSelectWndIds() { return m_selectWndIds; }
	// ���õ�ǰѡ�е����д���ID
	void setSelectWndIds(std::unordered_set<ID_TYPE> selectWndIds) { m_selectWndIds = std::move(selectWndIds); }
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
	// �������������Ϣ
	// ���������ڱ�����
	void handleActivate(wxActivateEvent& event);
	// �������������Ĳ˵�
	void handleContextMenu(wxContextMenuEvent& event);
	// ���������������ļ��ڴ����д�
	void handleDropFiles(wxDropFilesEvent& event);
	// ����ΪFocus
	void handleSetFocus(wxFocusEvent& event);
	// ȡ��Focus
	void handleKillFocus(wxFocusEvent& event);
	// ����Idle��Ϣ
	void handleIdle(wxIdleEvent& event);
	// ������̰�����Ϣ
	void handleKeyDown(wxKeyEvent& event);
	// ��������ɿ���Ϣ
	void handleKeyUp(wxKeyEvent& event);
	// ��������������Ϣ
	void handleChar(wxKeyEvent& event);
	// ��������������
	void handleLMouseDown(wxMouseEvent& event);
	// �����������ɿ�
	void handleLMouseUp(wxMouseEvent& event);
	// ��������ƶ�
	void handleMouseMove(wxMouseEvent& event);
	// ������ƣ����ﲻ��Ҫ�����������
	void handlePaint(wxPaintEvent& event);
	// �����ڴ�С�ı�
	void handleSize(wxSizeEvent& event);

private:
	// ��ȡ���ھ�����ú��������ڳ�ʼ��bench֮�����
	HWND getHandle();
	// �������������µļ���
	void updateScene(float dt);
	// ����ÿ֡����
	void drawScene();
	//�����ӿؼ�
	void drawWindowRecur(EditorAbstractWindow* editorWindow, int absX, int absY);

private:
	// ����ָ��λ�ý�����Ϣ�Ŀؼ�
	template <typename T = UiEditable<EditorAbstractWindow>>
	EditorAbstractWindow* findWnd(wxCoord x, wxCoord y);
	// ����һ���ؼ�����
	void createWndObject(EditorAbstractWindow* parent, int absX, int absY, const CopyWindowInfo& winValue);

	// ��ȡ���洰����Ϣ�Ķ���
	EditorSave* getEditorSave();
	// �����ڱ��浽�ļ��У�ͬ������
	void saveWnds();
	// ��������Ϣ���浽�����ļ��У��첽����
	void saveWndBacks();
	// ������һ�α��洰����Ϣ���̣����ر�������Ƿ�ɹ�
	bool handleLastBack();

	// ��ʼ����ʾ����
	void initFrameWnd(wxMDIParentFrame* parent, const wxString& captionName, const wxPoint& position, const wxSize &size);
	// ��ʼ������ؼ�
	void initManageWnd();
	// ��ʼ����Ϣ����
	void initMsgHandle();

private:
	wxPanel *m_bench;

	// ���Ƹñ༭����ؼ��Ķ���
	std::unique_ptr<DrawControlManager> m_drawManager;
	// �����洢�����Ŀؼ�
	EditorAbstractWindow* const m_winMgr = nullptr;
	// ��ǰ�༭�Ŀؼ�
	EditorAbstractWindow* m_currentWnd = nullptr;
	// ��ǰ����ѡ�еĿؼ�ID
	std::unordered_set<ID_TYPE> m_selectWndIds;

private:
	// ��Ϣ�����¼
	bool m_mouseDown = false;

	// ʱ��ͳ�ƣ��������Լ����ʱ�䣬�Ϳ�ʼ����
	float m_calcTime = 0;
	// �޶���ʱ��
	float m_backupTime = 10;
	// ������ļ���
	wxString m_editFile;
	// ������¼������߳���Ϣ
	std::future<bool> m_saveThread;
	// �����������ڱ���Ķ���
	EditorSave* m_editorSave = nullptr;
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