#include "ImageSimple.h"
#include "TextureManager.h"
#include "game.h"

ImageSimple::ImageSimple()
{
}


ImageSimple::~ImageSimple()
{
}

void ImageSimple::load(const LoaderParams* ppParams) {
	ImageSimple::pParams = ppParams;
	m_currentRow = 1;
	m_currentFrame = 0;
}


void ImageSimple::draw()
{
	TextureManager::Instance()->drawFrame(pParams->getTextureID(), pParams->getX(), pParams->getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void ImageSimple::update()
{	
}

void ImageSimple::clean()
{
}
