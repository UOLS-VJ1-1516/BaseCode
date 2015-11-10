#include "Player.h"
#include "Game.h"
#include <string>

Player::~Player()
{
}

void Player::Accelerate(int aX, int aY)
{
	LivingEntity::Accelerate(aX, aY);
	xPos = position.X;	
}


Player::Player() : LivingEntity()
{
	maxVel = Vector2D(10, 10);
	acceleration = Vector2D(1, 1);
}

void Player::Update()
{
	Accelerate(xAccel, yAccel);
	LivingEntity::Update();	
}