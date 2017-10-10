#pragma once
#include "cCubeMake.h"
class cIndexFinS
	: public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cIndexFinS();
	~cIndexFinS();
	virtual void Init() override;
	
	virtual void IndexGMotion() override;

	virtual bool Recover() override;
};

