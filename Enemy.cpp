#include "Enemy.h"
#include <SDL.h>
#include "Game.h"

void Enemy::FollowPlayer(Player * player)
{
	float xPos = position.X;
	float playerXPos = player->xPos;
	float delta = (float)Game::GetInstance()->delta;

	if (abs(xPos - playerXPos) < 1) {
		Accelerate(NULL, NULL);	
		xPos = playerXPos;
	} else if (xPos > playerXPos) {
		Accelerate(NEGATIVE, NULL);
	} else if (xPos < playerXPos) {
		Accelerate(POSITIVE, NULL);
	}	
}

void Enemy::BeStatic(Player * player)
{
	float xPos = position.X;
	float playerXPos = player->xPos;
	if ((SDL_GetTicks()) % 250 == 0)
	{
		if (xPos > playerXPos && !params->IsFlipped()) {
			params->Flip();
		}
		else if (xPos < playerXPos && params->IsFlipped()) {
			params->Flip();
		}		
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
		Accelerate(NEGATIVE, NULL);
	}
	else
	{
		Accelerate(POSITIVE, NULL);
	}
	
}

Enemy::Enemy(int type)
{
	this->type = type;
	maxVel = Vector2D(7.5, 7.5);
	acceleration = Vector2D(0.75, 0.75);
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
	
}
