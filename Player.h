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


private: 
	bool m_changes;
	bool m_accelerationCalculate;
	bool m_frictionCalculate;
	bool eventRightDown;
	bool eventLeftDown;
	bool eventRightUp;
	bool eventLeftUp;
};
#endif PLAYER_H
