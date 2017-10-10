#include "stdafx.h"
#include "cWrist.h"


cWrist::cWrist()
{
}


cWrist::~cWrist()
{
}

void cWrist::Init()
{
	cCubeMake::Init();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.8f, 1.2f, 0.4f);
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);

	matWorld = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}
