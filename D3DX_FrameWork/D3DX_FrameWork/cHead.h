#pragma once
#include "cCubeMake.h"

class cHead :
	public cCubeMake
{
public:
	cHead();
	~cHead();

	virtual void Init() override;
};

