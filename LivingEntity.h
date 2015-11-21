#pragma once
#include "Entity.h"
#include "Vector2D.h"

#define NEGATIVE -1
#define POSITIVE 1
#define NULL 0

class LivingEntity :
	public Entity
{
protected:
	Vector2D position, velocity, maxVel, acceleration, friction;	
public:
	LivingEntity();
	~LivingEntity();

	static LivingEntity * Create() { return new LivingEntity(); }
	void Move(float, float);

	void Accelerate(int, int);

	void Load(EntityParams *);
	void Draw();
	void DrawFrame();
	virtual void Update();
	void Clear();

	std::string GetId() { return params->GetId(); }
	float GetXPos() { return position.X; }
	float GetYPos() { return position.Y; }
	int GetWidth() { return params->GetWidth(); }
	int GetHeight() { return params->GetHeight(); }
	
	bool HaveAnimation() { return params->GetMaxFrame() > 1; }
	int GetFrame() { return params->GetFrame(); }
	int GetRow() { return params->GetRow(); }
};

