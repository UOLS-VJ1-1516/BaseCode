//Class Player para crear un GameObject Player
#include "Player.h"

//Constructor y destructor
Player::Player() {
	topeJump = 2;
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_maxVelocity.m_x = 20;
	m_maxVelocity.m_y = 20;
	m_minVelocity.m_x = -20;
	m_minVelocity.m_y = -20;
	m_acceleration.m_x = 0;
	m_acceleration.m_y = 0;
	m_friction.m_x = 0;
	m_friction.m_y = 0;
	m_flip = SDL_FLIP_NONE;
};
Player::~Player() {};

/*Funcion load que recibe todos lo parametros para hacer el load del Player,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void Player::load(const LoaderParams* pParams) {
	GameObject::load(pParams);
};

//Funcion para mostrar por pantalla la textura mediante la clase TextureManager
void Player::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};

//Funcion que realiza los movimientos del Player
void Player::update()
{
	m_currentFrame = 0;

	m_acceleration.m_y = 10;

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		moveRight();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		moveLeft();
	}
	else {
		noMoveX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		topeJump += 0.1;
		if (topeJump < 1)
		{
			jump();
		}
	}

	controlPosition();
	CollisionObject::update();
};

//Funcion si el player se mueve a la izquierda
void Player::moveLeft() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	m_flip = SDL_FLIP_HORIZONTAL;
	m_acceleration.m_x = -2;
};

//Funcion si el player se mueve a la derecha
void Player::moveRight() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	m_flip = SDL_FLIP_NONE;
	m_acceleration.m_x = 2;
};

//Funcion si el player no se mueve
void Player::noMoveX() {
	m_velocity.m_x = 0;
	m_acceleration.m_x = 0;
};

//Funcion que controla que el player no salga de pantalla
void Player::controlPosition() {
	if (m_position.m_x >= Game::Instance()->getScreenWidth() - m_width)
	{
		m_position.setX(Game::Instance()->getScreenWidth() - m_width);
	}
	else if (m_position.m_x <= 0) {
		m_position.setX(0);
	}

	if (m_position.m_y >= Game::Instance()->getScreenHeight() - m_height)
	{
		m_position.setY(Game::Instance()->getScreenHeight() - m_height);
	}
	else if (m_position.m_y <= 0) {
		m_position.setY(0);
	}
};

void Player::jump() {
	m_acceleration.m_y = -10;
};

//Funcion para limpiar la clase Player
void Player::clean() {};