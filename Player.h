#pragma once
#include "GameObject.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameObject
{
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	int getCallbackID() const { return m_callbackID; }
	void setCallback(void(*callback)()) { m_callback = callback; }
	void update();
	static GameObject* Player::Create() { return new Player(); }
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


private: 
	bool m_changes;
	bool m_accelerationCalculate;
	bool m_frictionCalculate;
	bool eventRightDown;
	bool eventLeftDown;
	bool eventRightUp;
	bool eventLeftUp;
	void(*m_callback)();
	int m_callbackID;
};
#endif PLAYER_H
