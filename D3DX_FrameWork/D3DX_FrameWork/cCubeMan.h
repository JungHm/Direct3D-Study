#pragma once
class cCubeMake;


class cCubeMan
{
private:
	cCubeMake* m_pRoot;

	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;
public:
	cCubeMan();
	~cCubeMan();

	void Init();
	void Update();
	void Render();

	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}

	void operator delete(void* p)
	{
		_mm_free(p);
	}
};

