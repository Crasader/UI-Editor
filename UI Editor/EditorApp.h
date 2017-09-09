#ifndef EDITOR_APP_H
#define EDITOR_APP_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class GameTimer;
class EditorFrame;

class EditorApp : public wxApp
{
public:
	// ���س����ʼ������
	bool OnInit() override;
	// ���س����˳�����
	int OnExit() override;

	// this method is called by the active event loop when there are no events
	// to process
	bool ProcessIdle() override;

private:
	// ������ȡFrame�����Ѿ������ٵ���Ϣ
	void handleFrameDestroy(wxNotifyEvent& event);

private:
	// ���ڼ���D3D��Ⱦ�¼�
	GameTimer* m_timer;
	// ����������
	EditorFrame* m_editorFrame;
};

#endif	// EDITOR_APP_H
