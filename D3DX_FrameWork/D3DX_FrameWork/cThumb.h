#pragma once
#include "cCubeMake.h"
class cThumb :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cThumb();
	~cThumb();

	virtual void Init() override;
	virtual void ThumbGMotion() override;

	virtual bool Recover() override;
};

