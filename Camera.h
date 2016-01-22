#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "GameObject.h"
#include "Game.h"

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

	void update(Vector2D velocity);

	void setTarget(GameObject* target) {
		m_pTarget = target; 
	}

	void setPosition(const Vector2D& position) {
		m_position = position;
	}

	Vector2D getPosition() const;
private:
	Camera();
	~Camera();
	GameObject* m_pTarget;
	Vector2D m_position;
	static Camera* s_pCamera;
};
typedef Camera TheCamera;
#endif