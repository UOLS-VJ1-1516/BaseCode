#pragma once
#include "Entity.h"
#include "Loaders.h"

class InertEntity : public Entity
{
public:
	InertEntity();
	~InertEntity();
	static InertEntity * Create() { return new InertEntity(); }
	void Load(EntityParams * params, const char * texture);
	void Draw();
	void DrawFrame();
	void Update();
	void Clear();
};