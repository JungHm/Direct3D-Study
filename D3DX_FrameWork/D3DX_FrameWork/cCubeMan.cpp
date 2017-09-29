#include "stdafx.h"
#include "cCubeMan.h"

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cLeftArmS.h"
#include "cRightArm.h"
#include "cRightArmS.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"
#include "cRightLegS.h"
#include "cLeftLegS.h"



cCubeMan::cCubeMan()
	: m_pRoot(NULL)
{
}


cCubeMan::~cCubeMan()
{
	SAFE_DELETE(m_pRoot);
}


void cCubeMan::Init()
{
	m_fRotY = m_vPosition.x = m_vPosition.y = m_vPosition.z = 0;
	cBody* pBody = new cBody;
	pBody->Init();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->Init();
	m_pRoot->AddChild(pHead);

	cLeftArm* pLeftArm = new cLeftArm;
	pLeftArm->Init();
	m_pRoot->AddChild(pLeftArm);
	

	cLeftArmS* pLeftArmS = new cLeftArmS;
	pLeftArmS->Init();
	pLeftArm->AddChild(pLeftArmS);//¹ØÆÈºÎ¸ğ¸¦ À­ÆÈ·Î
	

	cRightArm* pRightArm = new cRightArm;
	pRightArm->Init();
	m_pRoot->AddChild(pRightArm);
	

	cRightArmS* pRightArmS = new cRightArmS;
	pRightArmS->Init();
	pRightArm->AddChild(pRightArmS);
	

	cLeftLeg* pLeftLeg = new cLeftLeg;
	pLeftLeg->Init();
	m_pRoot->AddChild(pLeftLeg);
	

	cLeftLegS* pLeftLegS = new cLeftLegS;
	pLeftLegS->Init();
	pLeftLeg->AddChild(pLeftLegS);
	

	cRightLeg* pRightLeg = new cRightLeg;
	pRightLeg->Init();
	m_pRoot->AddChild(pRightLeg);
	

	cRightLegS* pRightLegS = new cRightLegS;
	pRightLegS->Init();
	pRightLeg->AddChild(pRightLegS);
	
}
void cCubeMan::Update()
{
	m_pRoot->SetcMotion(IDLE);

	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
		m_pRoot->SetcMotion(0);
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
		m_pRoot->SetcMotion(0);
	}

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
		m_pRoot->SetcMotion(MOVE);
	}

	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
		m_pRoot->SetcMotion(MOVE);

	}


	
	
	D3DXMATRIXA16	matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;

	if (m_pRoot)
	{
		m_pRoot->Update();
	}
}
void cCubeMan::Render()
{
	//g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);

	if (m_pRoot)
	{
		m_pRoot->Render();
	}
}