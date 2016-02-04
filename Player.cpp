#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"


Player::Player() {  };
Player::~Player() {  };
bool quit;
int flag;




void Player::load(const LoadPar * lPar)
{
	
	m_width = lPar->getWidth();
	m_height = lPar->getHeight();
	m_position.setX(lPar->getX());
	m_position.setY(lPar->getY());
	m_texid = lPar->getTextureID();
	m_sprits = lPar->getNumSprites();
	m_anchopantalla = Game::Instance()->getAncho();
	m_altopantalla = Game::Instance()->getAlto();
	m_currentFrame = 1;
	m_currentRow = 1;

	m_flip = 1;


	m_velocity.setX(0);  //Velocidad horizontal inicial
	m_velocity.setY(0);  //Velocidad verical inicial
	m_acceleration.setX(0.1);
	m_acceleration.setY(1);
	m_maxvelocity.setX(10);   //Prefiero jugar con la aceleracion maxima antes que con la Velmax, creo que me ayudara en un futuro
	m_maxvelocity.setY(5);
	//m_maxaccelerationneg.setX(-20);
	//m_maxaccelerationneg.setY(-10);
	m_friction.setX(0.5);  //Será mi frenada
	m_friction.setY(5);

};
void Player::draw()
{

	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}


void Player::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Renderer, m_flip);
	
}
bool exit() { return quit; }
//SDL_SCANCODE_ESCAPE    RIGHT LEFT UP

void Player::update() {
	quit = false;
	
	InputHandler::Instance()->update();
	m_currentRow = 1;
	m_sprits = 1;

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {

		quit = true;
	}

	//Flag, 1->Right 2->Left 3->Up 4->Down
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		
		m_currentRow = 2;
		m_sprits = 6;
		m_flip = 1;
		flag = 1;
		//Compruebo velocidad maxima, si es menor puedo sumar aceleracion sino no.
		if (m_velocity.getX() < m_maxvelocity.getX()) {
			m_velocity.setX(m_velocity.getX() + m_acceleration.getX());
		}
		m_position.setX(m_position.getX() + m_velocity.getX());
		

	}
	else{
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
			m_currentRow = 2;
			m_sprits = 6;
			m_flip = 2;
			flag = 2;
			//Compruebo velocidad maxima, si es menor puedo sumar aceleracion sino no.
			if (m_velocity.getX() < m_maxvelocity.getX()) {
				m_velocity.setX(m_velocity.getX() + m_acceleration.getX());
			}
			m_position.setX(m_position.getX() - m_velocity.getX());


		}
		else {
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
				m_currentRow = 3;
				m_sprits = 6;
				flag = 3;
					switch (flag)
					{
						case (1) :
							m_flip = 1;
							break;
						case(2) :
							m_flip = 2;
							break;
						default:
							break;
					}

					//Compruebo velocidad maxima, si es menor puedo sumar aceleracion sino no.
					if (m_velocity.getY() < m_maxvelocity.getY()) {
						m_velocity.setY(m_velocity.getY() + m_acceleration.getY());
					}
					m_position.setY(m_position.getY()- m_velocity.getY());


			}
			else {
				if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
					m_currentRow = 5;
					m_sprits = 1;
					flag = 4;
				}				else {
					m_currentRow = 1;
					m_sprits = 1;
					//NO HAY TECLAS PULSANDOSE, implemento friccion
					switch (flag)
					{
					case (1) :
						m_flip = 1;
						//Si la velocidad no es 0 le resto la friccion y lo coloco en su posicion
						if (m_velocity.getX() >=0 ) {
							m_velocity.setX(m_velocity.getX() - m_friction.getX());
							m_position.setX(m_position.getX() + m_velocity.getX());
						}
						

						break;
					case(2) :
						m_flip = 2;
						if (m_velocity.getX() >= 0) {
							m_velocity.setX(m_velocity.getX() - m_friction.getX());
							m_position.setX(m_position.getX() - m_velocity.getX());
						}
						
						break;
					case(3) :
						if (m_velocity.getY() >= 0) {
							m_velocity.setY(m_velocity.getY() - m_friction.getY());
							m_position.setY(m_position.getY() - m_velocity.getY());
						}
							
						break;
					default:
						m_velocity.setY(0);
						m_velocity.setY(0);
						break;
					}
					
				}			}		}	}		m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);	
	
	
	//------------------Netejo pantalla--------> para que salga por el otro lado eje vertical, limitando eje horizontal
	if (m_position.getX() > m_anchopantalla-175) { m_position.setX(m_anchopantalla-175);}
	if (m_position.getX() < 0) { m_position.setX(0); }
	if (m_position.getY() > m_altopantalla+80) { m_position.setY(0- 15); }
	if (m_position.getY() < 0-150) { m_position.setY(m_altopantalla+ 15); }
	
}
void Player::clean() {}