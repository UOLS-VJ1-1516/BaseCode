#pragma once

#include "Entity.h"

namespace Tools
{
	void takeScreenShot(int, int);
	double GetDeltaTime();
	long GetTime();
	bool InBounding(Entity *, Entity *);
	bool InBounding(Entity *, int x0, int y0);
	int GetWidth();
	int GetHeight();
}
