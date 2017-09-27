#include "stdafx.h"
#include "cMainGame.h"
#include "cCube.h"
#include "cGrid.h"
#include "cCamera.h"


cMainGame::cMainGame()
	:m_pGrid(NULL)
	, m_pCamera(NULL)
{
}


cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCamera);
	g_pDeviceManager->Destroy();
}

void cMainGame::Init()
{

	/*
	ST_PC_VERTEXT v;
	v.p = D3DXVECTOR3(0, 0, 0);
	v.c = D3DCOLOR_XRGB(255, 0, 0);

	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 1, 0);
	v.c = D3DCOLOR_XRGB(0, 255, 0);

	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1, 0, 0);
	v.c = D3DCOLOR_XRGB(0, 0, 255);

	m_vecVertex.push_back(v);*/

	m_pCamera = new cCamera;
	m_pCamera->Init();

	m_pGrid = new cGrid;
	m_pGrid->Init();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{
	if (m_pCamera)
	{
		m_pCamera->Update();
	}


}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 0),
		1.0f, 0);

	g_pD3DDevice->BeginScene();

	// Draw
	/*D3DXMATRIXA16	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
	m_vecVertex.size() / 3,
	&m_vecVertex[0],
	sizeof(ST_PC_VERTEXT));*/


	if (m_pGrid)
	{
		m_pGrid->Render();
	}

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