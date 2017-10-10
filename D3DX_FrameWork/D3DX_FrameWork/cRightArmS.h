#pragma once
#include "cCubeMake.h"
class cRightArmS :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cRightArmS();
	~cRightArmS();

	virtual void Init() override;
	virtual void MoveMotion() override;
	virtual bool Recover() override;
};

