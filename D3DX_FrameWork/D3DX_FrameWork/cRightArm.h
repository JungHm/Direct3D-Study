#pragma once
#include "cCubeMake.h"
class cRightArm :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cRightArm();
	~cRightArm();

	virtual void Init() override;
	virtual void MoveMotion() override;
};

