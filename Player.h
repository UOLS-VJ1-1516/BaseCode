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
	bool m_estoyEnElSuelo;
	int m_ticksHastaProximoSalto;
	float m_epsilon;
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
	static GameObject * Create() { return new Player(); }
};

#endif PLAYER_H