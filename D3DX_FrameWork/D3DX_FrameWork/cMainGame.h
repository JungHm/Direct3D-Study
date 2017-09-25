#pragma once
class cMainGame
{
private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3Ddevice;
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();
	void Relase();
};

