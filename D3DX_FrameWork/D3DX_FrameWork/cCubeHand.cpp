#include "stdafx.h"
#include "cCubeHand.h"

#include "cWrist.h"
#include "cJoint.h"
#include "cPalm.h"
#include "cPalmUp.h"
#include "cIndexFin.h"
#include "cIndexFinS.h"
#include "cIndexFinT.h"
#include "cMidFin.h"
#include "cMidFinS.h"
#include "cMidFinT.h"
#include "cRingFin.h"
#include "cRingFinS.h"
#include "cRingFinT.h"
#include "cLilFin.h"
#include "cLilFinS.h"
#include "cLilFinT.h"
#include "cThumb.h"
#include "cThumbS.h"

cCubeHand::cCubeHand()
	: m_pRoot(NULL)
	, handTex(NULL)
{
	m_fRotY = m_vPosition.x = m_vPosition.y = m_vPosition.z = 0.0f;
	m_vDirection = D3DXVECTOR3(0, 0, 1);

	D3DXCreateTextureFromFile(g_pD3DDevice, L"stoneTexture.png", &handTex);
	D3DXMatrixIdentity(&m_matWorld);
}


cCubeHand::~cCubeHand()
{
	SAFE_DELETE(m_pRoot);
	SAFE_RELEASE(handTex);
}

void cCubeHand::Init()
{
	cWrist* pWrist = new cWrist;
	pWrist->Init();
	pWrist->SetParentWorldTM(&m_matWorld);
	m_pRoot = pWrist;

	cJoint* pJoint = new cJoint;
	pJoint->Init();
	m_pRoot->AddChild(pJoint);

	cPalm* pPalm = new cPalm;
	pPalm->Init();
	pJoint->AddChild(pPalm);

	cPalmUp* pPalmUp = new cPalmUp;
	pPalmUp->Init();
	pPalm->AddChild(pPalmUp);

	cIndexFin* pIndexF = new cIndexFin;
	pIndexF->Init();
	pPalmUp->AddChild(pIndexF);

	cIndexFinS* pIndexFS = new cIndexFinS;
	pIndexFS->Init();
	pIndexF->AddChild(pIndexFS);

	cIndexFinT* pIndexFT = new cIndexFinT;
	pIndexFT->Init();
	pIndexFS->AddChild(pIndexFT);

	cMidFin* pMidFin = new cMidFin;
	pMidFin->Init();
	pPalmUp->AddChild(pMidFin);

	cMidFinS* pMidFinS = new cMidFinS;
	pMidFinS->Init();
	pMidFin->AddChild(pMidFinS);

	cMidFinT* pMidFinT = new cMidFinT;
	pMidFinT->Init();
	pMidFinS->AddChild(pMidFinT);

	cRingFin* pRingFin = new cRingFin;
	pRingFin->Init();
	pPalmUp->AddChild(pRingFin);

	cRingFinS* pRingFinS = new cRingFinS;
	pRingFinS->Init();
	pRingFin->AddChild(pRingFinS);

	cRingFinT* pRingFinT = new cRingFinT;
	pRingFinT->Init();
	pRingFinS->AddChild(pRingFinT);

	cLilFin* pLilFin = new cLilFin;
	pLilFin->Init();
	pPalmUp->AddChild(pLilFin);

	cLilFinS* pLilFinS = new cLilFinS;
	pLilFinS->Init();
	pLilFin->AddChild(pLilFinS);

	cLilFinT* pLilFinT = new cLilFinT;
	pLilFinT->Init();
	pLilFinS->AddChild(pLilFinT);

	cThumb* pThumb = new cThumb;
	pThumb->Init();
	pPalmUp->AddChild(pThumb);

	cThumbS* pThumbS = new cThumbS;
	pThumbS->Init();
	pThumb->AddChild(pThumbS);
}

void cCubeHand::Update()
{
	m_pRoot->SetcMotion(IDLE);

	if (GetKeyState('2') & 0x8000)
	{
		m_pRoot->SetcMotion(GRAB_ALL);
	}
	if (GetKeyState('3') & 0x8000)
	{
		m_pRoot->SetcMotion(SCISSORS_G);
	}
	if (GetKeyState('4') & 0x8000)
	{
		m_pRoot->SetcMotion(FAN);
	}
	if (GetKeyState('5') & 0x8000)
	{
		m_pRoot->SetcMotion(HELLO);
	}

	if (GetKeyState('Z') & 0x8000)
	{
		m_pRoot->SetcMotion(THUMB_G);
	}
	if (GetKeyState('X') & 0x8000)
	{
		m_pRoot->SetcMotion(INDEX_G);
	}
	if (GetKeyState('C') & 0x8000)
	{
		m_pRoot->SetcMotion(MID_G);
	}
	if (GetKeyState('V') & 0x8000)
	{
		m_pRoot->SetcMotion(RING_G);
	}
	if (GetKeyState('B') & 0x8000)
	{
		m_pRoot->SetcMotion(LIL_G);
	}

	/*D3DXMATRIXA16	matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;*/

	if (m_pRoot)
	{
		m_pRoot->Update();
	}
}

void cCubeHand::Render()
{
	g_pD3DDevice->SetTexture(0, handTex);
	if (m_pRoot)
	{
		m_pRoot->Render();
	}
}
