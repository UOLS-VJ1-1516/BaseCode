#pragma once
#include "Layer.h"
#include <vector>
#include "GameObject.h"


class ObjectLayer : public Layer
{
public:
	ObjectLayer();
	virtual void render();
	virtual void update();
	std::vector< GameObject* >* getGameObjects()
	{
		return &m_gameObjects;
	}
private:
	std::vector< GameObject* > m_gameObjects;
};
