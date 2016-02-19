#include "MenuButton.h"
#include "InputHandler.h"
#include "game.h"

MenuButton::MenuButton() {	
}

MenuButton::~MenuButton() {
}

void MenuButton::load(const LoaderParams* pParams) {
	m_currentFrame = MOUSE_OUT;
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 0;
	m_bReleased = false;
	m_callbackID = pParams->getCallbackID();
}

void MenuButton::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void MenuButton::update() {
	InputHandler::Instance()->update();
	
	Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width) && pMousePos->getX() > m_position.getX() && pMousePos->getY() < (m_position.getY() + m_height) && pMousePos->getY() > m_position.getY()) {
	if (InputHandler::Instance()->getMouseButtonState(0)) {
		m_currentFrame = CLICKED;
		if (m_bReleased) {
			m_bReleased = false; 
		}
	}
	else if (!InputHandler::Instance()->getMouseButtonState(0)) {
		if (!m_bReleased && m_currentFrame == CLICKED) {
			m_callback();
		}
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

void MenuButton::onCollision(GameObject * other)
{
}
