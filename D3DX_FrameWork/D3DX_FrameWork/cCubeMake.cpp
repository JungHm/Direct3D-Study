#include "stdafx.h"
#include "cCubeMake.h"


cCubeMake::cCubeMake()
	: m_vLocalPos(0, 0, 0)
	, m_pParentWorldTM(NULL)
	, motionNum(0)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);

	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);
	D3DXMatrixIdentity(&matOriginT);


}


cCubeMake::~cCubeMake()
{
}


void cCubeMake::AddChild(cCubeMake* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}
void cCubeMake::Destroy()
{
	for each (auto p in m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCubeMake::Init()
{
	//D3DXCreateTextureFromFile(g_pD3DDevice, L"steve.png", &steveTex);
	ST_PT_VERTEXT	v;
	y = 1.0f;

	//	front
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);  m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);		 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);  m_vecVertex.push_back(v);

	//	back
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, 1.0f);				 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, 1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				 m_vecVertex.push_back(v);

	//	left
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, 1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);			 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);	 m_vecVertex.push_back(v);


	//	right
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);			 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, 1.0f);	 m_vecVertex.push_back(v);

	//	top
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, 1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);			 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);			 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);			 m_vecVertex.push_back(v);

	//	bottom
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f); 				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);				 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -y, 1.0f);						 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -y, -1.0f);						 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -y, 1.0f);		 				 m_vecVertex.push_back(v);
}
void cCubeMake::CubeInit()
{
	ST_PT_VERTEXT	v;
	y = 1.0f;
	//	front
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(0.5f, 0.5f);  m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.5f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);				v.t = D3DXVECTOR2(1.0f, 0.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(0.5f, 0.5f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);				v.t = D3DXVECTOR2(1.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(1.0f, 0.5f);  m_vecVertex.push_back(v);

	//	back
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.5f, 1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.5f, 0.5f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.0f, 0.5f);		 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.5f, 1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.0f, 1.0f);		 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.0f, 0.5f);		 m_vecVertex.push_back(v);

	//	left
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.0f, 1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.0f, 0.5f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.5f, 0.5f);	 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.0f, 1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.5f, 0.5f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(0.5f, 1.0f);	 m_vecVertex.push_back(v);


	//	right
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(0.0f, 1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.0f, 0.5f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.5f, 0.5f);	 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(0.0f, 1.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.5f, 0.5f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.5f, 1.0f);	 m_vecVertex.push_back(v);

	//	top
	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.f, 0.5f); 	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.0f, 0.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.5f, 0.0f);	 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.5f, 0.0f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, 1.0f);				v.t = D3DXVECTOR2(0.5f, 0.5f);	 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y, -1.0f);				v.t = D3DXVECTOR2(0.f, 0.5f); 	 m_vecVertex.push_back(v);

	//	bottom
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, 1.0f);		v.t = D3DXVECTOR2(0.5f, 1.0f); 				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(0.5f, 0.5f);				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, y - 2.0f, -1.0f);		v.t = D3DXVECTOR2(1.0f, 0.5f);				 m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -y, 1.0f);				v.t = D3DXVECTOR2(0.5f, 1.0f);				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -y, -1.0f);				v.t = D3DXVECTOR2(1.0f, 0.5f);				 m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -y, 1.0f);				v.t = D3DXVECTOR2(1.0f, 1.0f); 				 m_vecVertex.push_back(v);
}
void cCubeMake::Update()
{
	D3DXMatrixIdentity(&m_matWorldTM);


	//D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);


	m_matLocalTM = matMoveT * matR * matT *matOriginT;
	m_matWorldTM = m_matLocalTM;
	if (m_pParentWorldTM)
	{
		m_matWorldTM *= (*m_pParentWorldTM);
	}

	for each (auto p in m_vecChild)
	{
		switch (motionNum)
		{
		case IDLE:
			if (p->Recover()) p->IdleMotion();
			break;
		case MOVE:
			p->MoveMotion();
			break;
		case PUSH:
			p->PushMotion();
			break;
		case GRAB_ALL:
			p->GrabMotion();
			break;
		case HELLO:
			p->HelloMotion();
			break;
		case SCISSORS_G:
			p->ScissorG();
			break;
		case FAN:
			p->FanMotion();
			break;
		case THUMB_G:
			p->ThumbGMotion();
			break;
		case INDEX_G:
			p->IndexGMotion();
			break;
		case MID_G:
			p->MidGMotion();
			break;
		case RING_G:
			p->RingGMotion();
			break;
		case LIL_G:
			p->LilGMotion();
			break;
		/*default:
			D3DXMatrixIdentity(&matMoveT);
			D3DXMatrixIdentity(&matOriginT);
			break;*/
		}
		p->Update();
		if (p->m_vecChild.size() != 0) ChildUpdate(p->m_vecChild);
	}
}
void cCubeMake::Render()
{

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_PT_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEXT));

	for each (auto p in m_vecChild)
	{
		p->Render();
	}
}

void cCubeMake::ChildUpdate(std::vector<cCubeMake*> p)
{
	for each(auto c in p)
	{
		switch (motionNum)
		{
		case IDLE:
			if (c->Recover()) c->IdleMotion();
			break;
		case MOVE:
			c->MoveMotion();
			break;
		case PUSH:
			c->PushMotion();
			break;
		case GRAB_ALL:
			c->GrabMotion();
			break;
		case HELLO:
			c->HelloMotion();
			break;
		case SCISSORS_G:
			c->ScissorG();
			break;
		case FAN:
			c->FanMotion();
			break;
		case THUMB_G:
			c->ThumbGMotion();
			break;
		case INDEX_G:
			c->IndexGMotion();
			break;
		case MID_G:
			c->MidGMotion();
			break;
		case RING_G:
			c->RingGMotion();
			break;
		case LIL_G:
			c->LilGMotion();
			break;
		default:
			D3DXMatrixIdentity(&matMoveT);
			D3DXMatrixIdentity(&matOriginT);
			break;
		}
		c->Update();
		if (c->m_vecChild.size() == 0) return;
		else ChildUpdate(c->m_vecChild);
	}

	




}

