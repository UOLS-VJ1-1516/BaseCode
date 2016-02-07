#pragma once
#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H
#include <vector>
#include "GameObject.h"
#include "Layer.h"

class ObjectLayer : public Layer
{
public:
	virtual void update();
	virtual void render();
	bool ObjectLayer::checkHueco(GameObject* p1);
	bool ObjectLayer::checkEnd(GameObject* p1);
	std::vector<GameObject*>* getGameObjects()
	{
		return &m_gameObjects;
	}
	bool ObjectLayer::checkCollision(GameObject* p1, GameObject* p2);
private:
	std::vector<GameObject*> m_gameObjects;
};
#endif