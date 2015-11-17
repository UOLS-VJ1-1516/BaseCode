#pragma once
#include "GameObject.h"

class Player2 : public GameObject
{
public:
	Player2();
	~Player2();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
private :
	bool stateFlip;
};
#pragma once
