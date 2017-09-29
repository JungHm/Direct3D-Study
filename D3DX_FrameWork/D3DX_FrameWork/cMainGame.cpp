#include "stdafx.h"
#include "cMainGame.h"
#include "cCubeMake.h"
#include "cGrid.h"
#include "cCamera.h"
#include "cCubeMan.h"

cMainGame::cMainGame()
	:m_pCubeMan(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL)
	, GridOn(true)
	, m_pD3DTexture(NULL)
{

}

cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pCubeMan);
	SAFE_RELEASE(m_pD3DTexture);
	g_pDeviceManager->Destroy();
}

void cMainGame::Init()
{
	ST_PT_VERTEXT t;
	t.p = D3DXVECTOR3(0, 0, 0);
	t.t = D3DXVECTOR2(0, 0);
	m_vecTex.push_back(t);

	t.p = D3DXVECTOR3(0, 1, 0);
	t.t = D3DXVECTOR2(1, 0);
	m_vecTex.push_back(t);

	t.p = D3DXVECTOR3(1, 0, 0);
	t.t = D3DXVECTOR2(0, 1);
	m_vecTex.push_back(t);

	D3DXCreateTextureFromFile(g_pD3DDevice, L"aa.png", &m_pD3DTexture);
	

	m_pCamera = new cCamera;
	m_pCamera->Init();


	m_pGrid = new cGrid;
	m_pGrid->Init();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Init();



	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{
	if (m_pCamera)
	{
		m_pCamera->Update();
	}

	if (m_pCubeMan)
	{
		m_pCubeMan->Update();
	}
	if (GetAsyncKeyState('1') & 0x0001) GridOn = (GridOn) ? false : true;


}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 0),
		1.0f, 0);

	g_pD3DDevice->BeginScene();
	g_pD3DDevice->SetFVF(ST_PT_VERTEXT::FVF);

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetTexture(0, m_pD3DTexture);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTex.size() / 3, &m_vecTex[0], sizeof(ST_PT_VERTEXT));


	//if (m_pGrid&&GridOn)
	//{
	//	m_pGrid->Render();
	//}
	//if (m_pCubeMan)
	//{
	//	m_pCubeMan->Render();
	//}


	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
	{
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
	}
}