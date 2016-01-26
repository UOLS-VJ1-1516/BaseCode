#pragma once
#include "GameObject.h"
#include "ObjectLayer.h"
class CollisionManager {

public:
	static CollisionManager* Instance()
	{
		if (s_pInstance == 0)
			s_pInstance = new CollisionManager();
		return s_pInstance;
	}
	void checkCollision(GameObject * pPlayer, const std::vector<ObjectLayer*>*objectLayers);

private:
	static const int s_buffer = 15;
	static CollisionManager*s_pInstance;
	static bool RectRect(SDL_Rect A, SDL_Rect B);

};

