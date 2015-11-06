#include "Player.h"
#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "string"


Player::Player() {}  //Constructor}
Player::~Player() {}

int  m_currentFrame;
SDL_RendererFlip reverse = SDL_FLIP_NONE;

void Player::load(const LoaderParams* pParams) {

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_velocity.setX(1);
	m_velocity.setY(0);


	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());

	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getSprits();
	m_currentRow = pParams->getCurrentRow();

}

void Player::draw() {

	TextureManager::Instance()->drawFrame(m_textureID,(m_position.getX())*2, m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(),reverse);
}

void Player::update() {

	m_currentFrame = (int)((SDL_GetTicks() / 100) % 7);

	if (m_position.getX() + 50 > (Game::Instance()->getP_ANC() / 2)) {
		m_velocity.setX(-1);
		reverse = SDL_FLIP_HORIZONTAL;
	}
	else if ((m_position.getX()) == (float)0) {
		m_velocity.setX(1);
		reverse = SDL_FLIP_NONE;

	}
		
	m_position += m_velocity;
}

void Player::clean() {}