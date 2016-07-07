#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : m_callback(callback) {
	
	MenuButton::Params = pParams;

	m_bReleased = false;
	if (TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender())) {
	}
};

void MenuButton::load(const LoaderParams* pParam) {};

void MenuButton::draw()
{
	TextureManager::Instance()->drawFrame(Params->getTextureID(), (int)Params->getX(), (int)Params->getY(), Params->getWidth(), Params->getHeight(), 0, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void MenuButton::update()
{
	Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (InputHandler::Instance()->getMouseButtonState(0) && m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0)) {
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
	InputHandler::Instance()->clean();
}
