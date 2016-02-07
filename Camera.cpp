#include "Camera.h"

Camera* Camera::s_pCamera = 0;

Camera::~Camera() {

}

void Camera::setMaxPosition(int maxPosition) {
	m_maxPosition = maxPosition;
}

Vector2D Camera::getPosition() const {
	if (m_pTarget != 0) {
		Vector2D pos(m_pTarget->getPosition().getX() - (Game::Instance()->getWindowWidth() / 2), 0);
		if (pos.getX() < 0) {
			pos.setX(0);
		}
		else if (pos.getX() >= m_maxPosition - Game::Instance()->getWindowWidth()) {
			pos.setX(m_maxPosition - Game::Instance()->getWindowWidth());
		}
		return pos;
	}
	return m_position;
}


Camera::Camera() {
	m_position.setX(0);
	m_position.setY(0);
}