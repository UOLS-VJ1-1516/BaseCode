#pragma once
#include "Layer.h"
#include "GameObject.h"
#include "Level.h"
#include <vector>
class ObjectLayer : public Layer
{
public:
	ObjectLayer();
	virtual ~ObjectLayer();
	virtual void render();
	virtual void update();
	std::vector< GameObject* >* getGameObjects()
	{
		return &m_gameObjects;
	}
private:
	std::vector< GameObject* > m_gameObjects;//tilesets owned by level
};