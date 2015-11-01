#include "game.h"
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {};
GameObject::~GameObject() {};

void GameObject::load(int x, int y, int width, int height, std::string textureID) {
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	m_textureID = textureID;
}

void GameObject::draw() {
	TextureManager::Instance()->drawFrame("walker", 58, 38, 58, 38, numRow, spriteNum, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void GameObject::update() {
	spriteNum = int((SDL_GetTicks() / 100) % 12);
	numRow = int((SDL_GetTicks() / 1200) % 2);
}

void GameObject::clean() {};