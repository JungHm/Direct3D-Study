#include "stdafx.h"
#include "cMainGame.h"


cMainGame::cMainGame() 
	: m_pD3D(NULL), m_pD3Ddevice(NULL)
{
}


cMainGame::~cMainGame()
{
	m_pD3D->Release();
	m_pD3Ddevice->Release();
}

void cMainGame::Init()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9 d3dCaps;
	int nVertexProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);
	if (d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(D3DPRESENT_PARAMETERS));
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;//가장 효율적인 스왑방식 
	d3dPP.Windowed = TRUE;
	d3dPP.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dPP.EnableAutoDepthStencil = TRUE;
	d3dPP.AutoDepthStencilFormat = D3DFMT_D16;
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing, &d3dPP,
		&m_pD3Ddevice);//device 생성

}

void cMainGame::Update()
{
}

void cMainGame::Render()
{
	m_pD3Ddevice->Clear(NULL, NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 255),
		1.0F, 0);

	m_pD3Ddevice->BeginScene();

	//Draw

	m_pD3Ddevice->EndScene();

	m_pD3Ddevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::Relase()
{
}
