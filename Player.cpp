#include "Player.h"
#include "Game.h"
#include <string>
#include "Camera.h"

Player::~Player()
{
}

Player::Player() : LivingEntity()
{
	position.X = 0;
	maxVel = Vector2D(10, 15);
	acceleration = Vector2D(1, 1);	
	SetJump(-15);
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

void Player::DrawFrame()
{
	SDL_Rect img, draw;

	img.x = params->GetWidth() * params->GetFrame();
	img.y = params->GetHeight() * params->GetRow();
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = position.X - TheCam->GetPosition()->X;
	draw.y = position.Y;
	draw.w = params->GetWidth();
	draw.h = params->GetHeight();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[texture];
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}