#pragma once
class cCubeMake;

class cCubeHand
{
private:
	cCubeMake* m_pRoot;
	LPDIRECT3DTEXTURE9 handTex;

	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;
public:
	cCubeHand();
	~cCubeHand();

	void Init();
	void Update();
	void Render();

	MATRIX16_FIX
};

