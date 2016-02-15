#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "string"


int dir = 0;
int dreta = 1;
std::string texture;
int ultimaPos = 0;
bool colisionLeft = false;
bool colsionRight = false;

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::load(const LoaderParams* ppParams) {
	//pParams = new LoaderParams(ppParams->getX(), ppParams->getY(), ppParams->getWidth(), ppParams->getHeight(), ppParams->getTextureID(), ppParams->getnumFrames, ppParams->getcallbackID);
	Player::pParams = ppParams;
	//texture = pParams->getTextureID();
	//TextureManager::Instance()->load("spritesheet.png", pParams->getTextureID(), Game::Instance()->getRender());
	//m_position.setX(0);
	//m_position.setY(180);
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = 0;
	m_currentRow = 1;
	width = pParams->getWidth();
	height = pParams->getHeight();

}
void Player::draw() {
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

	if(dir == 1){
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
	} 
	else {
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
}
void Player::update() {
	m_velocity.setX(1);
	m_acceleration.setX(1);
	m_velocity.setY(0);
	m_acceleration.setY(0);
	ultimaPos = m_position.getX();
	/*
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (colisionLeft != true) {
			if (isCollisionWithTile()) {
				printf("Colision!!!");
				colsionRight = true;
			}
		}
	}
	
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		if (colsionRight != true) {
			if (isCollisionWithTile()) {
				printf("Colision!!!");
				colisionLeft = true;
			}
		}
	}
	*/
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (colisionLeft != true) {
			if (isCollisionWithTile()) {
				printf("Colision!!!");
				colsionRight = true;
			}
		}
		if (colsionRight != true) {
			dir = 0;
			if (m_position.getX() < Game::Instance()->getGameWidth() - 30) {
				m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
				m_velocity.setX(-2);
				m_velocity -= m_acceleration;
				m_position -= m_velocity;
				colisionLeft = false;
			}
		}
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
		if (colsionRight != true) {
			if (isCollisionWithTile()) {
				printf("Colision!!!");
				colisionLeft = true;
			}
		}
		if (colisionLeft != true) {
			if (m_position.getX() > 0) {
				dir = 1;
				m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
				m_velocity.setX(2);
				m_velocity += m_acceleration;
				m_position -= m_velocity;
				colsionRight = false;
			}
		}
	}
}
void Player::clean() {

}

void Player::handleInput()
{
	Vector2D target = InputHandler::Instance()->getMousePosition();
	m_velocity = target - m_position;
	m_velocity /= 50;
}

