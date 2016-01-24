#include "TextureManager.h"
#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "Camera.h"
#include "SoundManager.h"

Player::Player() {
	mJump = false; 
	
};

Player::~Player() {};

void Player::draw()
{
	if (isCollisionWithTile(m_position)) {
		stopY((int)m_position.getY());
		mJump = false;
	}
	//if (m_velocity.getX() < 0) {
		// turn = SDL_FLIP_NONE;
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turn);
	//}
	/*else if (m_velocity.getX() >= 0) {
		 turn = SDL_FLIP_HORIZONTAL;
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turn );
	}*/
}

void Player::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_lastStop = Vector2D(0, 0);
	m_currentFrame = 0;
	m_maxVelocity = 10;
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setX(0);
	m_acceleration.setY(0);
};

void Player::update() {
	
	int pixelsToChangeFrame = 12;
	Vector2D v0 = m_velocity;
	SDL_Event event;
	SDL_PollEvent(&event);


	if (m_velocity.getX() > 0) {
		decrementAccelerationX();
	}
	if (m_velocity.getX() < 0) {
		incrementAccelerationX();
	}
	if (m_velocity.getY() > 0) {
		decrementAccelerationY();
	}
	if (m_velocity.getY() < 0) {
		incrementAccelerationY();
	}
	m_velocity += m_acceleration;
	if (m_velocity.getX()*v0.getX() < 0 || m_velocity.getX() == 0) {
		stopX(m_position.getX());
	}
	if (m_velocity.getY()*v0.getY() < 0 || m_velocity.getY() == 0) {
		stopY(m_position.getY());
	}
	if (m_velocity.length() > m_maxVelocity) {
		m_velocity = m_velocity.normalize()*m_maxVelocity;
		m_acceleration.setX(0);
	}
	m_position += m_velocity + m_acceleration * 1 / 2;
	m_currentFrame = (abs((int)(m_position - m_lastStop).length()) / pixelsToChangeFrame) % m_spriteNum;

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		incrementAccelerationX();
		turn = SDL_FLIP_HORIZONTAL;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		turn = SDL_FLIP_NONE;
		decrementAccelerationX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		decrementAccelerationY();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		if (!mJump) {
 			jump();
			SoundManager::Instance()->playSound("jump",0,1);
			//mJump = true;
		}
			
	}

	if (m_position.getX() < 0) {
		stopX(0);
	}
	if (m_position.getX() > (Game::Instance()->getGameWidth() - m_width)) {
		stopX(Game::Instance()->getGameWidth() - m_width);
	}
	if (m_position.getY() < 0) {
		stopY(0);
	}
	if (m_position.getY() > (Game::Instance()->getGameHeight() - m_height)) {
		stopY(Game::Instance()->getGameHeight() - m_height);
	}

	incrementAccelerationY();
	Camera::Instance()->setPosition(m_position);
	CollisionObject::update();
}

void Player::stopX(int positionX)
{
	m_lastStop.setX(positionX);
	m_position.setX(positionX);
	m_velocity.setX(0);
	m_acceleration.setX(0);
}

void Player::stopY(int positionY)
{
	m_lastStop.setY(positionY);
	m_position.setY(positionY);
	m_velocity.setY(0);
	m_acceleration.setY(0);
}

void Player::incrementAccelerationX()
{
	m_acceleration.setX(m_acceleration.getX() + 0.1);
}
void Player::decrementAccelerationX()
{
	m_acceleration.setX(m_acceleration.getX() - 0.1);
}
void Player::incrementAccelerationY()
{
	m_acceleration.setY(m_acceleration.getY() + 0.1);
}
void Player::decrementAccelerationY()
{
	m_acceleration.setY(m_acceleration.getY() - 0.1);
}

void Player::jump()
{
	//m_acceleration.setY(m_acceleration.getY() - 0.6);
 	m_velocity.setY(-m_maxVelocity);
	mJump = true;
}

/*void Player::collision() {
return ;
}*/
;

/*Player::Player() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity=10;
	m_acceleration.setX(m_velocity.getX() + 0.05);
	m_acceleration.setY(0);
	m_desacceleration.setX(m_velocity.getX() - 0.05);
	m_frictionRight.setX(m_velocity.getX() - 0.02);
	m_frictionLeft.setX(m_velocity.getX() + 0.02);

};
Player::~Player() {};
SDL_RendererFlip turn = SDL_FLIP_HORIZONTAL;

void Player::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width,
		m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turn);
}
void Player::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;

}
void Player::update() {

	//m_velocity.setX(0.1);
	m_velocity += m_acceleration;

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		incrementAccelerationX();
		std::cout << m_velocity.getX();
		printf("\n");
		m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
		m_velocity.setX(m_acceleration.getX() + (m_velocity.getX() - m_frictionRight.getX()));
		m_position += m_velocity + m_acceleration * 1 / 2;
		m_maxVelocity = m_velocity.getX();
		turn = SDL_FLIP_HORIZONTAL;
		if (m_velocity.getX() == m_maxVelocity) {
			m_velocity.setX(m_velocity.getX() - m_acceleration.getX());
		}
		if (m_position.getX() >= 1200) {
			m_position.setX(Game::Instance()->getGameWidth());
		}
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		decrementAccelerationX();
		std::cout << m_velocity.getX();
		printf("\n");
		m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
		m_velocity.setX(m_velocity.getX()* -1);
		m_velocity.setX(m_acceleration.getX() + (m_velocity.getX() - m_frictionLeft.getX()));
		m_position += m_velocity + m_acceleration * 1 / 2;
		turn = SDL_FLIP_NONE;
		if (m_velocity.getX() == m_maxVelocity) {
			m_velocity.setX(m_velocity.getX() + m_acceleration.getX());
		}
		if (m_position.getX() <= 0) {
			m_position.setX(0);
		}
	}
	else {
		m_currentFrame = 1;
		m_velocity.setX(0);


	}
	incrementAccelerationY();
	GameObject::update();
	
}*/
void Player::clean() {
};