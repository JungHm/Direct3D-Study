#pragma once
#include "cCubeMake.h"
class cIndexFin
	: public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;

public:
	cIndexFin();
	~cIndexFin();

	virtual void Init() override;
	virtual void IndexGMotion() override;

	virtual bool Recover() override;
};

