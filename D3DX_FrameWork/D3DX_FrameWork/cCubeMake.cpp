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
	int a = 0;
}


void cCubeMake::AddChild(cCubeMake* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}
void cCubeMake::Destroy()
{
	for each (auto p in m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCubeMake::Init()
{
	ST_PC_VERTEXT	v;

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
}
void cCubeMake::Update()
{
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

	for each (auto p in m_vecChild)
	{
		p->Render();
	}
}