#pragma once
#include "LivingEntity.h"
#include <SDL.h>

class Player : public LivingEntity
{
public:
	int xAccel = 0, yAccel = 0;
	Player();
	~Player();	
	float xPos = 0;
	void Accelerate(int, int);
	void Update();
	static Entity * Create() { return new Player(); }
};