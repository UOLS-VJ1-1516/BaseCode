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
	void checkCollision(std::vector<GameObject *>* collisionObject);
	static void setGameObjects(std::vector<GameObject*>*);
	void setTarget(GameObject* target) {
		m_pTarget = target;
	}

private:
	GameObject* m_pTarget;
	static const int s_buffer = 15;
	static bool RectRect(SDL_Rect A, SDL_Rect B);
	static CollisionManager* s_CollisionManager;
};
#endif COLLISIONMANAGER_H