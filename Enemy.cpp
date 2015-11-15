//Class Enemy para crear un GameObject Enemy
#include "Enemy.h"

//Constructor y destructor
Enemy::Enemy() {
	m_velocity.setX(5);
	m_velocity.setY(0);
	m_maxVelocity.setX(10);
	m_acceleration.setX(m_velocity.getX() + 0.02);
	m_friction.setX(m_velocity.getX() - 0.08);
};
Enemy::~Enemy() {};

SDL_RendererFlip flipEnemy = SDL_FLIP_NONE;

/*Funcion load que recibe todos lo parametros para hacer el load del Enemy,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void Enemy::load(const LoaderParams* pParams) {
	GameObject::load(pParams);
};

//Funcion para mostrar por pantalla la textura mediante la clase TextureManager
void Enemy::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flipEnemy);
};

void Enemy::update()
{
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	if (m_position.getX() <= 0) {
		m_velocity.setX(5);
		flipEnemy = SDL_FLIP_NONE;
	}
	else if (m_position.getX() >= Game::Instance()->getScreenWidth() - m_width) {
		m_velocity.setX(-5);
		flipEnemy = SDL_FLIP_HORIZONTAL;
	}
	m_position += m_velocity;
};

void Enemy::clean() {};