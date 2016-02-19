#include "Camera.h"

Camera *Camera::s_pInstance = 0;

void Camera::setMaxPosition(int maxPostion)
{
	m_maxPosition = maxPostion;
}
int Camera::getMaxPosition()
{
	return m_maxPosition;
}
const Vector2D Camera::getPosition() const
{
	if (m_pTarget != 0)
	{
		Vector2D pos(m_pTarget->m_position.getX() - (Game::Instance()->getVisibleWidth()/2), 0);
		if (pos.getX()< 0)
		{
			pos.setX(0);
		}
		else if (pos.getX() > m_maxPosition - (Game::Instance()->getVisibleWidth() / 2))
		{
			pos.setX(m_maxPosition - (Game::Instance()->getVisibleWidth() / 2)-1);
		}
		return pos;
		
	}
	return m_position;
}
