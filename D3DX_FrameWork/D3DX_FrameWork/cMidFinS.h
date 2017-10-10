#pragma once
#include "cCubeMake.h"
class cMidFinS
	: public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cMidFinS();
	~cMidFinS();


	virtual void Init() override;
	virtual void MidGMotion() override;

	virtual bool Recover() override;
};
