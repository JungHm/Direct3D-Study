#pragma once
class cCubeMake;


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

