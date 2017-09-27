#include "stdafx.h"
#include "cCubeMake.h"


cCubeMake::cCubeMake()
	: m_fRotY(0.0f)
	, m_vPosition(0, 0, 0)
	, m_vDirection(0, 0, 1)
{
}


cCubeMake::~cCubeMake()
{
}

void cCubeMake::Init(D3DXVECTOR3 temp)
{
	D3DXMatrixIdentity(&t_matS);
	VertexSet(0, temp, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(1, temp, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(2, temp, D3DCOLOR_XRGB(255, 0, 0));
	VertexSet(0, temp, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(2, temp, D3DCOLOR_XRGB(255, 0, 0)); VertexSet(3, temp, D3DCOLOR_XRGB(255, 0, 0));

	VertexSet(1, temp, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(0, temp, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(4, temp, D3DCOLOR_XRGB(0, 0, 0));
	VertexSet(1, temp, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(4, temp, D3DCOLOR_XRGB(0, 0, 0)); VertexSet(5, temp, D3DCOLOR_XRGB(0, 0, 0));

	VertexSet(2, temp, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(6, temp, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(7, temp, D3DCOLOR_XRGB(0, 255, 0));
	VertexSet(2, temp, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(7, temp, D3DCOLOR_XRGB(0, 255, 0)); VertexSet(3, temp, D3DCOLOR_XRGB(0, 255, 0));

	VertexSet(1, temp, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(5, temp, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(6, temp, D3DCOLOR_XRGB(0, 0, 155));
	VertexSet(1, temp, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(6, temp, D3DCOLOR_XRGB(0, 0, 155)); VertexSet(2, temp, D3DCOLOR_XRGB(0, 0, 155));

	VertexSet(0, temp, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(3, temp, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(7, temp, D3DCOLOR_XRGB(255, 0, 255));
	VertexSet(0, temp, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(7, temp, D3DCOLOR_XRGB(255, 0, 255)); VertexSet(4, temp, D3DCOLOR_XRGB(255, 0, 255));

	VertexSet(5, temp, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(4, temp, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(7, temp, D3DCOLOR_XRGB(255, 255, 255));
	VertexSet(5, temp, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(7, temp, D3DCOLOR_XRGB(255, 255, 255)); VertexSet(6, temp, D3DCOLOR_XRGB(255, 255, 255));

	Adjust();
}
void cCubeMake::Adjust()
{
}
void cCubeMake::Update()
{
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}

	D3DXMatrixIdentity(&m_matWorld);

	D3DXMATRIX	matS, matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);

	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	matS = t_matS;
	//matT += t_matT;
	m_matWorld = matS * matR * matT;
}
void cCubeMake::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));
}

void cCubeMake::VertexSet(int num, D3DXVECTOR3 temp, D3DCOLOR c)
{
	ST_PC_VERTEXT v;
	if (num == 0)
	{
		v.p = D3DXVECTOR3(temp.x - 2.f, temp.y - 2.f, temp.z - 2.f);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 1)
	{
		v.p = D3DXVECTOR3(temp.x - 2.f, temp.y, temp.z - 2.f);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 2)
	{
		v.p = D3DXVECTOR3(temp.x, temp.y, temp.z - 2.f);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 3)
	{
		v.p = D3DXVECTOR3(temp.x, temp.y - 2.f, temp.z - 2.f);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 4)
	{
		v.p = D3DXVECTOR3(temp.x - 2.f, temp.y - 2.f, temp.z);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 5)
	{
		v.p = D3DXVECTOR3(temp.x - 2.f, temp.y, temp.z);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 6)
	{
		v.p = D3DXVECTOR3(temp.x, temp.y, temp.z);
		v.c = c;
		m_vecVertex.push_back(v);
	}
	if (num == 7)
	{
		v.p = D3DXVECTOR3(temp.x, temp.y - 2.f, temp.z);
		v.c = c;
		m_vecVertex.push_back(v);
	}
}
