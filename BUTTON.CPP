#include "Button.h"
#include "Game.h"

void Button::Load(EntityParams * params, const char * textureFile)
{
	this->params = params;
	text = new LivingEntity();
	text->params = params;

	TextureManager::GetInstance()->Load(textureFile, params->GetId());
}

void Button::SetOnClickListener(void(*callback)())
{
	this->callback = callback;
}

void Button::Draw()
{
	SDL_Rect img, draw;
	img.x = 0;
	img.y = 0;
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (int)params->GetXPos();
	draw.y = (int)params->GetYPos();
	draw.h = params->GetHeight();
	draw.w = params->GetWidth();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[params->GetId()];
	SDL_RenderCopyEx(TheGame->GetRenderer(), textura, &img, &draw, 0, NULL, flip);

	switch (state)
	{
	case WAIT:
		textura = TextureManager::GetInstance()->GetArray["waitButton.png"];
		break;
	case HOVER:
		textura = TextureManager::GetInstance()->GetArray["hoverButton.png"];
		break;
	case PRESSED:
		textura = TextureManager::GetInstance()->GetArray["pressedButton.png"];
		break;
	}
	SDL_RenderCopyEx(TheGame->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}

void Button::DrawFrame()
{

}

void Button::Update()
{

}

void Button::Clear()
{

}