#include "stdafx.h"
#include "cLeftLeg.h"


cLeftLeg::cLeftLeg()
{
	Init(D3DXVECTOR3(-0.9f, -1.2f, 1.f));
}


cLeftLeg::~cLeftLeg()
{
}

void cLeftLeg::Adjust()
{
	D3DXMATRIX f_matS;

	D3DXMatrixScaling(&f_matS, 0.3f, 1.2f, 0.5f);
	D3DXMatrixIdentity(&m_matWorld);
	t_matS = f_matS;
}
