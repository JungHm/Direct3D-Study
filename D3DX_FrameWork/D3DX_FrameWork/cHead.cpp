#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
{
	Init(D3DXVECTOR3(1.f, 5.f, 1.f));
}


cHead::~cHead()
{
}

void cHead::Adjust()
{
	D3DXMATRIX f_matS;

	D3DXMatrixScaling(&f_matS, 0.5f, 0.5f, 0.5f);
	D3DXMatrixIdentity(&m_matWorld);
	t_matS = f_matS;

}
