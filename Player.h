#pragma once

#include "CollisionObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class Player : public CollisionObject
{
	//int spriteNum;
public:
	
	Player();
	~Player(); //Cabecera
	virtual void draw();
	virtual void load(const LoaderParams* pParams);
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Player(); }

	void accelerationX();
	void accelerationY();
	void desaccelerationX();
	void desaccelerationY();
	void jump();
	void onCollision(GameObject * otro);
	void incrementAccelerationY();
	void decrementAccelerationX();
	void decrementAccelerationY();
	void incrementAccelerationX();
	SDL_RendererFlip turn = SDL_FLIP_HORIZONTAL;

private:
	void stopX(int);
	void stopY(int);
	Vector2D m_lastStop;
	bool mJump;

};
