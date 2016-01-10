#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"
#include "StateParser.h"
#include "LevelParser.h"

void PlayState::update() {


	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->update();
	}*/
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {

		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}
	pLevel->update();

}
void PlayState::render() {
	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->draw();
	}*/
	pLevel->render();
}
bool PlayState::onEnter() {

	StateParser stateParser;
	stateParser.parseState("./Data/Tiny.xml", s_playID, &m_gObjects, &m_TextureIDList);

	LevelParser levelParser;
	pLevel = levelParser.parseLevel("./Data/mapaObjetos.tmx");
	//layerParser.parseTileLayer("./Data/mapa1.tmx");
	

	m_callbacks.push_back(0);
	setCallbacks();

	/*player = new Player();
	zep = new Zep();
	gordo = new Gordo();

	TextureManager::Instance()->load("Kirby.bmp", "player", Game::Instance()->getRender());
	TextureManager::Instance()->load("ZepS.bmp", "zep", Game::Instance()->getRender());
	TextureManager::Instance()->load("GordoS.bmp", "gordo", Game::Instance()->getRender());

	load = new LoaderParams(100, 100, 35, 32,10, "player",0);
	load2 = new LoaderParams(200, 200, 89, 78,4, "zep",0);
	load3 = new LoaderParams(400, 300, 50, 70,4, "gordo", 0);

	player->load(load);
	m_gObjects.push_back(player);

	zep->load(load2);
	m_gObjects.push_back(zep);

	gordo->load(load3);
	m_gObjects.push_back(gordo);*/

	

	return true;
}

const std::string PlayState::s_playID = "PLAY";
bool PlayState::onExit() {
	for (unsigned int i = 0; i < m_gObjects.size(); i++)
	{
		m_gObjects[i]->clean();
	}
	m_gObjects.clear();
	for (unsigned int i = 0; i < m_TextureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_TextureIDList[i]);
	}
	m_TextureIDList.clear();

	std::cout << "Salida del PlayState\n";
	return true;
}

void PlayState::setCallbacks()
{
	for (int i = 0; i < m_gObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gObjects[i]);
			pButton->setCallbacks(m_callbacksID[pButton->getCallbackID()]);
		}
	}

}
