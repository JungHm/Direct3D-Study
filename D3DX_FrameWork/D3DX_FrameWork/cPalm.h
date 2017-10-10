#pragma once
#include "cCubeMake.h"
class cPalm :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cPalm();
	~cPalm();
	virtual void Init() override;
	virtual void FanMotion() override;
	virtual bool Recover() override;
	virtual void HelloMotion() override;
};

