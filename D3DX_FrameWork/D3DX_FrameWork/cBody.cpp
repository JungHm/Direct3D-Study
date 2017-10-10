#include "stdafx.h"
#include "cBody.h"


cBody::cBody()
{
}


cBody::~cBody()
{
	SAFE_RELEASE(spMesh); 
}

void cBody::Init()
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
	manBox.scale = 1.4f;
	D3DXComputeBoundingSphere(&m_vecVertex[0].p, 36, D3DXGetFVFVertexSize(ST_PT_VERTEXT::FVF), &manBox.center, &manBox.radius);
	D3DXCreateSphere(g_pD3DDevice, manBox.radius, 20, 20, &spMesh, NULL);
}

void cBody::Update()
{
	cCubeMake::Update();
	manBox.center = g_Cam->GetDistance();
}


void cBody::Render()
{

	cCubeMake::Render();

	/*D3DXMATRIXA16 matWorld, matScale, matTrans;
	D3DXMatrixTranslation(&matTrans, manBox.center.x, manBox.center.y, manBox.center.z);
	D3DXMatrixScaling(&matScale, manBox.scale, manBox.scale, manBox.scale);
	matWorld = matScale*matTrans;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	spMesh->DrawSubset(0);*/
}

void cBody::Destroy()
{
}
