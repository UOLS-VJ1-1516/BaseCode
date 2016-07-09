#pragma once
#include "game.h"
#include "GameObject.h"

class AnimatedGraphic : public GameObject
{
public:

	
	AnimatedGraphic(int animSpeed);
	~AnimatedGraphic();
	void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	int m_animSpeed;

	const LoaderParams* Params;
	
};