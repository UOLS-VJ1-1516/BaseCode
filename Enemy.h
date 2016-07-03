#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy : public GameObject
{
	public:
		Enemy();
		~Enemy();

		virtual void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();

		static GameObject* Create() { return new Enemy(); }

	private:

		const char* m_textureID;
};

#endif ENEMY_H