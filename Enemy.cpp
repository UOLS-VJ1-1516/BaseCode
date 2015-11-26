#include "Enemy.h"
#include <SDL.h>
#include "Game.h"

void Enemy::FollowPlayer(Player * player)
{
	float xPos = position.X;
	float playerXPos = player->GetXPos();
	float delta = (float)Game::GetInstance()->delta;

	if (abs(xPos - playerXPos) < 1) {
		xAccel = NULL;
		xPos = playerXPos;
	} else if (xPos > playerXPos) {
		xAccel = NEGATIVE;
	} else if (xPos < playerXPos) {
		xAccel = POSITIVE;
	}	
}

void Enemy::BeStatic(Player * player)
{
	float xPos = position.X;
	float playerXPos = player->GetXPos();
	
	if (xPos > playerXPos && !params->IsFlipped()) {
		params->Flip();
	}
	else if (xPos < playerXPos && params->IsFlipped()) {
		params->Flip();
	}		
	
}

void Enemy::TheIgnored()
{
	int w = NULL;
	SDL_GetWindowSize(Game::GetInstance()->GetWindow(), &w, NULL);
	
	float delta = (float)Game::GetInstance()->delta;
	if (position.X <= 0 || position.X >= w)
	{
		params->Flip();
	}
	if (params->IsFlipped())
	{
		xAccel = NEGATIVE;
	}
	else
	{
		xAccel = POSITIVE;
	}
	
}

Enemy::Enemy(int type)
{
	this->type = type;
	maxVel = Vector2D(7.5, 10);
	acceleration = Vector2D(0.75, 1);
}


Enemy::~Enemy()
{
}

void Enemy::Update(Player * player)
{
	switch (type)
	{
	case STATIC_ENEMY:
		BeStatic(player);
		break;
	case FOLLOWER_ENEMY:
		FollowPlayer(player);
		break;
	case IGNORE_ENEMY:
		TheIgnored();
		break;
	default:
		break;
	}
	Accelerate(xAccel, yAccel);
}
