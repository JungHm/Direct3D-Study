#include "stdafx.h"
#include "cPalm.h"


cPalm::cPalm()
	: angleY(0.0f)
	, angleMax(0.3f)
	, angleMin(-0.3f)
	, angleRe(true)
{
}


cPalm::~cPalm()
{
}

void cPalm::Init()
{
	cCubeMake::CubeInit();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 1.3f, 0.5f, 0.4f);
	D3DXMatrixTranslation(&matT, 0.0f, 2.0f, 0.0f);

	matWorld = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}

void cPalm::FanMotion()
{
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);

	if (angleY >= angleMax)
	{
		angleRe = false;
	}
	else if (angleY <= angleMin)
	{
		angleRe = true;
	}

	if (angleRe) angleY += 0.06f;
	else angleY -= 0.06f;
	D3DXMatrixTranslation(&matMoveT, 0.f, -0.6f, 0.f);
	D3DXMatrixTranslation(&matOriginT, 0.f, 0.6f, 0.f);
	D3DXMatrixRotationX(&matR, angleY);
}

bool cPalm::Recover()
{
	//D3DXMatrixIdentity(&matR);
	//D3DXMatrixIdentity(&matMoveT);
	if (!(angleY < 0.0001f && angleY > -0.0001f))
	{
		if (angleY >= 0.0f) angleY -= 0.01f;
		else if (angleY <= 0.0f) angleY += 0.01f;
		D3DXMatrixTranslation(&matMoveT, 0.f, -0.6f, 0.f);
		D3DXMatrixTranslation(&matOriginT, 0.f, 0.6f, 0.f);
		D3DXMatrixRotationX(&matR, angleY);
		return false;
	}
	return true;
}

void cPalm::HelloMotion()
{
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);

	if (angleY >= angleMax)
	{
		angleRe = false;
	}
	else if (angleY <= angleMin)
	{
		angleRe = true;
	}

	if (angleRe) angleY += 0.02f;
	else angleY -= 0.02f;
	D3DXMatrixTranslation(&matMoveT, 0.f, -0.6f, 0.f);
	D3DXMatrixTranslation(&matOriginT, 0.f, 0.6f, 0.f);
	D3DXMatrixRotationZ(&matR, angleY);
}
