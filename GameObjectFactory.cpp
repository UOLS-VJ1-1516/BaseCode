#include "GameObjectFactory.h"
#include "TextureManager.h"


GameObjectFactory * GameObjectFactory::s_pInstance = 0;
GameObjectFactory::~GameObjectFactory(void)
{
}

GameObjectFactory::GameObjectFactory(void)
{
}

void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn pCreate) {
	m_FactoryMap[gameObjectName] = pCreate;
}

GameObject* GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {
	if (m_FactoryMap.find(gameObjectName) != m_FactoryMap.end()) {
		return m_FactoryMap[gameObjectName]();
	}

	return NULL;
}