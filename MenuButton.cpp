#include "MenuButton.h"
#include "Game.h"



MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) :m_callback(callback) {
	MenuButton::Params = pParams;

	m_bR = false;
	m_currentFrame = MOUSE_OUT;

	TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender());
	m_textureID = pParams->getTextureID();
}

MenuButton::~MenuButton() {};
void MenuButton::load(const LoaderParams* pParam) {};


void MenuButton::draw()
{
		TextureManager::Instance()->drawFrame(m_textureID, Params->getX(), Params->getY(), Params->getWidth(), Params->getHeight(), 1, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
		
}

void MenuButton::update()
{
	Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (Params->getX() + Params->getWidth())
		&& pMousePos->getX() > Params->getX()
		&& pMousePos->getY() < (Params->getY() + Params->getHeight())	
		&& pMousePos->getY() > Params->getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (InputHandler::Instance()->getMouseButtonState(0) && m_bR)
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_bR = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(0)) {
			m_bR = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
		m_bR = false;
	}
}

void MenuButton::clean()
{
	InputHandler::Instance()->clean();
}