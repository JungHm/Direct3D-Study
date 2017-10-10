#include "stdafx.h"
#include "cLeftArmS.h"


cLeftArmS::cLeftArmS()
	: angleY(0.0f)
	, angleMax(0.0f)
	, angleMin(-0.7f)
	, angleRe(true)
{
}


cLeftArmS::~cLeftArmS()

{
}

void cLeftArmS::Init()
{
	cCubeMake::Init();
	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.4f);
	D3DXMatrixTranslation(&matT, -1.2f, -0.6f, 0.0f);

	matWorld = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}

void cLeftArmS::MoveMotion()
{
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);

	if (angleY > angleMax)
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
	D3DXMatrixRotationX(&matR, angleY);
}

bool cLeftArmS::Recover()
{
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

