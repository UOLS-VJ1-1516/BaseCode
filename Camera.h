#pragma once
#include "Vector2D.h"
#include "game.h"
#include "GameObject.h"
class Camera
{
public:
	static Camera* Instance()
	{
		if (s_pCamera == 0)
		{
			s_pCamera = new Camera();
		}
		return s_pCamera;
	}
	//void update(Vector2D velocity);
	void setTarget(Vector2D* target) { m_pTarget = target; }
	void setPosition(const Vector2D& position) {
		m_position =
			position;
	}
	const Vector2D getPosition();
private:
	Camera();
	~Camera();
	Vector2D* m_pTarget;
	Vector2D m_position;
	static Camera* s_pCamera;
};


