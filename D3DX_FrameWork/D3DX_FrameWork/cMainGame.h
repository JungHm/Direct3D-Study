#pragma once

class cCubeMake;
class cGrid;
class cCamera;
class cCubeMan;

class cMainGame
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	cGrid*		m_pGrid;
	cCamera*	m_pCamera;
	cCubeMan*	m_pCubeMan;

	bool GridOn;
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

