#pragma once
#include "Loaders.h"
#include <iostream>
#include "EventHandler.h"
#include "Entity.h"

#define WAIT 1
#define HOVER 2
#define PRESSED 3

class Button : public Entity
{
private:
	EntityParams * params;
	std::string buttonID;
	int state = WAIT;
	InertEntity * text;
public:
	void Load(EntityParams * params);
	
	void SetOnClickListener(void(*callback)());	
	
	void Draw();	
	void DrawFrame();
	void Update();
	void Clear();

	int CallbackID;
protected:
	void(*callback)();
};
