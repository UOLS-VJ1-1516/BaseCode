#include "CollisionManager.h"

void CollisionManager::checkCollision(GameObject * pPlayer, const std::vector<ObjectLayer*>* objectLayers)
{
	for (int i = 0; i < objectLayers->size(); i++)
	{
		std::vector<GameObject*>* GOs = objectLayers->at(i)->getGameObjects();
		for (int e = 0; e < GOs->size(); e++)
		{
			if (pPlayer != GOs->at(e))
			{
				if (RectRect(pPlayer->getBoundingBox(), GOs->at(e)->getBoundingBox()))
				{
					pPlayer->onCollision(GOs->at(e));
				}
			}
		}
	}
}
bool CollisionManager::RectRect(SDL_Rect A, SDL_Rect B)
{
	A.x += s_buffer;
	A.y += s_buffer;
	A.h -= s_buffer;
	A.w -= s_buffer;
	B.x += s_buffer;
	B.y += s_buffer;
	B.h -= s_buffer;
	B.w -= s_buffer;
	bool left = 0;
	bool sup = 0;
	if (A.x < B.x) left = 0; else left = 1;
	if (A.y < B.y) sup = 0; else sup = 1;

	if (!left && !sup)
	{
		if (((A.x + A.w) > B.x) && ((A.y + A.h) > B.y))
		{
			return true;
		}
	}
	else if (!left && sup)
	{
		if (((A.x + A.w) > B.x) && (A.y < (B.y + B.h)))
		{
			return true;
		}
	}
	else if (left && sup)
	{
		if ((A.x < (B.x + B.w)) && (A.y < (B.y + B.h)))
		{
			return true;
		}
	}
	else if (left && !sup)
	{
		if ((A.x < (B.x + B.w)) && ((A.y + A.h) > B.y))
		{
			return true;
		}
	}
	return false;
}

