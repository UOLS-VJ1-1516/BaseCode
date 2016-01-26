#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Camera.h"

Player::Player() {
	m_jump = true;

};
Player::~Player() {};

void Player::draw()
{
	
	if (m_velocity.getX() < 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
		m_Orientation = SDL_FLIP_HORIZONTAL;
	}
	else if (m_velocity.getX() > 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
		m_Orientation = SDL_FLIP_NONE;
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, 0, Game::Instance()->getRender(), m_Orientation);
	}
}


void Player::load(const LoaderParams* pParams)
{
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_lastPosition.setX(0);
	m_lastPosition.setY(0);
	m_currentFrame = 0;
	m_velocityMax = pParams->getSpeedMax();
	m_velocity.setX(pParams->getSpeed_x());
	m_velocity.setY(pParams->getSpeed_y());
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_frictionCoeficient = pParams->getFriction();
	m_friction = m_velocity*m_frictionCoeficient;
	m_Orientation = SDL_FLIP_NONE;

};
void Player::update() {
	/*Vector2D velocityInicial = m_velocity;
	int pixelsToChangeFrame = 9;
	SDL_Event event;
	SDL_PollEvent(&event);

	if (m_position.getX() < 0) {
		Stop(0);
	}		
	if (m_position.getX() > (Game::Instance()->getScreenWidth() - m_width)) {
		Stop(Game::Instance()->getScreenWidth() - m_width);
	}

	if (m_position.getY() < 0) {
		StopY(0);
	}
	if (m_position.getY() > (Game::Instance()->getScreenHeight() - m_height)) {
		StopY(Game::Instance()->getScreenHeight() - m_height);
	}

	if (m_velocity.getX() < 0) {
		incrementAccelerationX();
	}
	if (m_velocity.getX() > 0) {
		decrementAccelerationX();
	}
	if (m_velocity.getY() > 0) {
		decrementAccelerationY();
	}
	if (m_velocity.getY() < 0) {
		incrementAccelerationY();
	}

	m_velocity += m_acceleration;

	if (m_velocity.getX()*velocityInicial.getX() < 0 || m_velocity.getX() == 0) {
		Stop(m_position.getX());
	}
	if (m_velocity.getY()*velocityInicial.getY() < 0 || m_velocity.getY() == 0) {
		StopY(m_position.getY());
	}
	if (m_velocity.length() > m_velocityMax) {
		m_velocity = m_velocity.normalize()*m_velocityMax;
		m_acceleration.setX(0);
	}
	m_position += m_velocity + m_acceleration * 1/2;
	m_currentFrame = (abs((int)(m_position - m_lastPosition).length()) / pixelsToChangeFrame) % m_spriteNum;


	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		incrementAccelerationX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		decrementAccelerationX();
	}

	if (InputHandler::Instance()->Quit())
	{
		Game::Instance()->setIsRunning(false);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		m_jump += 0.1;
		if (m_jump < 2)
			 jump();
		
	}
	incrementAccelerationY();*/

	if (isCollisionWithTile()) {
		printf("->%d\n", getCollisionDirection());
		/*switch (getCollisionDirection())
		{
		case 2: stopY((int)m_position.getY()); break;
		case 3: stopX((int)m_position.getX() + m_TileWith); break;
		case 4: stopY((int)m_position.getY() + m_TileHeight); break;
		case 1: stopX((int)m_position.getX()); break;
		}*/
		StopY((int)m_position.getY());
		m_jump = false;
	}
	m_jump = false;
	int pixelsToChangeFrame = 6;
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
		Stop(m_position.getX());
	}
	if (m_velocity.getY()*v0.getY() < 0 || m_velocity.getY() == 0) {
		StopY(m_position.getY());
	}
	if (m_velocity.length() > m_velocityMax) {
		m_velocity = m_velocity.normalize()*m_velocityMax;
		m_acceleration.setX(0);
	}
	m_position += m_velocity + m_acceleration * 1 / 2;
	m_currentFrame = (abs((int)(m_position - m_lastPosition).length()) / pixelsToChangeFrame) % m_spriteNum;

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		incrementAccelerationX();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		decrementAccelerationX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		decrementAccelerationY();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		if (!m_jump) {
			jump();
			m_jump = true;
		}

	}

	if (m_position.getX() < 0) {
		Stop(0);
	}
	if (m_position.getX() > (Game::Instance()->getScreenWidth() - m_width)) {
		Stop(Game::Instance()->getScreenWidth() - m_width);
	}
	if (m_position.getY() < 0) {
		StopY(0);
	}
	if (m_position.getY() > (Game::Instance()->getScreenHeight() - m_height)) {
		StopY(Game::Instance()->getScreenHeight() - m_height);
	}
	incrementAccelerationY();
	TheCamera::Instance()->setPosition(m_position);

};

void Player::jump()
{
	//m_acceleration.setY(m_acceleration.getY() - 0.9);
	m_velocity.setY(-19);

}

void Player::onCollision(GameObject * other)
{
}

void Player::clean() {
};

void Player::incrementAccelerationX()
{
	m_acceleration.setX(m_acceleration.getX() + 0.7);
}
void Player::decrementAccelerationX()
{
	m_acceleration.setX(m_acceleration.getX() - 0.7);
}
void Player::incrementAccelerationY()
{
	m_acceleration.setY(m_acceleration.getY() + 0.7);//0.3
}
void Player::decrementAccelerationY()
{
	m_acceleration.setY(m_acceleration.getY() - 0.7);//0.3
}

void Player::Stop(int position_x) {
	m_position.setX(position_x);
	m_lastPosition.setX(position_x);
	m_velocity.setX(0);
	m_acceleration.setX(0);
	m_friction.setX(0);
}
void Player::StopY(int position_y)
{
	m_lastPosition.setY(position_y);
	m_position.setY(position_y);
	m_velocity.setY(0);
	m_acceleration.setY(0);
	m_friction.setY(0);
}