#include "stdafx.h"
#include "cThumb.h"


cThumb::cThumb()
	: angleY(0.0f)
	, angleMax(0.3f)
	, angleMin(-1.0f)
	, angleRe(true)
{
}


cThumb::~cThumb()
{
}

void cThumb::Init()
{
	cCubeMake::CubeInit();

	D3DXMATRIXA16 matS, matT,tempR, matWorld;
	D3DXMatrixScaling(&matS, 0.2f, 0.3f, 0.2f);
	D3DXMatrixTranslation(&matT, 1.3f, 2.8f, 0.0f);
	D3DXMatrixRotationZ(&tempR, -0.5f);
	matWorld = matS *tempR* matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}

void cThumb::ThumbGMotion()
{
	//cCubeMake::GrabMotion();
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);

	if (!(angleY >= angleMax))
	{
		angleY += 0.04f;
	}
	//else D3DXMatrixTranslation(&matMoveT, 0.0f, 0.0f, 1.0f);

	D3DXMatrixTranslation(&matMoveT, 0.0f, -3.5f, 0.0f);
	D3DXMatrixTranslation(&matOriginT, 0.0f, 3.5f, 0.0f);
	
	D3DXMatrixRotationY(&matR, angleY);
}

bool cThumb::Recover()
{
	//D3DXMatrixIdentity(&matR);
	//D3DXMatrixIdentity(&matMoveT);
	if (!(angleY < 0.0001f && angleY > -0.0001f))
	{
		if (angleY >= 0.0f) angleY -= 0.01f;
		else if (angleY <= 0.0f) angleY += 0.01f;

		D3DXMatrixTranslation(&matMoveT, 0.0f, -3.5f, 0.0f);
		D3DXMatrixTranslation(&matOriginT, 0.0f, 3.5f, 0.0f);
		D3DXMatrixRotationY(&matR, angleY);
		return false;
	}
	return true;
}
