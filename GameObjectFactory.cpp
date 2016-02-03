#include "GameObjectFactory.h"
#include "MenuButton.h"
#include "Player.h"
#include "Gordo.h"
#include "Zep.h"

GameObjectFactory* GameObjectFactory::s_pInstance = 0;

GameObjectFactory::GameObjectFactory(void) {

	
}

GameObjectFactory::~GameObjectFactory(void) {

}

void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn pCreate) {
	m_FactoryMap[gameObjectName] = pCreate;
}
GameObject* GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {
	return m_FactoryMap[gameObjectName]();
}