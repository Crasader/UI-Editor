#include <cassert>
#include "FormToolWindow.h"
#include "../ErrorHandle/ErrorHandle.h"

FormToolWindow::FormToolWindow(wxAuiManager &manager, wxWindow * parent, int direction, const wxString & paneName)
	: WorkArea(parent),
	m_auiManager(manager)
{
	// Ҫ��aui����Ĵ��ڣ��봫��ĸ�����Ϊͬһ������
	assert((m_auiManager.GetManagedWindow() == parent) && "the window managed by aui should be same with parent ");
	// �ڵ�����������ǰ����Ҫ��ʼ��m_bench��Ϊm_bench��������
	m_bench = new wxPanel(parent);
	m_auiManager.AddPane(m_bench, direction, paneName);
}

FormToolWindow::~FormToolWindow()
{
	assert(getBench() != nullptr);
}

// ��������ͣ������
void FormToolWindow::setDirection(int direction)
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		myPaneInfo.Direction(direction);
		m_auiManager.Update();
	}
	else
	{
		throw ExtraExcept::unexpected_situation("myPaneInfo's IsOk() should be true.");
	}
}

// �������ñ���
void FormToolWindow::setCaption(const wxString & captionName)
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		myPaneInfo.Caption(captionName);
		m_auiManager.Update();
	}
	else
	{
		throw ExtraExcept::unexpected_situation("myPaneInfo's IsOk() should be true.");
	}
}

// �������ø���ͣ������
void FormToolWindow::setPaneInfo(const wxAuiPaneInfo & paneInfo)
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		myPaneInfo = paneInfo;
		m_auiManager.Update();
	}
	else
	{
		throw ExtraExcept::unexpected_situation("myPaneInfo's IsOk() should be true.");
	}
}

wxAuiPaneInfo & FormToolWindow::getPaneInfo()
{
	wxAuiPaneInfo& myPaneInfo = m_auiManager.GetPane(getBench());
	if (myPaneInfo.IsOk())
	{
		return myPaneInfo;
	}
	else
	{
		throw ExtraExcept::unexpected_situation("myPaneInfo's IsOk() should be true.");
		return myPaneInfo;
	}
}