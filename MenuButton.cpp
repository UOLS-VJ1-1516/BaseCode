#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton() {
	
};

MenuButton::~MenuButton(){};
void MenuButton::load(const LoaderParams* pParams) {
	MenuButton::Params = pParams;

	m_bReleased = false;
}
void MenuButton::setCallback(void(*callback)())
{
	this->m_callback = callback;
}


void MenuButton::draw() {
	TextureManager::Instance()->draw(Params->getTextureID(), Params->getX(), Params->getY(), Params->getWidth(), Params->getHeight(), m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void MenuButton::update() {
	InputHandler::Instance()->update();
	
	pMousePos = InputHandler::Instance()->getMousePosition();
	printf("x: %f - y: %f\n", pMousePos->getX(), pMousePos->getY());

	if (pMousePos->getX() < (Params->getX() + Params->getWidth())
		&& pMousePos->getX() > Params->getX()
		&& pMousePos->getY() < (Params->getY() + Params->getHeight())
		&& pMousePos->getY() > Params->getY())
	{
		if (InputHandler::Instance()->getMouseButtonState(0)) {
			m_currentFrame = CLICKED;
			if (m_bReleased) {
				m_bReleased = false;
			}
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0)) {
			if (!m_bReleased && m_currentFrame == CLICKED) { m_callback(); };
			m_bReleased = true;      
			m_currentFrame = MOUSE_OVER; 
		}
	}
	else { 
		m_currentFrame = MOUSE_OUT; 
	}
};

void MenuButton::clean() {
	InputHandler::Instance()->clean();
};