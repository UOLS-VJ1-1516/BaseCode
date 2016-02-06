#include "MenuButton.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "Vector2D.h"

const std::string MenuButton::s_ButtonID= "MENU";

MenuButton::MenuButton()
{

}

MenuButton::~MenuButton()
{
	
}

void MenuButton::load(const LoaderParams* ppParams) {
	m_callbackID = ppParams->getcallbackID();
	//m_bReleased = false;
	m_currentFrame = MOUSE_OUT; // start at frame 0
	MenuButton::pParams = ppParams;
	m_currentRow = 1;
}


void MenuButton::draw()
{
	TextureManager::Instance()->drawFrame(pParams->getTextureID(), pParams->getX(), pParams->getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void MenuButton::update()
{
	Vector2D pMousePos =InputHandler::Instance()->getMousePosition();
	
	if (pMousePos.getX() < (pParams->getX() + pParams->getWidth()) && pMousePos.getX() > pParams->getX()
		&& pMousePos.getY() < (pParams->getY() + pParams->getHeight())
		&& pMousePos.getY() > pParams->getY())
	{
		if (InputHandler::Instance()->getMouseButtonState(LEFT)
			&& m_bReleased)
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
	InputHandler::Instance()->clean();
}