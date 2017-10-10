#pragma once
#include "cCubeMake.h"

class cHead :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cHead();
	~cHead();

	virtual void Init() override;
	virtual void IdleMotion();
};

