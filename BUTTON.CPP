#include "Button.h"
#include "Game.h"

void Button::Load(EntityParams * params)
{
	this->params = params;
	text = new InertEntity();
	text->params = params;
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

	SDL_Texture * textura = NULL;
	switch (state)
	{
	case WAIT:
		textura = TextureManager::GetInstance()->GetArray()["buttonWait"];
		break;
	case HOVER:
		textura = TextureManager::GetInstance()->GetArray()["buttonHover"];
		break;
	case PRESSED:
		textura = TextureManager::GetInstance()->GetArray()["buttonPressed"];
		break;
	}
	SDL_RenderCopyEx(TheGame->GetRenderer(), textura, &img, &draw, 0, NULL, flip);

	SDL_Texture * text = TextureManager::GetInstance()->GetArray()[params->GetId()];
	SDL_RenderCopyEx(TheGame->GetRenderer(), text, &img, &draw, 0, NULL, flip);

}

void Button::DrawFrame()
{
	Draw();
}

void Button::Update()
{
	int x = BigHandle->GetMousePosition().first;
	int y = BigHandle->GetMousePosition().second;

	if (x > params->GetXPos() && x < params->GetWidth() + params->GetXPos() &&
		y > params->GetYPos() && y < params->GetHeight() + params->GetYPos())
	{
		state = HOVER;
		if (BigHandle->GetMouseButtons().first)
		{
			state = PRESSED;
			callback();
		}
	}
	else
	{
		state = WAIT;
	}
}

void Button::Clear()
{

}