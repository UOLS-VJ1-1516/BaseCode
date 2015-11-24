#include "Player.h"
#include "Game.h"
#include <string>

Player::~Player()
{
}

Player::Player() : LivingEntity()
{
	maxVel = Vector2D(10, 10);
	acceleration = Vector2D(1, 1);
}

void Player::Update()
{
	cout << "Player Speed: " << velocity.toString() << endl;
	Accelerate(xAccel, yAccel);
	LivingEntity::Update();	
}

bool Player::InBounds(LivingEntity * entitat)
{
	return Tools::InBounding(entitat, this);
}

void Player::Jump()
{
	if (GetYPos() + GetHeight() == Tools::GetHeight())
	{
		velocity.Y = -100;
	}
}