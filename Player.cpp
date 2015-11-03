#include "Player.h"
#include "Game.h"

Player::~Player()
{
}

void Player::Move(float pos)
{
	if (pos < 0 && !params->IsFlipped() || pos > 0 && params->IsFlipped())
		params->Flip();
	if (SDL_GetTicks() % 50 / (int)Game::GetInstance()->delta == 0)
		params->AddFrame();
	params->AddXPos(pos);
}


Player::Player() : LivingEntity()
{
	
}
