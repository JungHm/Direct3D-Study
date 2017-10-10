#pragma once
#include "cCubeMake.h"
class cMidFin
	:public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cMidFin();
	~cMidFin();

	virtual void Init() override;
	virtual void MidGMotion() override;

	virtual bool Recover() override;
};
