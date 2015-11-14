#include "LoaderParams.h"
#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams) :
	GameObject(pParams)
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
	
}
void MenuButton::draw()
{
	GameObject::draw(); // use the base class drawing
}
void MenuButton::update()
{
	Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (InputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}
void MenuButton::clean()
{
	GameObject::clean();
}

//pagina 112
//96