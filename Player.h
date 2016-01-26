#pragma once
#include "CollisionObject.h"
class Player : public CollisionObject
{
public:
	Player();
	~Player();
	virtual void draw();
	void load(const LoaderParams *pParams);
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Player(); }
private:
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};
