#pragma once
class cCube
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;

public:
	cCube();
	~cCube();

	void Init();
	void Update();
	void Render();
};

