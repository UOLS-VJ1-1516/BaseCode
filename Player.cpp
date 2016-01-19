#include "Player.h"
#include "Game.h"
#include <string>
#include <sdl.h>

Player::~Player()
{
}

Player::Player() : LivingEntity()
{
	position.X = 0;
	maxVel = Vector2D(10, 10);
	acceleration = Vector2D(1, 1);	
	SetJump(-25);
}

void Player::Update()
{
	Accelerate(xAccel, yAccel);	
	LivingEntity::Update();	
}

bool Player::InBounds(LivingEntity * entitat)
{
	return Tools::InBounding(entitat, this);
}

void Player::Jump()
{
	if (!inAir)
		velocity.Y = salt;
}
