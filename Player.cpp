//Class Player para crear un GameObject Player
#include "Player.h"
#include "game.h"

//Constructor y destructor
Player::Player(){
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setX(10);
	m_acceleration.setX(m_velocity.getX() + 0.02);
	m_friction.setX(m_velocity.getX() - 0.08);
};
Player::~Player(){};

SDL_RendererFlip flip = SDL_FLIP_NONE;

/*Funcion load que recibe todos lo parametros para hacer el load del Player,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void Player::load(const LoaderParams* pParams){
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_spriteNum = pParams->getSpriteNum();
	m_currentRow = pParams->getRowNum();
	TextureManager::Instance()->load(m_fileName, m_textureID, Game::Instance()->getRenderer());
	TextureManager::Instance()->setFrame(m_textureID, m_width, m_height);
};

//Funcion para mostrar por pantalla la textura mediante la clase TextureManager
void Player::draw(){
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flip);
};

void Player::update()
{
	m_currentFrame = 0;

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
	
	controlPosition();
};

void Player::moveLeft(){
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	flip = SDL_FLIP_HORIZONTAL;
	m_acceleration.setX(m_acceleration.getX() + 0.001);
	m_velocity.setX(m_velocity.getX() + (m_acceleration.getX() - m_friction.getX()));
	if (m_velocity.getX() >= m_maxVelocity.getX()) {
		m_velocity.setX(m_maxVelocity.getX());
	}
	m_position -= m_velocity;
};

void Player::moveRight() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	flip = SDL_FLIP_NONE;
	m_acceleration.setX(m_acceleration.getX() + 0.001);
	m_velocity.setX(m_velocity.getX() + (m_acceleration.getX() - m_friction.getX()));
	if (m_velocity.getX() >= m_maxVelocity.getX()) {
		m_velocity.setX(m_maxVelocity.getX());
	}
	m_position += m_velocity;
};

void Player::noMoveX() {
	m_velocity.setX(0);
	m_acceleration.setX(0);
};

void Player::controlPosition() {
	if (m_position.getX() >= Game::Instance()->getScreenWidth() - m_width)
	{
		m_position.setX(Game::Instance()->getScreenWidth() - m_width);
	}
	else if (m_position.getX() <= 0) {
		m_position.setX(0);
	}
};

void Player::clean(){};