#include "Enemy.h"
#include <SDL.h>
#include "Game.h"

void Enemy::FollowPlayer(Player * player)
{
	float xPos = params->GetXPos();
	float playerXPos = player->params->GetXPos();
	float delta = Game::GetInstance()->delta;

	if (xPos > playerXPos) {
		Move(-5 / delta, 0);
	}
	else if (xPos < playerXPos) {
		Move(5 / delta, 0);
	}
	else {
		Move(0, 0);
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
			Move(0, 0);
		}
	}
}

void Enemy::TheIgnored()
{
	int w = NULL;
	SDL_GetWindowSize(Game::GetInstance()->GetWindow(), &w, NULL);
	
	float delta = Game::GetInstance()->delta;
	if (params->GetXPos() <= 0 || params->GetXPos() >= w)
	{
		params->Flip();
	}
	if (params->IsFlipped())
	{
		Move(-5 / delta, 0);
	}
	else
	{
		Move(5 / delta, 0);
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
