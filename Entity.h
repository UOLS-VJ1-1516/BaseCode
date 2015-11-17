#pragma once
#include "EntityParams.h"

class Entity
{
public:
	EntityParams * params;
public:
	virtual void Load(EntityParams * params) = 0;
	virtual void Draw() = 0;
	virtual void DrawFrame() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
};

