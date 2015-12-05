#include "TextureManager.h"
#include "Player.h"
#include "Game.h"
#include "InputHandler.h"



Player::Player() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setX(1);
	m_acceleration.setX(m_velocity.getX() + 0.05);
	m_desacceleration.setX(m_velocity.getX() - 0.05);
	m_frictionRight.setX(m_velocity.getX() - 0.02);
	m_frictionLeft.setX(m_velocity.getX() + 0.02);

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
	
	//m_velocity.setX(0.1);
	
	
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		std::cout << m_velocity.getX();
		printf("\n");
		m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
		m_velocity.setX(0.1);
		m_velocity.setX(m_acceleration.getX()+(m_velocity.getX() - m_frictionRight.getX()));
		m_maxVelocity.setX(m_velocity.getX());
		turn = SDL_FLIP_NONE;
		if (m_velocity.getX()==m_maxVelocity.getX()) {
			m_velocity.setX(m_velocity.getX()-m_desacceleration.getX());
		}
		if (m_position.getX() >= 1200) {
			m_position.setX(800);
		}

	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		std::cout << m_velocity.getX();
		printf("\n");
		m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
		m_velocity.setX(-0.1);
		m_velocity.setX(m_desacceleration.getX() + (m_velocity.getX() - m_frictionLeft.getX()));
		turn = SDL_FLIP_HORIZONTAL;
		if (m_velocity.getX() == m_maxVelocity.getX()) {
			m_velocity.setX(m_velocity.getX()+m_acceleration.getX());
		}
		if (m_position.getX() <= 0) {
			m_position.setX(0);
		}
	}
	else {
		m_currentFrame = 1;
		m_velocity.setX(0);
		
		
	}
	GameObject::update();
	
	
}

void Player::clean() {
};
