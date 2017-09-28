#pragma once
#include "cCubeMake.h"
class cLeftArm :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cLeftArm();
	~cLeftArm();

	virtual void Init() override;
	virtual void MoveMotion() override;
};

