#pragma once
#include "cCubeMake.h"
class cLilFinS :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cLilFinS();
	~cLilFinS();

	virtual void Init() override;
	virtual void LilGMotion() override;

	virtual bool Recover() override;
};

