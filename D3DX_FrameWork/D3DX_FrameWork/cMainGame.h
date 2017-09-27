#pragma once
#include "tankMove.h"


class cMainGame
{
private:
	tankMove* tk;
public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();
	void Relase();
};

