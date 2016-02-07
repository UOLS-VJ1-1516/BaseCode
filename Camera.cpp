#include "Camera.h"
#include <stdlib.h>

void Camera::setMaxPosition(int maxPosition)
{
	m_maxPosition = maxPosition;
}

Vector2D Camera::getPosition()
{
	/*
	Vector2D ret = Vector2D(m_pTarget->getPosition().getX() + (m_pTarget->getWidth() / 2) - ((Game::Instance()->getScreenWidth()) / 2), 0);
	if (ret.getX() < 0) ret.setX(0);
	if (ret.getX() > 464) ret.setX(464);
	return ret;
	*/
	if (m_pTarget != 0)
	{
		Vector2D pos(m_pTarget->getPosition().getX() - (Game::Instance()->getScreenWidth() / 2)- m_pTarget->getVelocity().getX(), 0);
		if (pos.getX() < 0)
		{
			pos.setX(0);
		}
		else if (pos.getX() >= m_maxPosition - Game::Instance()->getScreenWidth()) {

			pos.setX(m_maxPosition - Game::Instance()->getScreenWidth());
		}
		//m_pTarget->setCameraMove(pos.getX());
		//printf("x: %f - %f | y: %f - %f\n", pos.getX(), m_pTarget->getPosition().getX(), pos.getY(), m_pTarget->getPosition().getY());
		return pos;
	}
	return m_position;
}

Camera::~Camera()
{
}

Camera* Camera::s_pCamera = 0;

Camera::Camera() {
	m_position.setX(0);
	m_position.setY(0);
};