#pragma once
#include "cCubeMake.h"
class cLeftLegS :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cLeftLegS();
	~cLeftLegS();

	virtual void Init() override;
	//virtual void MoveMotion() override;
};

