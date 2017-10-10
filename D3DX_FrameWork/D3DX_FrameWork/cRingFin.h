#pragma once
#include "cCubeMake.h"
class cRingFin :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cRingFin();
	~cRingFin();
	virtual void Init() override;
	virtual void RingGMotion() override;

	virtual bool Recover() override;
};

