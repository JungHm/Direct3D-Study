#pragma once
#include "cCubeMake.h"
class cRightLegS :public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cRightLegS();
	~cRightLegS();

	virtual void Init() override;
	//virtual void MoveMotion() override;
};

