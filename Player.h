#pragma once
#include "GameObject.h"

class Player : public GameObject{
	public:
		Player();
		~Player();
		void load(const Param* pParams);
		void draw();
		void update();
	    void clean();
		};