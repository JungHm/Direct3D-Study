#pragma once
#include "cCubeMake.h"
class cRingFinT :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cRingFinT();
	~cRingFinT();

	virtual void Init() override;
	virtual void RingGMotion() override;

	virtual bool Recover() override;
};

