#include "EditorWorkArea.h"
#include "../DrawEngine/d3dEngine.h"

EditorWorkArea::EditorWorkArea(wxMDIParentFrame* parent, const wxString& captionName = wxEmptyString, const wxPoint& position = wxDefaultPosition, const wxSize &size = wxDefaultSize)
	: WorkArea(parent)
{
	m_bench = new wxMDIChildFrame(parent, wxID_ANY, captionName, position, size);
	m_d3dEngine = new D3DEngine(getHandle(), D3DDEVTYPE_HAL, D3DCREATE_HARDWARE_VERTEXPROCESSING);
}

EditorWorkArea::~EditorWorkArea()
{
	delete m_d3dEngine;
}

// ����ÿ֡����
void EditorWorkArea::updateFrame(float dt)
{
	// �鿴�豸�Ƿ�ʧ
	if (m_d3dEngine->checkDeviceLost())
	{
		return;
	}

	updateScene(dt);
	drawScene();
}

// �������������µļ���
void EditorWorkArea::updateScene(float dt)
{
	
}

// ����ÿ֡����
void EditorWorkArea::drawScene()
{
	IDirect3DDevice9* d3dDevice = m_d3dEngine->getDevice();

	HR(d3dDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0));
	RECT formatRect;
	GetClientRect(getHandle(), &formatRect);

	HR(d3dDevice->BeginScene());

	//m_d3dEngine->getFont()->DrawText(0, _T("Hello Direct3D"), -1,
	//	&formatRect, DT_CENTER | DT_VCENTER,
	//	D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256));

	HR(d3dDevice->EndScene());
	HR(d3dDevice->Present(0, 0, 0, 0));
}

// ��ʼ��D3D��Ա
void EditorWorkArea::initD3DMember()
{

}
