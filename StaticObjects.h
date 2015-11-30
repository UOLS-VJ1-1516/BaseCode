#pragma once
#include "GameObject.h"

class StaticObjects : public GameObject
{

public:
	StaticObjects();
	~StaticObjects();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void drawRotation(int angle);

	static GameObject* Create() {

		return new StaticObjects();

	}

};
