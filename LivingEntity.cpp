#include "LivingEntity.h"
#include <SDL.h>
#include "Loaders.h"
#include "Game.h"
#include <cmath>

using namespace std;

LivingEntity::LivingEntity() : Entity()
{
}


LivingEntity::~LivingEntity()
{
}

void LivingEntity::Move(float xPos, float yPos)
{
	
	if (xPos < 0 && !params->IsFlipped() || xPos > 0 && params->IsFlipped())
		params->Flip();
	if (SDL_GetTicks() % 100 / (int)Game::GetInstance()->delta == 0)
		params->AddFrame();
	params->AddXPos(xPos);
	
}

void LivingEntity::Accelerate(int aX, int aY)
{		
	velocity.X += (aX * 2 * acceleration.X);
	velocity.Y += (aY * 2 * acceleration.Y);
	velocity *= (float)Game::GetInstance()->delta / 1000;

	if (velocity.X > 0)
		velocity.X = fmin(velocity.X, maxVel.X);
	else if (velocity.X < 0)
		velocity.X = fmax(velocity.X, -maxVel.X);
	if (velocity.Y > 0)
		velocity.Y = fmin(velocity.Y, maxVel.Y);
	else if (velocity.Y < 0)
		velocity.X = fmax(velocity.Y, -maxVel.Y);
	
	if (velocity.X > 0)
	{
		velocity.X -= friction.X * Game::GetInstance()->delta / 1000;
	}
	else if (velocity.X < 0)
	{
		velocity.X += friction.X * Game::GetInstance()->delta / 1000;
	}

	position.X += velocity.X + (acceleration.X * aX);
	position.Y += velocity.Y + (acceleration.Y * aY);

	bool isFlipped;

	if (aX > 0)
		isFlipped = false;
	else if (aX < 0)
		isFlipped = true;
	else if (aX == 0)
		isFlipped = params->IsFlipped();

	params->SetFlipped(isFlipped);

	if (SDL_GetTicks() % 3 == 0 && aX != 0 || aY != 0)
		params->AddFrame();	
}

void LivingEntity::Load(EntityParams * params, const char * file)
{
	this->params = params;
	position.X = params->GetXPos();
	position.Y = params->GetYPos();
	velocity = Vector2D(0, 0);
	friction = Vector2D(0.15f, 0.15f);
	TextureManager::GetInstance()->Load(file, params->GetId());
}

void LivingEntity::Draw()
{
	SDL_Rect img, draw;
	img.x = 0;
	img.y = 0;
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (int)position.X;
	draw.y = (int)position.Y;
	draw.h = params->GetHeight();
	draw.w = params->GetWidth();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[params->GetId()];
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}

void LivingEntity::DrawFrame()
{
	SDL_Rect img, draw;

	img.x = params->GetWidth() * params->GetFrame();
	img.y = params->GetHeight() * params->GetRow();
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (int)position.X;
	draw.y = (int)position.Y;
	draw.w = params->GetWidth();
	draw.h = params->GetHeight();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[params->GetId()];
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}

void LivingEntity::Update()
{
	
}

void LivingEntity::Clear()
{
	this->~LivingEntity();
}
