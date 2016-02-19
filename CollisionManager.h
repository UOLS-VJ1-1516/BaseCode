#pragma once

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "GameObject.h"
#include <vector>
#include "ObjectLayer.h"
#include "SDL.h"

class CollisionManager {
	public:
		~CollisionManager() {};
		CollisionManager() {};
		void checkCollision(GameObject* pPlayer, const std::vector<ObjectLayer*>* objectLayers);
		static const int s_buffer = 15;

		static bool RectRect(SDL_Rect A, SDL_Rect B);
};

#endif