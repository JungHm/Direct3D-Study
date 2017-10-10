#pragma once
#include "cCubeMake.h"
class cRingFinS
	: public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cRingFinS();
	~cRingFinS();
	virtual void Init() override;
	virtual void RingGMotion() override;

	virtual bool Recover() override;
};

