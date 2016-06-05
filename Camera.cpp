#include "Camera.h"


Camera* Camera::s_pInstance = 0;

Camera::Camera()
{
	m_position.setX(0);
	m_position.setY(0);
}
Camera::~Camera()
{

}

void Camera::setTarget(GameObject* target)
{
	m_pTarget = target;
}
void Camera::setPosition(Vector2D position)
{
	//printf("La posicion de la camara es: X: %f   Y:%f \n", position.getX(), position.getY());
	m_position.setX(position.getX());
	m_position.setY(position.getY());
}
void Camera::setMaxPosition(int maxPostion)
{
	m_maxPosition = 50000;
}
Vector2D Camera::getPosition()
{
	if (m_pTarget != 0) {
		Vector2D Myposition(m_pTarget->getPosition().getX() - (Game::Instance()->getAncho()/4 ) + (m_position.getX()+100), 0);
		//Vector2D Myposition(m_pTarget->getPosition().getX(), 0);
		if (Myposition.getX() < 0) {
			Myposition.setX(0);
		}
		return Myposition;
	}
	return m_position;
}