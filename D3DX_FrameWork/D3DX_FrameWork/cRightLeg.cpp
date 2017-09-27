#include "stdafx.h"
#include "cRightLeg.h"


cRightLeg::cRightLeg()
{
	Init(D3DXVECTOR3(2.6f, -1.2f, 1.f));
}


cRightLeg::~cRightLeg()
{
}

void cRightLeg::Adjust()
{
	D3DXMATRIX f_matS;

	D3DXMatrixScaling(&f_matS, 0.3f, 1.2f, 0.5f);
	D3DXMatrixIdentity(&m_matWorld);
	t_matS = f_matS;
}
