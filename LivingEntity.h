#pragma once
#include "Entity.h"
#include "Vector2D.h"
#define NEGATIVE -1
#define POSITIVE 1
#define NULL 0

class LivingEntity :
	public Entity
{
private:
	Vector2D position, velocity, maxVel, acceleration, friction;
	float CalcSpeed(float acc, float sp);
	float CalcPos(float acc, float vel);
public:
	LivingEntity();
	~LivingEntity();

	void Move(float, float);

	void Accelerate(int, int);

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

