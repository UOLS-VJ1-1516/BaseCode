/*#include "GameObject.h"
#include "TextureManager.h"

//GameObject::GameObject() {}
int m_width;
int m_height;
int m_currentFrame;
int m_currentRow;
int m_x;
int m_y;
std::string m_textureID;


//GameObject::~GameObject() {}

void load(int x, int y, int width, int height,
	std::string textureID) {
	m_x = x;
	m_y = y;

	m_width = width;
	m_height = height;

	m_textureID = textureID;
	m_currentFrame = 1;
	m_currentRow = 1;
}

void draw(SDL_Renderer* pRender) {
	TextureManager::Instance()->draw("player", 100, 100, 35, 32, pRender,SDL_FLIP_HORIZONTAL);
}

void update() {
	m_x += 1;
}

void clean() {}
*/