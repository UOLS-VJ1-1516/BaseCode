#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"


Player::Player() {};
Player::~Player() {};
bool quit;

void Player::load(float x, float y, int width, int height,
	std::string texid)
{
	m_position.setX(x);
	m_position.setY(y);
	m_width = width;
	m_height = height;
	m_texid = texid;
	m_currentFrame = 1;
	m_currentRow = 1;
	m_sprits = 1;
	
}

void Player::load(const LoadPar* lPar)
{
	m_width = lPar->getwidth();
	m_height = lPar->getheight();
	m_position.setX(lPar->getx());
	m_position.setY(lPar->gety());
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_sprits = lPar->getsprits();
	m_flip = lPar->getflip();

	m_velocity.setX(0);  //Velocidad horizontal inicial
	m_velocity.setY(0);
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_maxvelocity.setX(10);
	m_maxvelocity.setY(10);
	m_maxvelocityneg.setX(-10);
	m_maxvelocityneg.setY(-10);
    m_anchopantalla=lPar->getanchopantalla();
    m_altopantalla=lPar->getaltopantalla();
	m_friction.setX(0.5);

};
void Player::draw()
{

	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}


void Player::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Renderer, m_flip);
	
}
bool exit() { return quit; }

void Player::update() {
	quit = false;
	SDL_Scancode key = InputHandler::Instance()->update();
	if (key == SDL_SCANCODE_ESCAPE) {
		
		quit = true;
	}
	if (key == SDL_SCANCODE_RIGHT) {
		m_velocity.setX(15);
		m_acceleration.setY(0);
		m_acceleration.setX(m_acceleration.getX()+0.5);
		m_velocity += m_acceleration;
		m_position += m_velocity;
		
		m_flip = 1;
		
	}
	
	if (key == SDL_SCANCODE_LEFT) {
		m_velocity.setX(-15);
		m_acceleration.setY(0);
		m_acceleration.setX(m_acceleration.getX()-0.5);
		m_velocity += m_acceleration;
		m_position += m_velocity;

		m_flip = 2;

	}
	if (key == SDL_SCANCODE_UP) {
		m_velocity.setY(-15);
		m_acceleration.setX(0);
		m_acceleration.setY(m_acceleration.getY()-0.5);
		m_velocity += m_acceleration;
		m_position += m_velocity;


	}
	if (key == SDL_SCANCODE_DOWN) {
		m_velocity.setY(15);
		m_acceleration.setX(0);
		m_acceleration.setY(m_acceleration.getY()+0.5);
		m_velocity += m_acceleration;
		m_position += m_velocity;
		

	}	m_velocity.setX(0);
	m_velocity.setY(0);	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
	
	//---Controlo que no se vaya la aceleracion a infinito
	if (m_acceleration.getX() >= m_maxvelocity.getX()) m_acceleration.setX(m_maxvelocity.getX());
	if (m_acceleration.getX() <= m_maxvelocityneg.getX()) m_acceleration.setX(m_maxvelocityneg.getX());
	if (m_acceleration.getY() >= m_maxvelocity.getY()) m_acceleration.setY(m_maxvelocity.getY());
	if (m_acceleration.getY() <= m_maxvelocityneg.getY()) m_acceleration.setY(m_maxvelocityneg.getY());

	
	
	//------------------LIMITANDO PANTALLA para que salga por el otro lado
	if (m_position.getX() > m_anchopantalla+80) { m_position.setX(0-120);}
	if (m_position.getX() < 0-150) { m_position.setX(m_anchopantalla +15); }
	if (m_position.getY() > m_altopantalla+80) { m_position.setY(0- 15); }
	if (m_position.getY() < 0-150) { m_position.setY(m_altopantalla+ 15); }
	
}
void Player::clean() {}