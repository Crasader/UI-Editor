#include "EditorToolWindow.h"
#include "../ErrorHandle/ErrorHandle.h"
#include <wx/frame.h>
#include <cassert>

EditorToolWindow::EditorToolWindow(wxAuiManager &manager, wxWindow * parent, int direction, const wxString & paneName)
	: WorkArea(parent),
	m_auiManager(manager)
{
	// Ҫ��aui����Ĵ��ڣ��봫��ĸ�����Ϊͬһ������
	assert((m_auiManager.GetManagedWindow() == parent) && "the window managed by aui should be same with parent ");
	// �ڵ�����������ǰ����Ҫ��ʼ��m_bench��Ϊm_bench��������
	m_bench = new wxPanel(parent);
	m_auiManager.AddPane(m_bench, direction, paneName);
}

EditorToolWindow::~EditorToolWindow()
{
	assert(getBench() != nullptr);
}

// ��������ͣ������
void EditorToolWindow::setDirection(int direction)
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		myPaneInfo.Direction(direction);
		m_auiManager.Update();
	}
	else
	{
		throw ExtraException::unexpected_situation("myPaneInfo's IsOk() should be true.");
	}
}

// �������ñ���
void EditorToolWindow::setCaption(const wxString & captionName)
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		myPaneInfo.Caption(captionName);
		m_auiManager.Update();
	}
	else
	{
		throw ExtraException::unexpected_situation("myPaneInfo's IsOk() should be true.");
	}
}

// �������ø���ͣ������
void EditorToolWindow::setPanelInfo(const wxAuiPaneInfo & paneInfo)
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		myPaneInfo = paneInfo;
		m_auiManager.Update();
	}
	else
	{
		throw ExtraException::unexpected_situation("myPaneInfo's IsOk() should be true.");
	}
}

wxAuiPaneInfo & EditorToolWindow::getPanelInfo()
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		return myPaneInfo;
	}
	else
	{
		throw ExtraException::unexpected_situation("myPaneInfo's IsOk() should be true.");
		return myPaneInfo;
	}
}