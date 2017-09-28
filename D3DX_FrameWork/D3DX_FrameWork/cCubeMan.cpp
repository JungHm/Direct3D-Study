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
	m_pRoot = pLeftArm;//À­ÆÈÀ» ·çÆ®·Î

	cLeftArmS* pLeftArmS = new cLeftArmS;
	pLeftArmS->Init();
	m_pRoot->AddChild(pLeftArmS);//¹ØÆÈºÎ¸ğ¸¦ À­ÆÈ·Î
	m_pRoot = pBody;//´Ù½Ã ¹Ùµğ¸¦ ·çÆ®

	cRightArm* pRightArm = new cRightArm;
	pRightArm->Init();
	m_pRoot->AddChild(pRightArm);
	m_pRoot = pRightArm;//À­ÆÈÀ» ·çÆ®·Î

	cRightArmS* pRightArmS = new cRightArmS;
	pRightArmS->Init();
	m_pRoot->AddChild(pRightArmS);
	m_pRoot = pBody;//´Ù½Ã ¹Ùµğ¸¦ ·çÆ®

	cLeftLeg* pLeftLeg = new cLeftLeg;
	pLeftLeg->Init();
	m_pRoot->AddChild(pLeftLeg);
	m_pRoot = pLeftLeg;

	cLeftLegS* pLeftLegS = new cLeftLegS;
	pLeftLegS->Init();
	m_pRoot->AddChild(pLeftLegS);
	m_pRoot = pBody;

	cRightLeg* pRightLeg = new cRightLeg;
	pRightLeg->Init();
	m_pRoot->AddChild(pRightLeg);
	m_pRoot = pRightLeg;

	cRightLegS* pRightLegS = new cRightLegS;
	pRightLegS->Init();
	m_pRoot->AddChild(pRightLegS);
	m_pRoot = pBody;
}
void cCubeMan::Update()
{
	m_pRoot->SetcMotion(IDLE);

	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;

	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
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