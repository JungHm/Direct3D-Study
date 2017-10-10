#pragma once
#include "cCubeMake.h"
class stone :
	public cCubeMake
{
private:
	LPDIRECT3DTEXTURE9 stoneTexture;

	float radius;
	//D3DXVECTOR3 stoneCenter;
	LPD3DXMESH spMesh;
	///SPHERE_PROPERTY stoneBox;
	int direction;

	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;
public:
	stone();
	~stone();

	virtual void Init() override;
	void Update();
	void Render();
	SYNTHESIZE(SPHERE_PROPERTY, stoneBox, Collision);
	void SetDirection(int direc) { direction = direc; }
};

