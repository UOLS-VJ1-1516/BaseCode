#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};


void Enemy::load(int x, int y, int width, int height,
	std::string texid)
	 {
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_texid = texid;
	m_currentFrame = 1;
	m_currentRow = 1;
	m_sprits = 1;
	m_flip = 0;
	}

void Enemy::load(const LoadPar* lPar)
 {
	m_width = lPar->getwidth();
	m_height = lPar->getheight();
	m_x = lPar->getx();
	m_y = lPar->gety();
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_sprits = lPar->getsprits();
	m_flip = lPar->getflip();
	
	};
void Enemy::draw()
{
	//TextureManager::Instance()->drawFrame(m_texid,m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), SDL_FLIP_NONE);
	TextureManager::Instance()->drawFrame("bird2", m_x, m_y, 200, 180, 1, 1, Game::Instance()->GetRenderer(), SDL_FLIP_NONE);
}
//char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* g_lRenderer, SDL_RendererFlip  flip

void Enemy::draw(SDL_Renderer* g_lRender) {
	//TextureManager::Instance()->drawFrame(m_texid, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, g_lRender, SDL_FLIP_NONE);
	TextureManager::Instance()->drawFrame("bird2", m_x, m_y, 200, 180, 1, 1, Game::Instance()->GetRenderer(), SDL_FLIP_NONE);
}

void Enemy::update() {
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
	
}
void Enemy::clean() {}