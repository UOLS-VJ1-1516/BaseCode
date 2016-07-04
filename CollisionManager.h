#pragma once
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "CollisionObject.h"

class CollisionManager {

public:
	CollisionManager();
	~CollisionManager();
	static CollisionManager* Instance()
	{
		if (s_CollisionManager == 0)
		{
			s_CollisionManager = new CollisionManager();
		}
		return s_CollisionManager;
	}
	void checkCollision(std::vector<GameObject *> collisionObject);

	static bool YColision();
	static bool YColisionMeta();
	static void setGameObjects(std::vector<GameObject*>*);
	void setTarget(GameObject* target) {
		m_pTarget = target;
	}


private:
	GameObject* m_pTarget;
	Vector2D MiCaja[3];
	static CollisionManager* s_CollisionManager;
};
#endif COLLISIONMANAGER_H