#include "MenuState.h"
#include "MenuButton.h"

void MenuState::update() {

};
void MenuState::render() {

};
bool MenuState::onEnter() {

	return true;
};
bool MenuState::onExit() {

	return true;
};

const std::string MenuState::s_menuID = "Menu";

std::string MenuState::getStateID() const{

	return MenuState::s_menuID;
};