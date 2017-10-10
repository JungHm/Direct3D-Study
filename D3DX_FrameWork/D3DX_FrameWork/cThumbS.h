#pragma once
#include "cCubeMake.h"
class cThumbS :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cThumbS();
	~cThumbS();

	virtual void Init() override;
	virtual void ThumbGMotion() override;

	virtual bool Recover() override;
};

