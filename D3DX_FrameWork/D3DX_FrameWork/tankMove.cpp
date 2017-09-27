#include "stdafx.h"
#include "tankMove.h"


tankMove::tankMove()
	:angleY(0.0f), vecMove(0, 0, 0.1f), cubeMove(0, 0, 0),
	isClick(false)
{
}


tankMove::~tankMove()
{
}

void tankMove::Init()
{
	D3DXMatrixIdentity(&matWorld); D3DXMatrixIdentity(&matTrans); D3DXMatrixIdentity(&matRotate); D3DXMatrixIdentity(&matGrWorld); D3DXMatrixIdentity(&matMouseRot);

	vEye.x = 0; vEye.y = 5; vEye.z = -15;
	vLookAt.x = 0; vLookAt.y = 0; vLookAt.z = 0;
	vUp.x = 0; vUp.y = 1; vUp.z = 0;
	gEye = vEye; gLookAt = vLookAt;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);


	RECT rc;
	GetClientRect(g_hWnd, &rc);
	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DX_PI / 4.0f,
		rc.right / (float)rc.bottom,
		1.0f,
		1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

	VertexSet(0, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(1, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(2, D3DCOLOR_XRGB(255, 0, 0));
	VertexSet(0, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(2, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(3, D3DCOLOR_XRGB(255, 0, 0));

	VertexSet(1, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(0, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(4, D3DCOLOR_XRGB(0, 0, 0));
	VertexSet(1, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(4, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(5, D3DCOLOR_XRGB(0, 0, 0));

	VertexSet(2, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(6, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(7, D3DCOLOR_XRGB(0, 255, 0));
	VertexSet(2, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(7, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(3, D3DCOLOR_XRGB(0, 255, 0));

	VertexSet(1, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(5, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(6, D3DCOLOR_XRGB(0, 0, 155));
	VertexSet(1, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(6, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(2, D3DCOLOR_XRGB(0, 0, 155));

	VertexSet(0, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(3, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(7, D3DCOLOR_XRGB(255, 0, 255));
	VertexSet(0, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(7, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(4, D3DCOLOR_XRGB(255, 0, 255));

	VertexSet(5, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(4, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(7, D3DCOLOR_XRGB(255, 255, 255));
	VertexSet(5, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(7, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(6, D3DCOLOR_XRGB(255, 255, 255));

	ST_PC_VERTEXT v;
	for (int i = -10; i < 10; i++)
	{
		v.p = D3DXVECTOR3(-10, -1, i);
		m_gridVertex.push_back(v);
		v.p = D3DXVECTOR3(10, -1, i);
		m_gridVertex.push_back(v);

		v.p = D3DXVECTOR3(i, -1, 10);
		m_gridVertex.push_back(v);
		v.p = D3DXVECTOR3(i, -1, -10);
		m_gridVertex.push_back(v);
	}

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void tankMove::Release()
{
}

void tankMove::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		vecMove.x = 0; vecMove.y = 0, vecMove.z = 0.1f;
		angleY -= 0.05f;
		D3DXMATRIXA16 tempMat;
		D3DXMatrixRotationY(&tempMat, angleY);
		D3DXVec3TransformNormal(&vecMove, &vecMove, &tempMat);
		D3DXMatrixRotationY(&matRotate, angleY);

	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		vecMove.x = 0; vecMove.y = 0, vecMove.z = 0.1f;
		angleY += 0.05f;
		D3DXMATRIXA16 tempMat;
		D3DXMatrixRotationY(&tempMat, angleY);
		D3DXVec3TransformNormal(&vecMove, &vecMove, &tempMat);
		D3DXMatrixRotationY(&matRotate, angleY);
	}
	//mouse rotate
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		vecMove.x = 0; vecMove.y = 0, vecMove.z = 0.1f;
		D3DXMatrixRotationYawPitchRoll(&matMouseRot, m_vCamRotAngle.y, m_vCamRotAngle.x, 0);
		D3DXVec3TransformNormal(&vecMove, &vecMove, &matMouseRot);
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		cubeMove += vecMove;
		D3DXMatrixTranslation(&matTrans, cubeMove.x, cubeMove.y, cubeMove.z);
		vEye = gEye + cubeMove; vLookAt = gLookAt + cubeMove;
		D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
		g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		cubeMove -= vecMove;
		D3DXMatrixTranslation(&matTrans, cubeMove.x, cubeMove.y, cubeMove.z);
		vEye = gEye + cubeMove; vLookAt = gLookAt + cubeMove;
		D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
		g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
	}

	matWorld = matMouseRot*matRotate * matTrans;
}

void tankMove::Render()
{
	// Draw
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		12,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));

	//GRID
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matGrWorld);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,
		m_gridVertex.size() / 2,
		&m_gridVertex[0],
		sizeof(ST_PC_VERTEXT));
}

void tankMove::VertexSet(int num, D3DCOLOR c)
{
	ST_PC_VERTEXT v;
	if (num == 0)
	{
		v.p = D3DXVECTOR3(-1, -1, -1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 1)
	{
		v.p = D3DXVECTOR3(-1, 1, -1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 2)
	{
		v.p = D3DXVECTOR3(1, 1, -1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 3)
	{
		v.p = D3DXVECTOR3(1, -1, -1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 4)
	{
		v.p = D3DXVECTOR3(-1, -1, 1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 5)
	{
		v.p = D3DXVECTOR3(-1, 1, 1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 6)
	{
		v.p = D3DXVECTOR3(1, 1, 1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 7)
	{
		v.p = D3DXVECTOR3(1, -1, 1);
		v.c = c;
		m_vecVertex.push_back(v);
	}
}
