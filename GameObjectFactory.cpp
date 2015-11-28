#include "GameObjectFactory.h"

GameObjectFactory * GameObjectFactory::instance = 0;

void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn create) {
	factoryMap[gameObjectName] = create;
}

GameObject * GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {
	GameObject * go = factoryMap[gameObjectName]();
	return go;
}
