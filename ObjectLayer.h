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
	std::vector<GameObject*>* getGameObjects()
	{
		return &m_gameObjects;
	}
private:
	std::vector<GameObject*> m_gameObjects;
};
#endif