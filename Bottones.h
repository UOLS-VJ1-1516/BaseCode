#pragma once

#include "GameObject.h"

class Bottones :public GameObject {
public:
	Bottones();
	~Bottones();
	void draw();
	void update();
	void load(const LoaderParams * pParams);
	void clean();
	void drawR(int angle);
};
