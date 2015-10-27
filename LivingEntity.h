#pragma once
#include "Entity.h"

class LivingEntity :
	public Entity
{
public:
	LivingEntity();
	~LivingEntity();

	void Move(int);

	void Load(EntityParams *, const char *);
	void Draw();
	void DrawFrame();
	virtual void Update();
	void Clear();

	const char * GetId() { return params->GetId(); }
	int GetXPos() { return params->GetXPos(); }
	int GetYPos() { return params->GetYPos(); }
	int GetWidth() { return params->GetWidth(); }
	int GetHeight() { return params->GetHeight(); }

	void SetPosY(int value) { params->SetYPos(value); }
	bool HaveAnimation() { return params->GetMaxFrame() > 1; }
	int GetFrame() { return params->GetFrame(); }
	int GetRow() { return params->GetRow(); }
};

