#pragma once
#include "LivingEntity.h"
#include <SDL.h>
#include <vector>

class Player : public LivingEntity
{
public:
	int xAccel = 0, yAccel = 0;
	Player();
	~Player();	
	void Update();
	void Jump();
	bool InBounds(LivingEntity *);
	static Entity * Create() { return new Player(); }
};