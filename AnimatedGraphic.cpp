#include "AnimatedGraphic.h"

AnimatedGraphic::~AnimatedGraphic()
{
}

AnimatedGraphic::AnimatedGraphic(int animSpeed)
{
	m_animSpeed = animSpeed;
}

void AnimatedGraphic::load(const LoaderParams* pParam) {};

void AnimatedGraphic::draw()
{
	TextureManager::Instance()->drawFrame(Params->getTextureID(), (int)Params->getX(), (int)Params->getY(), Params->getWidth(), Params->getHeight(), 0, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %	m_sprite));
}

void AnimatedGraphic::clean()
{
}
