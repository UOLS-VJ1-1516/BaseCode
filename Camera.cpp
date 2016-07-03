#include "Camera.h"
#include "game.h"

Camera* Camera::s_pCamera = 0;

Camera::Camera()
{
	m_position.setX(0);
	m_position.setY(0);
}


Camera::~Camera()
{
}


Vector2D Camera::getPosition() const
{
		if (m_pTarget != 0)
		{
			Vector2D pos(m_pTarget->getX() - (Game::Instance()->getGameWidth() / 2), 0);
			if (pos.getX()< 0)
			{
				pos.setX(0);
			}
			return pos;
		}
		return m_position;
}

