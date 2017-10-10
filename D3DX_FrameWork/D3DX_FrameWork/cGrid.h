#pragma once
class cGrid
{
private:
	float fMax;
	float fMin;
	float fY;
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	std::vector<ST_PT_VERTEXT>	m_texVertex;

	LPDIRECT3DTEXTURE9 GridTexture;
public:
	cGrid();
	~cGrid();

	void Init(int nNumHalfTile = 50, float fInterval = 1.0f);
	void Render();

	void FloorTextureInit();
};

