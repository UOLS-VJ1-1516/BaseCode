#pragma once
#include "game.h"
#include "Player.h"
#include "TextureManager.h"
#include "Vector2D.h"

Player::Player() {};
Player::~Player() {};

void Player::draw(SDL_Renderer* pRender) {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Player::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_currentRow = 0;
	m_spriteNum = pParams->getSpriteNum();
}

void Player::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % m_spriteNum);

	if (m_position.getX() >= 600) {
		m_velocity.setX(-5);
		flip = SDL_FLIP_HORIZONTAL;
	}
	else if (m_position.getX() <= 0) {
		m_velocity.setX(5);
		flip = SDL_FLIP_NONE;
	}
}

void Player::clean() {};