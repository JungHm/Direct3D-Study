#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
	: angleY(0.0f)
	, angleMax(0.6f)
	, angleMin(-0.6f)
	, angleRe(true)
{
}


cHead::~cHead()
{
}

void cHead::Init()
{
	cCubeMake::Init();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.8f, 0.8f, 0.8f);
	D3DXMatrixTranslation(&matT, 0.0f, 2.0f, 0.0f);
	D3DXMatrixIdentity(&matWorld);
	matWorld = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
	m_vecVertex[0].t = D3DXVECTOR2(0.375f, 0.25f);
	m_vecVertex[1].t = D3DXVECTOR2(0.375f, 0.125f);
	m_vecVertex[2].t = D3DXVECTOR2(0.5f, 0.125f);

	m_vecVertex[3].t = D3DXVECTOR2(0.375f, 0.25f);
	m_vecVertex[4].t = D3DXVECTOR2(0.5f, 0.125f);
	m_vecVertex[5].t = D3DXVECTOR2(0.5f, 0.25f);
	//
	m_vecVertex[6].t = D3DXVECTOR2(0.125f, 0.25f);
	m_vecVertex[7].t = D3DXVECTOR2(0.125f, 0.125f);
	m_vecVertex[8].t = D3DXVECTOR2(0.25f, 0.125f);

	m_vecVertex[9].t = D3DXVECTOR2(0.125f, 0.25f);
	m_vecVertex[10].t = D3DXVECTOR2(0.25f, 0.125f);
	m_vecVertex[11].t = D3DXVECTOR2(0.25f, 0.25f);
	//
	m_vecVertex[12].t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex[13].t = D3DXVECTOR2(0.25f, 0.125f);
	m_vecVertex[14].t = D3DXVECTOR2(0.375f, 0.125f);

	m_vecVertex[15].t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex[17].t = D3DXVECTOR2(0.375f, 0.125f);
	m_vecVertex[16].t = D3DXVECTOR2(0.375f, 0.25f);
}

void cHead::IdleMotion()
{
	D3DXMatrixIdentity(&matR);

	if (angleY >= angleMax)
	{
		angleRe = false;
	}
	else if (angleY <= angleMin)
	{
		angleRe = true;
	}

	if (angleRe) angleY += 0.05f;
	else angleY -= 0.05f;

	D3DXMatrixRotationY(&matR, angleY);
}
