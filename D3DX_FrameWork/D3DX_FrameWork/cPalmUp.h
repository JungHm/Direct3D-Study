#pragma once
#include "cCubeMake.h"
class cPalmUp :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;


public:
	cPalmUp();
	~cPalmUp();
	virtual void Init() override;

	virtual void GrabMotion() override;
	virtual bool Recover() override;
};

