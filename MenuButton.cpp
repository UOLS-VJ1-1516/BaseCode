#include "MenuButton.h"
#include "InputHandler.h"
#include "GameObject.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : m_callback(callback)
{
	m_currentFrame = MOUSE_OUT;
	GameObject::load(pParams);
	m_bReleased = false;
}

void MenuButton::draw()
{
	GameObject::draw();
}

void MenuButton::update()
{
	Vector2D* mousePos = InputHandler::Instance()->GetMousePosition();
	if (mousePos->getX() < (m_position.getX() + m_width)
		&& mousePos->getX() > m_position.getX()
		&& mousePos->getY() < (m_position.getY() + m_height)
		&& mousePos->getY() > m_position.getY())
	{
		if (InputHandler::Instance()->getMouseButtonState(0) && m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0))
		{
			m_currentFrame = MOUSE_OVER;
			m_bReleased = true;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	InputHandler::Instance()->clean();
}

void MenuButton::load(const LoaderParams * pParams)
{
	GameObject::load(pParams);
	m_currentFrame = MOUSE_OUT;
}
