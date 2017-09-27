#pragma once

class cCube;
class cGrid;
class cCamera;

class cMainGame
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	cCube*		m_pCube;
	cGrid*		m_pGrid;
	cCamera*	m_pCamera;

public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

