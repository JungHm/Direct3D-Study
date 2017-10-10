#pragma once
class cCubeMake;

enum Direction
{
	FRONT = 1,
	BACK,
	LEFT,
	RIGHT	
};

class cCubeMan
{
private:
	cCubeMake* m_pRoot;
	LPDIRECT3DTEXTURE9 steveTex;

	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;
	
	SPHERE_PROPERTY manPos;

	int pushDirection;
public:
	cCubeMan();
	~cCubeMan();

	void Init();
	void Update();
	void Render();

	SPHERE_PROPERTY GetManPos(void) { return manPos; }

	int GetDirection() { return pushDirection; }

	MATRIX16_FIX
};

