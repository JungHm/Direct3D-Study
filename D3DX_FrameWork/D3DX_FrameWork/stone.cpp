#include "stdafx.h"
#include "stone.h"


stone::stone()
{
	m_vDirection=D3DXVECTOR3(0, 0, 1);
}


stone::~stone()
{
	SAFE_RELEASE(stoneTexture);
	spMesh->Release();

}

void stone::Init()
{
	m_vPosition = D3DXVECTOR3(0, 0, 0);
	D3DXCreateTextureFromFile(g_pD3DDevice, L"stoneTexture.png", &stoneTexture);
	cCubeMake::CubeInit();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 3.0f, 3.0f, 3.0f);
	D3DXMatrixTranslation(&matT, 0.0f, -0.7f, 10.0f);

	matWorld = matS* matT;
	
	for (UINT i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
	stoneBox.scale = 1.0f;
	D3DXComputeBoundingSphere(&m_vecVertex[0].p, 36, D3DXGetFVFVertexSize(ST_PT_VERTEXT::FVF), &stoneBox.center, &stoneBox.radius);
	D3DXCreateSphere(g_pD3DDevice, stoneBox.radius, 20, 20, &spMesh, NULL);
}

void stone::Update()
{
	if (direction == 1)//FRONT
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
		m_vDirection = D3DXVECTOR3(0, 0, 1);
		stoneBox.center += m_vPosition;
	}
	else if (direction == 2)//BACK
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
		m_vDirection = D3DXVECTOR3(0, 0, 1);
		stoneBox.center += m_vPosition;
	}
	else if (direction == 3)//LEFT
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
		m_vDirection = D3DXVECTOR3(1, 0, 0);
		stoneBox.center += m_vPosition;
	}
	else if (direction == 4)//RIGHT
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
		m_vDirection = D3DXVECTOR3(1, 0, 0);
		stoneBox.center += m_vPosition;
	}
	else{ m_vDirection = D3DXVECTOR3(0, 0, 0); }

	D3DXMATRIXA16	matT;

	//D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorldTM = matT;
	//D3DXVec3TransformNormal(&stoneBox.center, &stoneBox.center, &matT);
}

void stone::Render()
{
	
	g_pD3DDevice->SetTexture(0, stoneTexture);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_PT_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEXT));

	D3DXMATRIXA16 matWorld, matScale, matTrans;
	D3DXMatrixTranslation(&matTrans, stoneBox.center.x, stoneBox.center.y, stoneBox.center.z);
	D3DXMatrixScaling(&matScale, stoneBox.scale, stoneBox.scale, stoneBox.scale);
	matWorld = matScale*matTrans;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	spMesh->DrawSubset(0);
	
}
