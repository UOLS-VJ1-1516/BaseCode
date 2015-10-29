#include "TextureManager.h"
#include "Player.h"


	void Player::draw(SDL_Renderer* pRender)
	{
		spriteNum = (int)((SDL_GetTicks() / 100) % 10);
		TextureManager::Instance()->drawFrame("player", 100, 100, 35, 32, 0, spriteNum, pRender, SDL_FLIP_NONE);
	}
