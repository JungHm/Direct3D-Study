#pragma once

class tankMove
{
private:

	std::vector<ST_PC_VERTEXT>	m_vecVertex;

	D3DXMATRIXA16 matWorld;
	D3DXMATRIXA16 matView;
	D3DXMATRIXA16 matProj;
	//D3DXMATRIXA16 matPort;
	D3DXVECTOR3 cubeMove;
	D3DXVECTOR3 vecMove;

	D3DXMATRIXA16 matRotate;
	D3DXMATRIXA16 matMouseRot;
	D3DXMATRIXA16 matTrans;

	float angleY;

private:
	std::vector<ST_PC_VERTEXT> m_gridVertex;
	D3DXMATRIXA16 matGrWorld;

	D3DXVECTOR3	vEye;
	D3DXVECTOR3	vLookAt;
	D3DXVECTOR3	vUp;

	D3DXVECTOR3	gEye;
	D3DXVECTOR3	gLookAt;
	D3DXVECTOR3	gUp;

	float PrevmouseX;
	float PrevmouseY;
	float NowmouseX;
	float NowmouseY;

	float mAngleX;
	float mAngleY;

	bool isClick;
public:
	tankMove();
	~tankMove();

	void Init();
	void Release();
	void Update();
	void Render();

	void VertexSet(int num, D3DCOLOR c);
};

