#include "GameObjectFactory.h"

	
GameObjectFactory * GameObjectFactory::s_pInstanceFact = 0;
	GameObjectFactory::GameObjectFactory(void)
	{
	}


	GameObjectFactory::~GameObjectFactory(void)
	{
	}

	void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn pCreate) {
		m_FactoryMap[gameObjectName] = pCreate;//guardem a la posicio del tipus d'objecte, la funcio per crear-lo
	}

	GameObject* GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {
		if (m_FactoryMap.find(gameObjectName) != m_FactoryMap.end()) {
			return m_FactoryMap[gameObjectName]();
		}

		return NULL;
	}
