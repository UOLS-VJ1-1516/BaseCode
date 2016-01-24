#include "Enemy.h"

//Constructor y destructor
Enemy::Enemy() {
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_maxVelocity.m_x = 20;
	m_maxVelocity.m_y = 20;
	m_minVelocity.m_x = -20;
	m_minVelocity.m_y = -20;
	m_acceleration.m_x = 2;
	m_acceleration.m_y = 0;
	m_friction.m_x = 0;
	m_friction.m_y = 0;
	m_flip = SDL_FLIP_NONE;
};
Enemy::~Enemy() {};

/*Funcion load que recibe todos lo parametros para hacer el load del Enemy,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void Enemy::load(const LoaderParams* pParams) {
	GameObject::load(pParams);
};

//Funcion para mostrar por pantalla la textura mediante la clase TextureManager
void Enemy::draw() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};

//Función para updatear las diferentes opciones del enemigo
void Enemy::update()
{
	CollisionObject::update();
};

//Función para limpiar
void Enemy::clean() {};