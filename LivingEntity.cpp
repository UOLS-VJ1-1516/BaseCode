#include "LivingEntity.h"
#include <SDL.h>
#include "Loaders.h"
#include "Game.h"

LivingEntity::LivingEntity() : Entity()
{
}


LivingEntity::~LivingEntity()
{
}

void LivingEntity::Move(int pos)
{
	if (pos < 0 && !params->IsFlipped() || pos > 0 && params->IsFlipped())
		params->Flip();
	params->AddFrame();	
	params->AddXPos(pos);
}

void LivingEntity::Load(EntityParams * params, const char * file)
{
	this->params = params;
	TextureManager::GetInstance()->Load(file, params->GetId());
}

void LivingEntity::Draw()
{
	SDL_Rect img, draw;
	img.x = 0;
	img.y = 0;
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = params->GetXPos();
	draw.y = params->GetYPos();
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

	draw.x = params->GetXPos();
	draw.y = params->GetYPos();
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
