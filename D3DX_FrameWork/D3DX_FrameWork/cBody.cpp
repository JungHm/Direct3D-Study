#include "stdafx.h"
#include "cBody.h"


cBody::cBody()
{
	Init(D3DXVECTOR3(1, 1, 1));
}


cBody::~cBody()
{
}

void cBody::Adjust()
{
	D3DXMATRIX f_matS;

	D3DXMatrixScaling(&f_matS, 1.2f, 1.6f, 1.0f);
	D3DXMatrixIdentity(&m_matWorld);
	t_matS = f_matS;
}
