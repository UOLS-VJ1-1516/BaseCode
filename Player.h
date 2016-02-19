#pragma once
#include "CollisionObject.h"
#include "SDL.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public CollisionObject
{
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	int getCallbackID() const { return m_callbackID; }
	void setCallback(void(*callback)()) { m_callback = callback; }
	void update();
	void clean();
	void calculateAcceleration();
	void calculateVelocity();
	void calculateFriction();
	void calculateFrame();
	void registerEvents();
	void frontHorizontal();
	void incrementAccelerationX();
	void incrementFriction();
	bool isCalculateAcceleration();
	bool iscalculateFriction();
	void resetParams();
	void handleInput();
	void impulseRight();
	void impulseLeft();
	void jump();
	void gravity();
	void incrementAccelerationY();
	void decrementAccelerationY();
	void onCollsion(GameObject* other);
	static GameObject * Create() { return new Player(); }
	void collision() {};
	bool nJump = false;
	bool mjumping = false;
	bool haycolision = false;

private: 
	bool m_changes;
	bool m_accelerationCalculate;
	bool m_frictionCalculate;
	bool eventRightDown;
	bool eventLeftDown;
	bool eventRightUp;
	bool eventLeftUp;
	void(*m_callback)();
	void stopX(int);
	void stopY(int);
	bool aceleracionY;
	bool frictionY;
	bool mgravity;
	Vector2D m_lastStop;
	int m_callbackID;
};
#endif PLAYER_H
