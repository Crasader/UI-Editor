#include "EditorApp.h"
#include "EditorFrame.h"
#include "DrawEngine\GameTimer.h"

// ���س����ʼ������
bool EditorApp::OnInit()
{
	// ���ø���ĳ�ʼ������
	if (!wxApp::OnInit())
		return false;

	m_editorFrame = new EditorFrame("UI Editor");
	m_editorFrame->SetSize(1080, 810);
	m_editorFrame->Center();

	// ��ʾ������
	m_editorFrame->Show(true);
	// ����Ϣ����ȡFrame������Ϣ
	Bind(DESTROY_EVENT, &EditorApp::handleFrameDestroy, this, m_editorFrame->GetId());

	// ��ʼ��ʱ��
	m_timer = new GameTimer();
	m_timer->reset();

	return true;
}

// ���س����˳�����
int EditorApp::OnExit()
{
	delete m_timer;
	return 0;
}

// this method is called by the active event loop when there are no events
// to process
bool EditorApp::ProcessIdle()
{
	bool ret = wxApp::ProcessIdle();
	// �������Ҫ�����Idle�¼�������D3D�������
	if (!ret)
	{
		do
		{
			// �鿴�ó����Ƿ�Ϊǰ̨����
			if (!IsActive())
			{
				Sleep(20);
				break;
			}
			m_timer->tick();
			if (m_editorFrame)
			{
				m_editorFrame->updateFrame(m_timer->deltaTime());
			}
		} while (0);
	}

	return ret;
}

// ������ȡFrame�����Ѿ������ٵ���Ϣ
void EditorApp::handleFrameDestroy(wxNotifyEvent & event)
{
	m_editorFrame = NULL;
}
