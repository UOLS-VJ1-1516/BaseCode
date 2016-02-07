#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::s_CollisionManager = 0;

void CollisionManager::checkCollision(std::vector<GameObject *>* collisionObject)
{
	for (int e = 0; e < collisionObject->size(); e++)
	{
		if (m_pTarget != collisionObject->at(e))
		{
			if (RectRect(m_pTarget->getBoundingBox(), collisionObject->at(e)->getBoundingBox()))
			{
				m_pTarget->onCollision(collisionObject->at(e));
			}
		}
	}
}

bool CollisionManager::RectRect(SDL_Rect A, SDL_Rect B)
{
	//PARA ASEGURAR QUE NO SE TOCAN
	return A.x < B.x + B.w && A.x + A.w > B.x && A.y < B.y + B.h && A.y + A.h > B.y;
}