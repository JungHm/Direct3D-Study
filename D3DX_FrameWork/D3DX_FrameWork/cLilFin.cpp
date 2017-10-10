#include "stdafx.h"
#include "cLilFin.h"


cLilFin::cLilFin()
	: angleY(0.0f)
	, angleMax(0.3f)
	, angleMin(-1.0f)
	, angleRe(true)
{
}


cLilFin::~cLilFin()
{
}

void cLilFin::Init()
{
	cCubeMake::CubeInit();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.2f, 0.3f, 0.2f);
	D3DXMatrixTranslation(&matT, -1.0f, 3.7f, 0.0f);

	matWorld = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}

void cLilFin::LilGMotion()
{
	//cCubeMake::GrabMotion();
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);

	if (!(angleY <= angleMin))
	{
		angleY -= 0.04f;
	}

	D3DXMatrixTranslation(&matMoveT, 0.0f, -3.5f, 0.0f);
	D3DXMatrixTranslation(&matOriginT, 0.0f, 3.5f, 0.0f);
	D3DXMatrixRotationX(&matR, angleY);
}

bool cLilFin::Recover()
{
	//D3DXMatrixIdentity(&matR);
	//D3DXMatrixIdentity(&matMoveT);
	if (!(angleY < 0.0001f && angleY > -0.0001f))
	{
		if (angleY >= 0.0f) angleY -= 0.01f;
		else if (angleY <= 0.0f) angleY += 0.01f;

		D3DXMatrixTranslation(&matMoveT, 0.0f, -3.5f, 0.0f);
		D3DXMatrixTranslation(&matOriginT, 0.0f, 3.5f, 0.0f);
		D3DXMatrixRotationX(&matR, angleY);
		return false;
	}
	return true;
}
