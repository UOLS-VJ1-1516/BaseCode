#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams * pParams, void(*callback()) : m_callback(callback)) {
	MenuButton::Params = pParams;

	m_buttonR = false;
	if (TextureManager::Instance()->load(pParams->getTextureID()), pParams->getTextureID(), Game::Instance()->getRender()) {
		TextureManager::Instance()
	}
}
