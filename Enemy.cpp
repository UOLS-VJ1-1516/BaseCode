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
	if (position.X < 0)
	{
		params->SetFlipped(false);
	}
	else if (position.X > Tools::GetWidth() - GetWidth())
	{
		params->SetFlipped(true);
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

void Enemy::MoveALittle()
{	
	srand((int)time(NULL));
	int random = rand() % 10;
	if (random > 2 && random < 8)
	{
		xAccel = NULL;
	}
	else if (random <= 2)
	{
		xAccel = NEGATIVE;
	}
	else if (random >= 8)
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
	case LITTLE_MOVEMENT: 
		MoveALittle();
		break;
	default:
		break;
	}
	playerPos = player->position;
	Accelerate(xAccel, yAccel);
}

void Enemy::DrawFrame()
{
	SDL_Rect img, draw;

	img.x = params->GetWidth() * params->GetFrame();
	img.y = params->GetHeight() * params->GetRow();
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (Tools::GetWidth() / 2) + (int)position.X - (playerPos.X);
	draw.y = ((Tools::GetHeight() - params->GetHeight()) / 2) + (int)position.Y - (playerPos.Y);
	draw.w = params->GetWidth();
	draw.h = params->GetHeight();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[params->GetId()];
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}
