#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

GameObject::GameObject() {};

GameObject::~GameObject() {};

void GameObject::load(int x, int y, int width, int height, std::string textureID){
	m_textureID = textureID;
	m_width = width;
	m_height = height;
	m_currentFrame = 0;
	m_currentRow = 0;
	m_x = x;
	m_y = y;
};

void GameObject::draw() {
	TextureManager::Instance()->drawFrame("Player", 300, 200, 104, 151, 0, spriteNum, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void GameObject::update() {
	spriteNum = (int)((SDL_GetTicks() / 100) % 6);
};

void GameObject::clean() {};