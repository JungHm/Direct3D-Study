#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
{
}


cHead::~cHead()
{
}

{

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.8f, 0.8f, 0.8f);
	D3DXMatrixTranslation(&matT, 0.0f, 2.0f, 0.0f);

}
	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}