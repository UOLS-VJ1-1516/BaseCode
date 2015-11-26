#include "MenuButton.h"
#include "texturemanager.h"
#include "InputHandler.h"
#include "Game.h"



MenuButton::MenuButton(const LoadPar * lPar, void(*callback)()) :m_callback(callback) {
	MenuButton::Params = lPar;
	m_bR = false;
	m_currentFrame = MOUSE_OUT;
	

};

MenuButton::~MenuButton() {};
void MenuButton::load(const LoadPar * lPar) {
	m_width = lPar->getwidth();
	m_height = lPar->getheight();
	m_position.setX(lPar->getx());
	m_position.setY(lPar->gety());
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_sprits = lPar->getsprits();
	m_flip = lPar->getflip();
	m_anchopantalla = lPar->getanchopantalla();  //Para que sea mas facil de adaptar
	m_altopantalla = lPar->getaltopantalla();
	

};


void MenuButton::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(Params->gettexid(),
		(int)Params->getx(), (int)Params->gety(),
		Params->getwidth(), Params->getheight(),
		Params->getcurrentRow(), m_currentFrame, Game::Instance()->GetRenderer(), 1);


}
void MenuButton::draw() {

	//m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), 
	TextureManager::Instance()->drawFrame(Params->gettexid(),
		(int)Params->getx(), (int)Params->gety(),
		Params->getwidth(), Params->getheight(),
		1, 1, Game::Instance()->GetRenderer(), 1);

};

void MenuButton::update() {
	
	InputHandler::Instance()->update();
	
	pMPosition = InputHandler::Instance()->getMousePosition();

	if ((int)pMPosition->getX() < (Params->getx() + Params->getwidth())
		&& (int)pMPosition->getX() > Params->getx()
		&& (int)pMPosition->getY() < (Params->gety() + Params->getheight())
		&& (int)pMPosition->getY() > Params->gety()) {

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