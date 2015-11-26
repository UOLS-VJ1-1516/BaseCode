#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"


Player::Player() {};
Player::~Player() {};
bool quit;
int flag;
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
	m_velocity.setY(0);  //Velocidad verical inicial
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_maxacceleration.setX(20);   //Prefiero jugar con la aceleracion maxima antes que con la Velmax, creo que me ayudara en un futuro
	m_maxacceleration.setY(30);   
	m_maxaccelerationneg.setX(-20);
	m_maxaccelerationneg.setY(-30);
    m_anchopantalla=lPar->getanchopantalla();  //Para que sea mas facil de adaptar
    m_altopantalla=lPar->getaltopantalla();
	m_friction.setX(0.5);  //Será mi frenada

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
	//Flag, 1->Right 2->Left 3->Up 4->Down
	if (key == SDL_SCANCODE_RIGHT) {
		m_velocity.setX(0);  //Velocidad inicial
		m_acceleration.setY(0);
		if (flag != 1) m_acceleration.setX(0);
		m_acceleration.setX(m_acceleration.getX() + 0.25);
		//---Controlo que no se vaya la aceleracion a infinito
		if (m_acceleration.getX() >= m_maxacceleration.getX()) m_acceleration.setX(m_maxacceleration.getX());
		m_velocity += m_acceleration;
		m_position += m_velocity;
		flag = 1;
		m_flip = 1;

	}
	else{
		if (key == SDL_SCANCODE_LEFT) {
			m_velocity.setX(0); //Velocidad inicial
			m_acceleration.setY(0);
			if (flag != 2) m_acceleration.setX(0);
			m_acceleration.setX(m_acceleration.getX() - 0.25);
			//---Controlo que no se vaya la aceleracion a infinito
			if (m_acceleration.getX() <= m_maxaccelerationneg.getX()) m_acceleration.setX(m_maxaccelerationneg.getX());
			m_velocity += m_acceleration;
			m_position += m_velocity;
			flag = 2;
			m_flip = 2;

		}
		else {
			if (key == SDL_SCANCODE_UP) {
				m_velocity.setY(0); //Velocidad inicial
				m_acceleration.setX(0);
				if (flag != 3) m_acceleration.setY(0);
				m_acceleration.setY(m_acceleration.getY() - 0.5);
				//---Controlo que no se vaya la aceleracion a infinito
				if (m_acceleration.getY() <= m_maxaccelerationneg.getY()) m_acceleration.setY(m_maxaccelerationneg.getY());
				m_velocity += m_acceleration;
				m_position += m_velocity;
				flag = 3;
			}
			else {
				if (key == SDL_SCANCODE_DOWN) {
					m_velocity.setY(0); //Velocidad inicial
					m_acceleration.setX(0);
					if (flag != 4) m_acceleration.setY(0);
					m_acceleration.setY(m_acceleration.getY() + 0.5);
					//---Controlo que no se vaya la aceleracion a infinito
					if (m_acceleration.getY() >= m_maxacceleration.getY()) m_acceleration.setY(m_maxacceleration.getY());
					m_velocity += m_acceleration;
					m_position += m_velocity;
					flag = 4;
				}				else {

					//-----Implemento friccion si el objeto esta en movimiento y no hay tecla pulsada, solo habrá fricción horizontal
						//----Friccion en caso negativo
					if (m_velocity.getX() < 0) {
						if (m_velocity.getX() != 0) {
							m_velocity += m_friction;
							m_velocity.setY(0);
							m_position += m_velocity;
						}
					}
					else {
						//Friccion caso positivo
						if (m_velocity.getX() > 0) {
							if (m_velocity.getX() != 0) {
								m_velocity -= m_friction;
								m_velocity.setY(0);
								m_position += m_velocity;
							}
						}
						else {
							m_velocity.setX(0);
							m_velocity.setY(0);
							m_acceleration.setX(0);
						}
					}
				}			}		}	}		m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);	
	
	
	//------------------Netejo pantalla--------> para que salga por el otro lado eje vertical, limitando eje horizontal
	if (m_position.getX() > m_anchopantalla-175) { m_position.setX(m_anchopantalla-175);}
	if (m_position.getX() < 0) { m_position.setX(0); }
	if (m_position.getY() > m_altopantalla+80) { m_position.setY(0- 15); }
	if (m_position.getY() < 0-150) { m_position.setY(m_altopantalla+ 15); }
	
}
void Player::clean() {}