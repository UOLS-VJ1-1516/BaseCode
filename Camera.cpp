#include "Camera.h"

void Camera::setMaxPosition(int maxPosition)
{
	m_maxPosition = maxPosition;
}

Vector2D Camera::getPosition() const
{
	if (m_pTarget != 0)
	{
		Vector2D pos(m_pTarget->getPosition().getX() - (Game::Instance()->getScreenWidth() / 2), 0);
		if (pos.getX() < 0)
		{
			pos.setX(0);
		}
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