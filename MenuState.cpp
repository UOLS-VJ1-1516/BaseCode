#include "MenuState.h"

void MenuState::update() {
	//o->update();
	mb->update();
};

void MenuState::render() {
	//o->draw
	mb->draw();
};

bool MenuState::onEnter() {
	lmb = new LoaderParams(150, 250, 223, 52, "Button", 2, 0, 0, 0, 0);
	mb = new MenuButton(lmb, s_menuToPlay);
	
	m_gameObjects.push_back(mb);

	return true;
};

bool MenuState::onExit() {

	return true;
};

const std::string MenuState::s_menuID = "Menu";

std::string MenuState::getStateID() const{

	return MenuState::s_menuID;
};

void MenuState::s_menuToPlay() {

};