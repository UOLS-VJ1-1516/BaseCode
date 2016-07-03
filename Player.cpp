#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"


Player::Player() {};
Player::~Player() {};


void Player::load(const LoaderParams* pParams)
{

	m_textureID = pParams->getTextureID();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());

	//m_x = pParams->getX(); 
	//m_y = pParams->getY();

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	
	m_currentRow = 0;
	m_sprite = pParams->getSprits();
	//m_currentFrame = 0;
	m_velocity.setX(0);
	m_velocity.setY(0);

}

void Player::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	
	
	

}

void Player::update() {
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);

	m_currentFrame = (int)((Game::Instance()->getP() / 100) % m_sprite);

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) { m_velocity.setX(2); }
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) { m_velocity.setX(-2); }
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) { m_velocity.setY(-2); }
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) { m_velocity.setY(2); }

	m_acceleration.setX(1);

	m_velocity.setX(1);
	
}


void Player::clean() {};