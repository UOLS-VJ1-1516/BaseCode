#pragma once
#include "CollisionObject.h"
#include "SDL.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public CollisionObject
{
private:
	void stopX(int);
	void stopY(int);
	Vector2D m_lastStop;
	SDL_RendererFlip m_lastTimeOrientation;
	bool nJump = false;
	bool mjumping = false;
	bool haycolision = false;
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void update(int width, int height);
	void incrementAccelerationY();
	void decrementAccelerationY();
	void incrementAccelerationX();
	void decrementAccelerationX();
	void impulseRight();
	void impulseLeft();
	void jump();
	void gravity();
	void onCollsion(GameObject* other);
	static GameObject * Create() { return new Player(); }
	void collision() {};
};

#endif PLAYER_H