#pragma once
enum MOTION
{
	IDLE=1,
	MOVE
};
class cCubeMake
{
protected:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;

	D3DXMATRIXA16				m_matLocalTM;
	D3DXMATRIXA16				m_matWorldTM;
	D3DXMATRIXA16	matR, matT;
	D3DXMATRIXA16	matMotionR;

	D3DXVECTOR3					m_vLocalPos;

	std::vector<cCubeMake*>			m_vecChild;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM)
	SYNTHESIZE(int, motionNum, cMotion)
public:
	cCubeMake();
	virtual ~cCubeMake();

	void AddChild(cCubeMake* pChild);
	void Destroy();

	virtual void Init();
	void Update();
	void Render();

	virtual void IdleMotion();
	virtual void MoveMotion();
};

