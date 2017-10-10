#pragma once
class cCube
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	D3DXMATRIX				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;


	D3DXMATRIX matScale;
public:
	cCube();
	~cCube();

	void Init();
	void Update();
	void Render();

};

