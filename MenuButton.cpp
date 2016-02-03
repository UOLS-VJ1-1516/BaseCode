#include "MenuButton.h"
#include "texturemanager.h"
#include "InputHandler.h"
#include "Game.h"



MenuButton::MenuButton() {
	
	
	//m_currentFrame = MOUSE_OUT  ;
	

};

MenuButton::~MenuButton() {};
void MenuButton::load(const LoadPar * lPar) {
	MenuButton::Params = lPar;
	m_bR = false;
	m_width = lPar->getWidth();
	m_height = lPar->getHeight();
	m_position.setX(lPar->getX());
	m_position.setY(lPar->getY());
	m_texid = lPar->getTextureID();
	m_sprits = lPar->getNumSprites();
	
	m_currentFrame = MOUSE_OUT;
	

};


void MenuButton::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(Params->getTextureID(),
		(int)Params->getX(), (int)Params->getY(),
		Params->getWidth(), Params->getHeight(),
		1, 1, Game::Instance()->GetRenderer(), 1);


}
void MenuButton::draw() {

	
	TextureManager::Instance()->drawFrame(Params->getTextureID(),
		(int)Params->getX(), (int)Params->getY(),
		Params->getWidth(), Params->getHeight(),
		1, 1, Game::Instance()->GetRenderer(), 1);

};

void MenuButton::update() {
	
	InputHandler::Instance()->update();
	
	pMPosition = InputHandler::Instance()->getMousePosition();

	if ((int)pMPosition->getX() < (Params->getX() + Params->getWidth())
		&& (int)pMPosition->getX() > Params->getX()
		&& (int)pMPosition->getY() < (Params->getY() + Params->getHeight())
		&& (int)pMPosition->getY() > Params->getY()) {

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

	
}

