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

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
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
