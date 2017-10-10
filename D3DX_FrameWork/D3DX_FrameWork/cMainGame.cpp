#include "stdafx.h"
#include "cMainGame.h"
#include "cCubeMake.h"
#include "cGrid.h"
#include "cCubeHand.h"
#include "cCubeMan.h"
#include "stone.h"

cMainGame::cMainGame()
	:m_pCubeMan(NULL)
	, m_pGrid(NULL)
	, m_pHand(NULL)
	, GridOn(true)
	, m_pD3DTexture(NULL)
	, isCollision(false)
{

}

cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pHand);
	SAFE_DELETE(m_pCubeMan);
	SAFE_DELETE(m_pStone);
	SAFE_RELEASE(m_pD3DTexture);
	g_pDeviceManager->Destroy();
	g_Cam->Release();
}

void cMainGame::Init()
{
	ST_PT_VERTEXT t;
	t.p = D3DXVECTOR3(0, 0, 0);
	t.t = D3DXVECTOR2(0, 1);
	m_vecTex.push_back(t);

	t.p = D3DXVECTOR3(0, 2, 0);
	t.t = D3DXVECTOR2(0, 0);
	m_vecTex.push_back(t);

	t.p = D3DXVECTOR3(3, 2, 0);
	t.t = D3DXVECTOR2(1, 0);
	m_vecTex.push_back(t);
	//tex0
	t.p = D3DXVECTOR3(0, 0, 0);
	t.t = D3DXVECTOR2(0, 1);
	m_vecTex1.push_back(t);

	t.p = D3DXVECTOR3(3, 2, 0);
	t.t = D3DXVECTOR2(1, 0);
	m_vecTex1.push_back(t);

	t.p = D3DXVECTOR3(3, 0, 0);
	t.t = D3DXVECTOR2(1, 1);
	m_vecTex1.push_back(t);





	m_pHand = new cCubeHand;
	m_pHand->Init();


	m_pGrid = new cGrid;
	m_pGrid->Init(50);
	D3DXCreateTextureFromFile(g_pD3DDevice, L"aa.png", &m_pD3DTexture);

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Init();

	m_pStone = new stone;
	m_pStone->Init();


	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{
	g_Cam->Update();
	//isCollision = SphereIntersect(g_Cam->GetDistance(), 1.4f, m_pStone->GetCollision().center, m_pStone->GetCollision().radius);
	//if (isCollision) { m_pStone->SetDirection(m_pCubeMan->GetDirection()); }
	//if (m_pStone) m_pStone->Update();

	if (m_pCubeMan && m_pHand)
	{
		//m_pCubeMan->Update();
		m_pHand->Update();
	}
	//if (m_pHand) m_pHand->Update();

	if (GetAsyncKeyState('1') & 0x0001) GridOn = (GridOn) ? false : true;


}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(255, 255, 255),
		1.0f, 0);

	g_pD3DDevice->BeginScene();
	g_pD3DDevice->SetFVF(ST_PT_VERTEXT::FVF);

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetTexture(0, m_pD3DTexture);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTex.size() / 3, &m_vecTex[0], sizeof(ST_PT_VERTEXT));
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTex1.size() / 3, &m_vecTex1[0], sizeof(ST_PT_VERTEXT));

	if (m_pCubeMan&&m_pHand)
	{
		//g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		//m_pCubeMan->Render();
		m_pHand->Render();
	}
	//if (m_pStone) { m_pStone->Render(); }
	

	g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	if (m_pGrid&&GridOn)
	{
		m_pGrid->Render();
	}
	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

bool cMainGame::SphereIntersect(D3DXVECTOR3 vCenter1, float fRadius1, D3DXVECTOR3 vCenter2, float fRadius2)
{
	float fDistance;
	D3DXVECTOR3 vDiff;

	vDiff = vCenter2 - vCenter1;
	fDistance = D3DXVec3Length(&vDiff);

	if (fDistance <= (fRadius1 + fRadius2))
	{
		return true;
	}
	return false;
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	g_Cam->WndProc(hWnd, message, wParam, lParam);
}