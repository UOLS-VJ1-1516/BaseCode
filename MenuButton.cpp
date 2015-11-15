#include "MenuButton.h"

SDL_RendererFlip flipButton = SDL_FLIP_NONE;

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : m_callback(callback)
{
	GameObject::load(pParams);
	m_bReleased = false;
	m_currentFrame = MOUSE_OUT; // start at frame 0
}

void MenuButton::load(const LoaderParams* pParams)
{
}

void MenuButton::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flipButton);
}

void MenuButton::update()
{
	Vector2D pMousePos = InputHandler::Instance()->getMousePosition();
	if (pMousePos.getX() < (m_position.getX() + m_width)
		&& pMousePos.getX() > m_position.getX()
		&& pMousePos.getY() < (m_position.getY() + m_height)
		&& pMousePos.getY() > m_position.getY())
	{
		if (InputHandler::Instance()->getMouseButtonState(LEFT)	&& m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
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