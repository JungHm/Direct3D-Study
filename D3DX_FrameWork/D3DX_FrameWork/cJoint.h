#pragma once
#include "cCubeMake.h"
class cJoint :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cJoint();
	~cJoint();

	virtual void Init() override;
	virtual void FanMotion() override;
	virtual bool Recover() override;
	virtual void HelloMotion() override;
};

