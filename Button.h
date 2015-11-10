#pragma once
#include "Entity.h"
#include <iostream>

class Button : Entity
{
private:
	EntityParams * params;
public:
	enum State
	{
		MOUSE_OUT, MOUSE_OVER, CLICKED
	};

	void Load(EntityParams * params, const char * textureFile);

	void SetOnClickListener(void(*callback)());
	
	void Check();
	void Draw();	
	void DrawFrame();
	void Update();
	void Clear();
protected:
	void(*callback)();
	bool Released;
};
