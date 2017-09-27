#include "stdafx.h"
#include "cMainGame.h"
#include "cGrid.h"
#include "cCamera.h"

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

cMainGame::cMainGame()
	: //m_pCube(NULL)
	  m_pGrid(NULL)
	, m_pCamera(NULL)
	, GridOn(true)
{
	
}

cMainGame::~cMainGame()
{
	//SAFE_DELETE(m_pCube);
	SAFE_DELETE(m_pBody);
	SAFE_DELETE(m_pHead);
	SAFE_DELETE(m_pLeftArm);
	SAFE_DELETE(m_pRightArm);
	SAFE_DELETE(m_pLeftLeg);
	SAFE_DELETE(m_pRightLeg);
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

	m_pBody = new cBody;
	m_pHead = new cHead;
	m_pLeftArm = new cLeftArm;
	m_pRightArm = new cRightArm;
	m_pLeftLeg = new cLeftLeg;
	m_pRightLeg = new cRightLeg;
	

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{
	if (m_pCamera)
	{
		m_pCamera->Update();
	}
	if (m_pBody)
	{
		m_pBody->Update();
		m_pHead->Update();
		m_pLeftArm->Update();
		m_pRightArm->Update();
		m_pLeftLeg->Update();
		m_pRightLeg->Update();

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

	// Draw
	/*D3DXMATRIX	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
	m_vecVertex.size() / 3,
	&m_vecVertex[0],
	sizeof(ST_PC_VERTEXT));*/


	if (m_pGrid && GridOn)
	{
		m_pGrid->Render();
	}
	if(m_pBody)
	{
		m_pBody->Render();
		m_pHead->Render();
		m_pLeftArm->Render();
		m_pRightArm->Render();
		m_pLeftLeg->Render();
		m_pRightLeg->Render();
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