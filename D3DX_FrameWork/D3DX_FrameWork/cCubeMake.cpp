#include "stdafx.h"
#include "cCubeMake.h"


cCubeMake::cCubeMake()
	: m_vLocalPos(0, 0, 0)
	, m_pParentWorldTM(NULL)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);
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
	D3DXMatrixIdentity(&m_matWorldTM);

	D3DXMATRIXA16	matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	m_matLocalTM = matR * matT;
	m_matWorldTM = m_matLocalTM;
	if (m_pParentWorldTM)
	{
		m_matWorldTM *= (*m_pParentWorldTM);
	}

	for each (auto p in m_vecChild)
	{
		p->Update();
	}
}
void cCubeMake::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));

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
}