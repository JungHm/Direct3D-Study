#include "stdafx.h"
#include "cRightArm.h"


cRightArm::cRightArm()
	: angleY(0.0f)
	, angleMax(0.6f)
	, angleMin(-0.6f)
	, angleRe(false)
{
}


cRightArm::~cRightArm()
{
}


void cRightArm::Init()
{
	cCubeMake::Init();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.4f);
	D3DXMatrixTranslation(&matT, 1.2f, 0.6f, 0.0f);
	D3DXMatrixIdentity(&matWorld);
	matWorld = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}

void cRightArm::MoveMotion()
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

	if (angleRe) angleY += 0.04f;
	else angleY -= 0.04f;
	D3DXMatrixTranslation(&matMoveT, 0.f, -0.6f, 0.f); 
	D3DXMatrixTranslation(&matOriginT, 0.f, 0.6f, 0.f);
	D3DXMatrixRotationX(&matR, angleY);
}

bool cRightArm::Recover()
{
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);
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
