#pragma once
struct ST_PC_VERTEXT
{
	D3DXVECTOR3	p;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};
class cMainGame
{
private:
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();
	void Relase();
};

