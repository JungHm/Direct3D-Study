#pragma once
#include "cCubeMake.h"
class cBody :
	public cCubeMake
{
public:
	cBody();
	~cBody();

	virtual void Init() override;
};
