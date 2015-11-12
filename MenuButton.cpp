#include "MenuButton.h"
#include "Game.h"

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) {
	MenuButton::Params = pParams;
	if (TextureManager::Instance()->load("button.bmp", "Button", Game::Instance()->getRender())) {
		TextureManager::Instance()->setSizeFrames("Button", 223, 52);
	}
	
};

MenuButton::~MenuButton(){
};

void MenuButton::load(const LoaderParams* pParam) {

};

void MenuButton::draw() {
	//printf("* %d", InputHandler::Instance()->getMouseButtonState(0));
	if (InputHandler::Instance()->getMouseButtonState(0)) {
		//if (InputHandler::Instance()->getMousePosition().getX() > Params->getX() && InputHandler::Instance()->getMousePosition().getX()< (Params->getX() + Params->getWidth())) {
		//	if (InputHandler::Instance()->getMousePosition().getX() > Params->getY() && InputHandler::Instance()->getMousePosition().getY()< (Params->getY() + Params->getHeight())) {
				TextureManager::Instance()->drawFrame(Params->getTextureID(), Params->getX(), Params->getY(), Params->getWidth(), Params->getHeight(), 0, 1, Game::Instance()->getRender(), SDL_FLIP_NONE);
		//	}
		//}
	}
	else {
		TextureManager::Instance()->drawFrame(Params->getTextureID(), Params->getX(), Params->getY(), Params->getWidth(), Params->getHeight(), 0, 0, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
};

void MenuButton::update() {
	InputHandler::Instance()->update();
};

void MenuButton::clean() {
	InputHandler::Instance()->clean();
};