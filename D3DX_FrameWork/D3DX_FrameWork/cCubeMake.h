#pragma once
enum MOTION
{
	IDLE=1,	MOVE, PUSH,
	WIN, GRAB_ALL, THUMB_G,
	INDEX_G, MID_G, RING_G, LIL_G,
	SCISSORS_G, FAN, HELLO
};
class cCubeMake
{
protected:
	std::vector<ST_PT_VERTEXT>	m_vecVertex;


	D3DXMATRIXA16				m_matLocalTM;
	D3DXMATRIXA16				m_matWorldTM;
	D3DXMATRIXA16	matR, matT;
	D3DXMATRIXA16	matMoveT, matOriginT;
	
	D3DXVECTOR3					m_vLocalPos;

	std::vector<cCubeMake*>			m_vecChild;
	float y;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	SYNTHESIZE(int, motionNum, cMotion);
	
public:
	cCubeMake();
	virtual ~cCubeMake();

	void AddChild(cCubeMake* pChild);
	void Destroy();

	virtual void Init();
	virtual void CubeInit();
	virtual void Update();
	virtual void Render();
	void ChildUpdate(std::vector<cCubeMake*> p);

public:
	//human motion
	virtual void IdleMotion();
	virtual void MoveMotion();
	virtual void PushMotion();
	virtual void WinMotion();
	
	//hand motion
	virtual void GrabMotion();
	virtual void HelloMotion();
	virtual void ScissorG();
	virtual void FanMotion();
	virtual void ThumbGMotion();
	virtual void IndexGMotion();
	virtual void MidGMotion();
	virtual void RingGMotion();
	virtual void LilGMotion();

	virtual bool Recover();

	MATRIX16_FIX
};

