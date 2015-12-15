//#pragma once
#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::s_pInstance = 0;

GameObjectFactory::GameObjectFactory() {}

GameObjectFactory::~GameObjectFactory(void) {}

void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn pCreate) {
	m_FactoryMap[gameObjectName] = pCreate;
}

GameObject* GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {
	GameObject* go = m_FactoryMap[gameObjectName]();
	return go;
}