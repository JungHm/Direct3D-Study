#pragma once
class cCubeMake;

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

class cCubeMan
{
private:
	cCubeMake* m_pRoot;

	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;

public:
	cCubeMan();
	~cCubeMan();

	void Init();
	void Update();
	void Render();
};

