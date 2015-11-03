#include "Enemy.h"
#include <SDL.h>
#include "Game.h"

void Enemy::FollowPlayer(Player * player)
{
	int xPos = params->GetXPos();
	int playerXPos = player->params->GetXPos();
	if ((SDL_GetTicks()) % 250 == 0)
	{
		if (xPos > playerXPos) {
			Move(-1);
		}
		else if (xPos < playerXPos) {
			Move(1);
		}
		else {
			Move(0);
		}
	}
}

void Enemy::BeStatic(Player * player)
{
	int xPos = params->GetXPos();
	int playerXPos = player->params->GetXPos();
	if ((SDL_GetTicks()) % 250 == 0)
	{
		if (xPos > playerXPos && !params->IsFlipped()) {
			params->Flip();
		}
		else if (xPos < playerXPos && params->IsFlipped()) {
			params->Flip();
		}
		else {
			Move(0);
		}
	}
}

void Enemy::TheIgnored()
{
	int w = NULL;
	SDL_GetWindowSize(Game::GetInstance()->GetWindow(), &w, NULL);
	
	if ((SDL_GetTicks()) % 250 == 0)
	{
		if (params->GetXPos() <= 0 || params->GetXPos() >= w)
		{
			params->Flip();
		}
		if (params->IsFlipped())
		{
			Move(-1);
		}
		else
		{
			Move(1);
		}
	}
}

Enemy::Enemy(int type)
{
	this->type = type;
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
