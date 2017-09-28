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

	for (int i = 0; i < m_vecVertex.size(); i++)
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
	D3DXMatrixTranslation(&matMoveT, 0, -0.6, 0); 
	D3DXMatrixTranslation(&matOriginT, 0, 0.6, 0);
	D3DXMatrixRotationX(&matR, angleY);
}