#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include "Game.h"



using namespace std;

class Camera
{
public:
	static Camera* Instance()
	{
		if (s_pInstance == 0)
			s_pInstance = new Camera();
		return s_pInstance;
	}
	~Camera();
	void setTarget(GameObject* target);
	void setPosition(Vector2D position);
	void setMaxPosition(int maxPostion);
	int getMaxPosition() { return m_maxPosition; }
	Vector2D getPosition();
private:
	static Camera*s_pInstance;
	Camera();
	GameObject* m_pTarget;
	Vector2D m_position;
	int m_maxPosition;
};
