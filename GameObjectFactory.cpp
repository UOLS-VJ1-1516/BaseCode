#include "GameObjectFactory.h"

void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn pCreate) {
}

GameObject * GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {
	GameObject * go = factoryMap[gameObjectName]();
	return go;
}
