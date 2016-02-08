#include "PlayState.h"
#include "PauseState.h"
#include "StateParser.h"
#include "Game.h"
#include "LevelParser.h"
const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	
	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gObjects.size(); i++) {
		
		m_gObjects[i]->update();
		
	}
	//------Compruebo teclas y escapeeeeeeeee
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {

		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	m_level->update();

};
void PlayState::render() {
	/*printf("TAMAÑO: %d", m_gObjects.size());
	for ( int i = 0; i < m_gObjects.size(); i++) {
		m_gObjects[i]->draw(Game::Instance()->GetRenderer());
	}*/
	m_level->render();
};
bool PlayState::onEnter() {

	printf("Entro en PlayState");
	// parse the state
	//StateParser stateParser;
	//stateParser.parseState("./images/miXML.xml", s_playID, &m_gObjects, &m_textureIDList);
	//m_callbacks.push_back(0);
	//setCallbacks(m_callbacks);
	

	LevelParser levelParser;
	m_level = levelParser.parseLevel("./images/mapa.tmx");
	
	return true;
	
};


bool PlayState::onExit() {
	InputHandler::Instance()->clean();
	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->
			clearFromTextureMap(m_textureIDList[i]);
	}

	m_textureIDList.clear();

	m_gObjects.clear();
	return true;
};

std::string PlayState::getStateID() const {
	return PlayState::s_playID;
};


void PlayState::setCallbacks(const std::vector<Callback>&callbacks)
{
	int x = 0;
	int i = 0;
	// go through the game objects
	for (i = 0; i < m_gObjects.size(); i++)
	{

		// if they are of type MenuButton then assign a callback
		//based on the id passed in from the file

		if (dynamic_cast<MenuButton*>(m_gObjects[i])) {


			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gObjects[i]);
			x = pButton->getCallbackID();
			pButton->setCallback(callbacks[x]);
		}

	}
}
