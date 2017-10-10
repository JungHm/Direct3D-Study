#include "stdafx.h"
#include "cGrid.h"


cGrid::cGrid()
	:GridTexture(NULL)
	, fY(-3.55F)
{
}


cGrid::~cGrid()
{
	SAFE_RELEASE(GridTexture);
}

void cGrid::Init(int nNumHalfTile, float fInterval)
{
	fMax = nNumHalfTile * fInterval;
	fMin = -nNumHalfTile * fInterval;

	D3DXCreateTextureFromFile(g_pD3DDevice, L"bb.jpg", &GridTexture);

	ST_PC_VERTEXT v;

	for (int i = 1; i <= nNumHalfTile; i++)
	{
		v.c = D3DCOLOR_XRGB(255, 255, 255);
		v.p = D3DXVECTOR3(fMin, -3.55F, i * fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, -3.55F, i * fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(fMin, -3.55F, -i * fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, -3.55F, -i * fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-i * fInterval, -3.55F, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * fInterval, -3.55F, fMax);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(i * fInterval, -3.55F, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i * fInterval, -3.55F, fMax);

		m_vecVertex.push_back(v);
	}

	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(fMin, 0, 0);	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0);	m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, fMin, 0);	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, fMax, 0);	m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, fMin);	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax);	m_vecVertex.push_back(v);



	FloorTextureInit();



}
void cGrid::Render()
{
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	//g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	//g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecVertex.size() / 2, &m_vecVertex[0], sizeof(ST_PC_VERTEXT));

	g_pD3DDevice->SetFVF(ST_PT_VERTEXT::FVF);
	g_pD3DDevice->SetTexture(0, GridTexture);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_texVertex.size() / 3, &m_texVertex[0], sizeof(ST_PT_VERTEXT));
}

void cGrid::FloorTextureInit()
{
	ST_PT_VERTEXT p;
	p.p = D3DXVECTOR3(0, fY, 0);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, fMax);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(fMax, fY, 0);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, 0);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, -fMax);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(-fMax, fY, 0);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, 0);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(-fMax, fY, 0);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, fMax);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, 0);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(fMax, fY, 0);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, -fMax);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(fMax, fY, fMax);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(fMax, fY, 0);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, fMax);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(-fMax, fY, fMax);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, fMax);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(-fMax, fY, 0);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(fMax, fY, -fMax);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, -fMax);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(fMax, fY, 0);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);


	p.p = D3DXVECTOR3(-fMax, fY, -fMax);
	p.t = D3DXVECTOR2(0, 1);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(-fMax, fY, 0);
	p.t = D3DXVECTOR2(1, 0);
	m_texVertex.push_back(p);

	p.p = D3DXVECTOR3(0, fY, -fMax);
	p.t = D3DXVECTOR2(0, 0);
	m_texVertex.push_back(p);




}
