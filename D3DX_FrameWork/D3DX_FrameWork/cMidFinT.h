#pragma once
#include "cCubeMake.h"
class cMidFinT :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cMidFinT();
	~cMidFinT();


	virtual void Init() override;
	virtual void MidGMotion() override;

	virtual bool Recover() override;
};

