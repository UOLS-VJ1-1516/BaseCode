#include "Player.h"
#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "string"

Player::Player() {}  //Constructor}
Player::~Player() {}

int m_x = -50;
int iW = 100, iH = 100;
const int P_ANC = 1280;
const int P_ALT = 720;
int  m_currentFrame;

void Player::load(const LoaderParams* pParams) {

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getSprits();
	m_currentRow = pParams->getCurrentRow();

}

void Player::draw() {

	TextureManager::Instance()->drawFrame(m_textureID, m_x*2, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Player::update() {


	m_currentFrame = (int)((SDL_GetTicks() / 100) % 7);

	if (m_x >(P_ANC / 2)) {
		m_x = -50;
	}
	m_x++;
}

void Player::clean() {}