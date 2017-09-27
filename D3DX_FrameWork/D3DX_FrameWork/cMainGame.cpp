#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"


cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
	g_pDeviceManager->Destroy();
}

void cMainGame::Init()
{

	D3DXVECTOR3	vEye(0, 5, -5);
	D3DXVECTOR3	vLookAt(0, 0, 0);
	D3DXVECTOR3	vUp(0, 1, 0);
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DX_PI / 4.0f,
		rc.right / (float)rc.bottom,
		1.0f,
		1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

	tk = new tankMove;
	tk->Init();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

}

void cMainGame::Update()
{
	tk->Update();
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(155, 155, 155),
		1.0f, 0);

	g_pD3DDevice->BeginScene();

	tk->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::Relase()
{
	tk->Release();
	SAFE_DELETE(tk);
}

