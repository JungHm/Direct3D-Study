#pragma once

class cGrid;
class cCamera;
//class cCube;
class cBody;
class cHead; class cLeftArm; class cRightArm; class cLeftLeg; class cRightLeg;

class cMainGame
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	cGrid*		m_pGrid;
	cCamera*	m_pCamera;
	//cCube
	cBody*		m_pBody;
	cHead*		m_pHead;
	cLeftArm* m_pLeftArm;
	cRightArm* m_pRightArm;
	cLeftLeg* m_pLeftLeg;
	cRightLeg* m_pRightLeg;

private://logic
	bool GridOn;
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

