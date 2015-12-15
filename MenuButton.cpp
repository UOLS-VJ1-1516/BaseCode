#pragma once
#include "MenuButton.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "TextureManager.h"

MenuButton::MenuButton() {
	
}

void MenuButton::load(const LoaderParams* pParams) {
	GameObject::load(pParams);
	m_currentFrame = MOUSE_OUT;
	m_callbackID = pParams->getCallbackID();
}

void MenuButton::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void MenuButton::update() {
	Vector2D* mousePos = InputHandler::Instance()->getMousePosition();

	if (mousePos->getX() < (m_position.getX() + m_width) && mousePos->getX() > m_position.getX() && mousePos->getY() < (m_position.getY() + m_height)
		&& mousePos->getY() > m_position.getY()) {
		if (InputHandler::Instance()->getMouseButtonState(0) && m_bReleased) {
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0))	{
			m_currentFrame = MOUSE_OVER;
			m_bReleased = true;
		}
	}
	else {
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean() {
	InputHandler::Instance()->clean();
}