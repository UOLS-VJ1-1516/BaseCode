#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton()
{
}

/*MenuButton::MenuButton(const LoaderParams * pParams, void(*callback)()) :m_callback(callback) {
	//MenuButton::Params = pParams;
	GameObject::load(pParams);
	m_bR = false;
	m_callbackID = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
	TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender());

};*/

void MenuButton::load(const LoaderParams * pParams) {
	
	m_callbackID = pParams->getCallbackID();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	
};

void MenuButton::draw() {
	
	TextureManager::Instance()->drawFrame(m_textureID,
		m_position.getX(), m_position.getY(),
		m_width, m_height,
		0, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
		
};

void MenuButton::update() {
	InputHandler::Instance()->update();

	pMPosition = InputHandler::Instance()->getMousePosition();
	printf("x= %d | y= %d\n", (int)pMPosition->getX(), (int)pMPosition->getY());
	if ((int)pMPosition->getX() < (pParams->getX() + pParams->getWidth())
		&& (int)pMPosition->getX() > pParams->getX()
		&& (int)pMPosition->getY() < (pParams->getY() + pParams->getHeight())
		&& (int)pMPosition->getY() > pParams->getY()){

		if (InputHandler::Instance()->getMouseButtonState(0)) {
			m_currentFrame = CLIKED;
			if (m_bR) {
				m_bR = false;
			}
			
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0)) {
			if (!m_bR && m_currentFrame == CLIKED) {
				m_callback();
			}
			m_bR = true;
			m_currentFrame = MOUSE_OVER;
		}

	}
	else {
		m_currentFrame = MOUSE_OUT;
	}
	
}
void MenuButton::clean() {
	InputHandler::Instance()->clean();
}

