#pragma once
#include "LivingEntity.h"
#include <SDL.h>

class Player : public LivingEntity
{
public:
	Player();
	~Player();
	void Move(float);
};