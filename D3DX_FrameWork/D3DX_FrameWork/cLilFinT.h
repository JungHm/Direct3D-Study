#pragma once
#include "cCubeMake.h"
class cLilFinT :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cLilFinT();
	~cLilFinT();
	virtual void Init() override;
	virtual void LilGMotion() override;

	virtual bool Recover() override;
};

