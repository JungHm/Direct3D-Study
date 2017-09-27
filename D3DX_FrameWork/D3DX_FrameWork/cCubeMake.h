#pragma once

class cCubeMake
{
protected:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	D3DXMATRIX				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;

	D3DXMATRIX				t_matS;
public:
	cCubeMake();
	~cCubeMake();

	virtual void Init(D3DXVECTOR3 temp);
	virtual void Adjust();
	virtual void Update();
	virtual void Render();

	virtual void VertexSet(int num, D3DXVECTOR3 temp, D3DCOLOR c);
};

