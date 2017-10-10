#pragma once

class cCubeMake;
class cGrid;
//class cCamera;
class cCubeHand;
class cCubeMan;
class stone;

class cMainGame
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	cGrid*		m_pGrid;
	cCubeHand*	m_pHand;
	cCubeMan*	m_pCubeMan;
	stone*		m_pStone;
	bool GridOn;
	bool isCollision;

	std::vector<ST_PT_VERTEXT>	m_vecTex;
	std::vector<ST_PT_VERTEXT>	m_vecTex1;
	LPDIRECT3DTEXTURE9 m_pD3DTexture;
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();


	bool SphereIntersect(D3DXVECTOR3 vCenter1, float fRadius1, D3DXVECTOR3 vCenter2, float fRadius2);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


};

