#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams * pParams, void(*callback)()) :m_callback(callback) {
	MenuButton::Params = pParams;

	m_bR = false;

	TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender());

};

MenuButton::~MenuButton() {};
void MenuButton::load(const LoaderParams * pParams) {
	
	
	m_currentFrame = MOUSE_OUT;
};

void MenuButton::draw() {
	
	TextureManager::Instance()->drawFrame(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,
		m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void MenuButton::update() {
	InputHandler::Instance()->update();

	pMPosition = InputHandler::Instance()->getMousePosition();

	if (pMPosition->getX() < (Params->getX() + Params->getWidth())
		&& pMPosition->getX() > Params->getX()
		&& pMPosition->getY() < (Params->getY() + Params->getHeight())
		&& pMPosition->getY() > Params->getY()){

		if (InputHandler::Instance()->getMouseButtonState(0)) {
			m_currentFrame = CLIKED;
			if (m_bR) {
				m_bR = false;
			}
			else if (!InputHandler::Instance()->getMouseButtonState(0)) {
				if (!m_bR && m_currentFrame == CLIKED) {
					m_callback();
				}
				m_bR = true;
				m_currentFrame = MOUSE_OVER;
			}
			else {
				m_currentFrame = MOUSE_OUT;
			}
		}
	}
	
}
void MenuButton::clean() {
	InputHandler::Instance()->clean();
}
