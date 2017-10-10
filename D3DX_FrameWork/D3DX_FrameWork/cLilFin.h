#pragma once
#include "cCubeMake.h"
class cLilFin :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cLilFin();
	~cLilFin();

	virtual void Init() override;
	virtual void LilGMotion() override;

	virtual bool Recover() override;
};

