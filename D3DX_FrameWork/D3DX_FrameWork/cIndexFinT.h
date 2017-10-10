#pragma once
#include "cCubeMake.h"
class cIndexFinT :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cIndexFinT();
	~cIndexFinT();
	virtual void Init() override;
	virtual void IndexGMotion() override;

	virtual bool Recover() override;
};