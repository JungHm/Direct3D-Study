#pragma once
#include "cCubeMake.h"
class cLeftLeg :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cLeftLeg();
	~cLeftLeg();

	virtual void Init() override;
	virtual void MoveMotion() override;
	virtual bool Recover() override;
};

