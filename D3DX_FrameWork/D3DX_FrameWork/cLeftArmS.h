#pragma once
#include "cCubeMake.h"
class cLeftArmS :
	public cCubeMake
{
private:
	float angleY;
	float angleMax;
	float angleMin;
	bool angleRe;
public:
	cLeftArmS();
	~cLeftArmS();

	virtual void Init() override;
	void MoveMotion();

};

