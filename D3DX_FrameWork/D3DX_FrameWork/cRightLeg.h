#pragma once
#include "cCubeMake.h"
class cRightLeg :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cRightLeg();
	~cRightLeg();

	virtual void Init() override;
	virtual void MoveMotion() override;
	virtual bool Recover() override;
};

