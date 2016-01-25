#include "GameObjectFactory.h"
#include <iostream>

GameObjectFactory::GameObjectFactory() {};
GameObjectFactory::~GameObjectFactory() {};

//Función para registrar un nuevo game object y guardarlo en un vector
void GameObjectFactory::Register(const std::string & gameObjectName, CreateGameObjectFn pCreate)
{
	m_FactoryMap[gameObjectName] = pCreate;
}

//Función para crear el game object registrado anteriormente
GameObject* GameObjectFactory::CreateGameObject(const std::string & gameObjectName)
{
	std::map< std::string, CreateGameObjectFn >::iterator it = m_FactoryMap.find(gameObjectName);

	if (it == m_FactoryMap.end())
	{
		std::cout << "No se ha encontrado: " << gameObjectName << "\n";
	}

	return  m_FactoryMap[gameObjectName]();
}