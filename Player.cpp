#include "Player.h"
#include "Game.h"
#include <string>

Player::~Player()
{
}

Player::Player() : LivingEntity()
{
	maxVel = Vector2D(10, 100);
	acceleration = Vector2D(1, 1);
}

void Player::Update()
{
	Accelerate(xAccel, yAccel);
	cout << "Player Speed: " << velocity.toString() << endl;
	LivingEntity::Update();	
}

bool Player::InBounds(LivingEntity * entitat)
{
	return Tools::InBounding(entitat, this);
}

void Player::Jump()
{
 	if (this->GetYPos() + this->GetHeight() == Tools::GetHeight())
	{
		velocity.Y = salt;
	}
}