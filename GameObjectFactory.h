#pragma once
#include <string>
#include "GameObject.h"
#include "BaseCreator.h"

#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

typedef GameObject* (*CreateGameObjectFn)();
class GameObjectFactory
{
public:
	virtual ~GameObjectFactory(void);
	static GameObjectFactory* Instance()
	{
		if (s_pInstanceFact == 0)
		{
			s_pInstanceFact = new GameObjectFactory();
		}
		return s_pInstanceFact;
	}
	void Register(const std::string & gameObjectName, CreateGameObjectFn pCreate);
	GameObject* CreateGameObject(const std::string & gameObjectName);
private:
	GameObjectFactory(void);
	static GameObjectFactory* s_pInstanceFact;
	std::map< std::string, CreateGameObjectFn > m_FactoryMap;
};
#endif GAMEOBJECTFACTORY_H