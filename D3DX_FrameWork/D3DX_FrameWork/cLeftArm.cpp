#include "stdafx.h"
#include "cLeftArm.h"


cLeftArm::cLeftArm()
{
	Init(D3DXVECTOR3(-1.8f, 1.f, 1.f));
}


cLeftArm::~cLeftArm()
{
}

void cLeftArm::Adjust()
{
	D3DXMATRIX f_matS;

	D3DXMatrixScaling(&f_matS, 0.5f, 1.2f, 0.5f);
	D3DXMatrixIdentity(&m_matWorld);
	t_matS = f_matS;

}