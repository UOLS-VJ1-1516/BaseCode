#pragma once
#include "Loaders.h"
#include <iostream>
#include "EventHandler.h"
#include "AllEntities.hpp"

#define WAIT 1
#define HOVER 2
#define PRESSED 3

class Button : public Entity
{
private:
	EntityParams * params;
	std::string buttonID;
	int state = WAIT;
	LivingEntity * text;
public:
	enum State
	{
		MOUSE_OUT, MOUSE_OVER, CLICKED
	};

	void Load(EntityParams * params, const char * textureFile);

	void SetOnClickListener(void(*callback)());	
	
	void Draw();	
	void DrawFrame();
	void Update();
	void Clear();
protected:
	void(*callback)();
};
