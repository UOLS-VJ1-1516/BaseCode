#include "Dog.h"
#include "TextureManager.h"
#include "game.h"

int dir2 = 0;
int cont2 = 0;


Dog::Dog()
{

}

Dog::~Dog()
{
}


void Dog::load(const LoaderParams* ppParams) {
	//pParams = new LoaderParams(ppParams->getX(), ppParams->getY(), ppParams->getWidth(), ppParams->getHeight(), ppParams->getTextureID(), ppParams->getnumFrames, ppParams->getcallbackID);
	Dog::pParams = ppParams;
	//TextureManager::Instance()->load("Dog.png", pParams->getTextureID(), Game::Instance()->getRender());
	m_position.setX(0);
	m_position.setY(300);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = 0;
	m_currentRow = 1;

}
void Dog::draw() {

	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	if (dir2 == 0) {
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
}
void Dog::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	m_velocity.setX(1);
	m_acceleration.setX(1);
	m_velocity.setY(0);
	m_acceleration.setY(0);

			if (m_position.getX() > 580) {
				cont2 = 1;
				dir2 = 1;
			}
			if (m_position.getX() < 2) {
				cont2 = 0;
				dir2 = 0;
			}
			if (cont2 == 0) {
				m_position.setX(m_position.getX() + 1);
				m_velocity += m_acceleration;
				m_position += m_velocity;
			}
			else {
				m_position.setX(m_position.getX() - 1);
				m_velocity += m_acceleration;
				m_position -= m_velocity;
			}
	
}
void Dog::clean() {

}

