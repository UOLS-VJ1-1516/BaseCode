#include "MenuButton.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "Vector2D.h"

const std::string MenuButton::s_ButtonID= "MENU";
//MenuButton::MenuButton(const LoaderParams* ppParams, void(*callback)())
MenuButton::MenuButton()
{
	/*
	//m_callback = callback;
	m_callbackID = ppParams->getcallbackID();
	m_currentFrame = MOUSE_OUT; // start at frame 0
	pParams = new LoaderParams(ppParams->getX(), ppParams->getY(), ppParams->getWidth(), ppParams->getHeight(), ppParams->getTextureID(), ppParams->getnumFrames, ppParams->getcallbackID, ppParams->getanimSpeed);
	m_currentRow = 1;
	*/
}

MenuButton::~MenuButton()
{
	
}

void MenuButton::load(const LoaderParams* ppParams) {
	m_callbackID = ppParams->getcallbackID();
	m_currentFrame = MOUSE_OUT; // start at frame 0
	//pParams = new LoaderParams(ppParams->getX(), ppParams->getY(), ppParams->getWidth(), ppParams->getHeight(), ppParams->getTextureID(), ppParams->getnumFrames,0,0);
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
	//GameObject::clean();
}