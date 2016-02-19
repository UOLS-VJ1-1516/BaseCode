#pragma once
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "GameObject.h"
#include <vector>
#include "ObjectLayer.h"

class CollisionManager
{
public:
	~CollisionManager() {};
	CollisionManager() {};
	void checkCollision(GameObject* pPlayer, const std::vector<ObjectLayer*>* objectLayers);
};
#endif
