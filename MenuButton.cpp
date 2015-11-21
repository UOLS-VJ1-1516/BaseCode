#include "MenuButton.h"
#include "Game.h"


MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) :m_callback(callback) {
	MenuButton::Params = pParams;

	m_bR = false;
	m_currentFrame = MOUSE_OUT;

	TextureManager::Instance()->load(pParams->getTextureID(), pParams->getTextureID(), Game::Instance()->getRender());
}

MenuButton::~MenuButton() {};
void MenuButton::load(const LoaderParams* pParam) {};


void MenuButton::draw()
{
	TextureManager::Instance()->drawFrame(Params->getTextureID(), Params->getX(), Params->getY(), Params->getWidth(), Params->getHeight(), 1, 2, Game::Instance()->getRender(), SDL_FLIP_NONE);
										//(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRender, SDL_RendererFlip flip)
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
	}
}

void MenuButton::clean()
{
	InputHandler::Instance()->clean();
}