#include "Player.h"
#include "TextureManager.h"
#include "game.h"


int dir = 0;
int dreta = 1;

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::load(const LoaderParams* ppParams) {
	//pParams = new LoaderParams(ppParams->getX(), ppParams->getY(), ppParams->getWidth(), ppParams->getHeight(), ppParams->getTextureID(), ppParams->getnumFrames, ppParams->getcallbackID);
	Player::pParams = ppParams;
	TextureManager::Instance()->load("spritesheet.png", pParams->getTextureID(), Game::Instance()->getRender());
	m_position.setX(0);
	m_position.setY(180);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = 0;
	m_currentRow = 1;

}
void Player::draw() {
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

	if(dir == 1){
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
	} 
	else {
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
}
void Player::update() {
	m_velocity.setX(1);
	m_acceleration.setX(1);
	m_velocity.setY(0);
	m_acceleration.setY(0);

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		dir = 0;
		if (m_position.getX() > 599) {
		}
		else {
			if (m_position.getX() < 0) {
			}
			else
			{
				m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
				m_velocity.setX(-2);
				m_velocity -= m_acceleration;
				m_position -= m_velocity;
			}
		}
	}
	else {
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			dir = 1;
			if (m_position.getX() > 600) {
			}
			else {
				if (m_position.getX() < 1) {
				}
				else {
					m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
					m_velocity.setX(2);
					m_velocity += m_acceleration;
					m_position -= m_velocity;
				}
			}

		}
	}
}
void Player::clean() {

}

void Player::handleInput()
{
	Vector2D target = InputHandler::Instance()->getMousePosition();
	m_velocity = target - m_position;
	m_velocity /= 50;
}

