#include "Player.h"
#include "Game.h"
#include "TextureManager.h"
#include "string"

Player::Player() {}  //Constructor}
Player::~Player() {}

int  m_currentFrame;
SDL_RendererFlip reverse = SDL_FLIP_NONE;

void Player::load(const LoaderParams* pParams) {

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_velocity.setX(0);
	m_velocity.setY(0);

	m_acceleration.setX(1.4);
	m_acceleration.setY(0);
	
	m_maxVelocity.setX(8);
	m_maxVelocity.setY(0);

	m_friction.setX(0.6);
	m_friction.setY(0.0);

	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());

	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getSprits();
	m_currentRow = pParams->getCurrentRow();

}

void Player::draw() {

	TextureManager::Instance()->drawFrame(m_textureID,(m_position.getX()), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(),reverse);
}

void Player::update() {

	Vector2D m_velocity_aux;
	m_currentFrame = 5;

	if (m_position.getX() + 100 <= (Game::Instance()->getP_ANC())) {
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{		
			if (m_maxVelocity.getX() <= m_velocity.getX()) {
				m_velocity.setX(m_maxVelocity.getX());
			}else{
				m_velocity += m_acceleration - m_friction;
			}		
			m_currentFrame = (int)((SDL_GetTicks() / 100) % m_spriteNum);
			reverse = SDL_FLIP_NONE;
			
		}
	}
	if ((m_position.getX()) >= 0) {
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{		
			if (-(m_maxVelocity.getX()) >= m_velocity.getX()) {
				m_velocity.setX(-(m_maxVelocity.getX()));
			}else{
				m_velocity -= m_acceleration - m_friction;
			}
			m_currentFrame = (int)((SDL_GetTicks() / 100) % 7);
			reverse = SDL_FLIP_HORIZONTAL;
			
		}
	}

	if ((m_velocity.getX()>0)&&(m_velocity.getX()-m_friction.getX()>0)) {
		m_velocity -= m_friction;
	}
	else if ((m_velocity.getX()<0) && (m_velocity.getX() + m_friction.getX()<0)) {
		m_velocity += m_friction;
	}
	else {
		m_velocity.setX(0);
	}

	m_position += m_velocity;


	//------------------ LIMITS PANTALLA ----------------------
	if (m_position.getX() + m_width > Game::Instance()->getP_ANC()) {
		m_position.setX(Game::Instance()->getP_ANC() - m_width);
	}
	if (m_position.getX() < 0) {
		m_position.setX(0);	
	}


}

void Player::clean() {}