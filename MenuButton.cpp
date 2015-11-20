#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams * pParams, void(*callback)()) :m_callback(callback) {
	MenuButton::Params = pParams;

	m_bR = false;
	m_currentFrame = MOUSE_OUT;
	TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender());

};

MenuButton::~MenuButton() {};
void MenuButton::load(const LoaderParams * pParams) {
		
};

void MenuButton::draw() {
	
	TextureManager::Instance()->drawFrame(Params->getTextureID(),
		(int)Params->getX(), (int)Params->getY(),
		Params->getWidth(), Params->getHeight(),
		0, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void MenuButton::update() {
	InputHandler::Instance()->update();

	pMPosition = InputHandler::Instance()->getMousePosition();
	printf("x= %d | y= %d\n", (int)pMPosition->getX(), (int)pMPosition->getY());
	if ((int)pMPosition->getX() < (Params->getX() + Params->getWidth())
		&& (int)pMPosition->getX() > Params->getX()
		&& (int)pMPosition->getY() < (Params->getY() + Params->getHeight())
		&& (int)pMPosition->getY() > Params->getY()){

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
