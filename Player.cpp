#include "TextureManager.h"
#include "Player.h"
#include "Game.h"
#include "InputHandler.h"


Player::Player() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setX(1);
	m_acceleration.setX(m_velocity.getX() + 0.02);
	m_friction.setX(m_velocity.getX() - 0.08);

};
Player::~Player() {};
SDL_RendererFlip turn = SDL_FLIP_NONE;

void Player::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, 
		m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turn);
}
void Player::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;

}
void Player::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	//m_velocity.setX(0.1);
	
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(0.1);
		m_velocity.setX(m_acceleration.getX()+(m_velocity.getX() - m_friction.getX()));
		turn = SDL_FLIP_NONE;
		if (m_maxVelocity.getX()>=1) {
			m_velocity.setX(0.1);
		}
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-0.1);
		m_velocity.setX(m_acceleration.getX() + (m_velocity.getX() + m_friction.getX()));
		turn = SDL_FLIP_HORIZONTAL;
	}
	else {
		m_velocity.setX(0);
		
		
	}
	GameObject::update();
	
	
}

void Player::clean() {
};
