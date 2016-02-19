#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "Camera.h"
#include "GameOverState.h"
#include "SoundManager.h"
#include "WinState.h"


Player::Player() {
	m_jump = true;
}
Player::~Player() {

}

void Player::load(const LoaderParams* pParams) {
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_textureID = pParams->getTextureID();
	m_numSprite = pParams->getNumSprite();
	m_velocity.setX(pParams->getSpeedX());
	m_velocity.setY(pParams->getSpeedY());
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_orientation = SDL_FLIP_NONE;
	m_maxVelocity = pParams->getMaxSpeed();
	m_frictionCo = pParams->getFrictionCo();
	m_friction = m_velocity*m_frictionCo;
	m_lastStop.setX(0);
	m_lastStop.setY(0);
}

void Player::draw() {
	//Si la velocidad es negativa, el sprite mira hacia la izquierda
	if (m_velocity.getX() < 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
		m_orientation = SDL_FLIP_HORIZONTAL;
	}
	//Si la velocidad es positiva, el sprite mira hacia la derecha
	else if (m_velocity.getX() > 0) {
		//refresh img
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_NONE);
		m_orientation = SDL_FLIP_NONE;
	}
	else {
		//refresh img
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX()  , (int)m_position.getY(), m_width, m_height, 3, m_currentRow, Game::Instance()->getRender(), m_orientation);
	}
	
}

void Player::update() {
	m_pBoundingBox.x = m_position.getX() + m_collisionMargin;
	m_pBoundingBox.y = m_position.getY();
	m_pBoundingBox.h = m_height;
	m_pBoundingBox.w = m_width - 2 * m_collisionMargin;

	CollisionObject::update();
	if (isCollisionWithTile()) {
		stopY((int)m_position.getY());
		m_jump = false;
		m_collision = true;
	}
	m_jump = false;
	int pixels = 3;
	Vector2D initVelocity = m_velocity;
	SDL_Event event;
	SDL_PollEvent(&event);

	if (m_position.getX() < 0) {
		stopX(0);
	}

	if (m_position.getY() < 0) {
		stopY(0);
	}
	
	if (m_position.getX() > (TheCamera::Instance()->getMaxPosition() - m_width)) {
		Game::Instance()->getGameStateMachine()->pushState(new WinState());
	}
	if (m_position.getY() > ((Game::Instance()->getWindowHeight()) - m_height)) {
		Game::Instance()->getGameStateMachine()->pushState(new GameOverState());
	}

	m_velocity += m_acceleration;

	if (m_velocity.getX()*initVelocity.getX() < 0 || m_velocity.getX() == 0) {
		stopX(m_position.getX());
	}

	if (m_velocity.getY()*initVelocity.getY() < 0 || m_velocity.getY() == 0) {
		stopY(m_position.getY());
	}

	if (m_velocity.length() > m_maxVelocity) {
		m_velocity = m_velocity.normalize()*m_maxVelocity;
		m_acceleration.setX(0);
	}

	m_position += m_velocity; 
	m_currentFrame = (abs((int)(m_position - m_lastStop).length()) / pixels) % m_numSprite;

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(7);
	}
	else {
		m_velocity.setX(0);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-7);
	}
	
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		if (!m_jump && m_collision) {
			jump();
			m_jump = true;
		}
	}
	gravedad();
}

void Player::clean() {
	InputHandler::Instance()->clean();
}

void Player::gravedad() {
	//m_acceleration.setX(0);
	//m_acceleration.setY(m_acceleration.getY()+0.2);
	m_velocity.setY(m_velocity.getY()+1);
}

void Player::stopX(int xpos) {
	m_lastStop.setX(xpos);
	m_position.setX(xpos);
	m_velocity.setX(0);
	m_acceleration.setX(0);
	m_friction.setX(0);
}

void Player::stopY(int ypos) {
	m_lastStop.setY(ypos);
	m_position.setY(ypos);
	m_velocity.setY(0);
	m_acceleration.setY(0);
	m_friction.setY(0);
}

void Player::jump() {
	m_velocity.setY(-15);
	m_collision = false;
	SoundManager::Instance()->playSound("jump", 0);
}

void Player::onCollision(GameObject * other) {
	if (std::strcmp(other->getId(), "plant") == 0)
	{
		Game::Instance()->getGameStateMachine()->pushState(new GameOverState());
	}
	else {
		Game::Instance()->getGameStateMachine()->pushState(new MenuState());
	}
}