#pragma once
#include <map>
#include "GameObject.h"
#include <iostream>

#define TheGameObjectFactory GameObjectFactory::Instance()

typedef GameObject* (*CreateGameObjectFn)();

class GameObjectFactory {
public:
	virtual ~GameObjectFactory();
	static GameObjectFactory* Instance() {
		if (instance == 0) instance = new GameObjectFactory();
		return instance;
	}
	void Register(const std::string & gameObjectName, CreateGameObjectFn create);
	GameObject* CreateGameObject(const std::string & gameObjectName);
private:
	GameObjectFactory(void);
	static GameObjectFactory* instance;
	std::map< std::string, CreateGameObjectFn > factoryMap;
};