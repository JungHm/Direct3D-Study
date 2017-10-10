#pragma once
#include "cCubeMake.h"
class cBody :
	public cCubeMake
{
private:
	
	//SPHERE_PROPERTY manBox;
	LPD3DXMESH spMesh;
public:
	cBody();
	~cBody();

	virtual void Init() override;
	void Update();
	virtual void Render() override;
	void Destroy();
	SYNTHESIZE(SPHERE_PROPERTY, manBox, Collision)
};
