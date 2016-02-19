#pragma once
#include "Vector2D.h"
#include "GameObject.h"
class Camera
{
public:
	static Camera* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Camera();
		}
		return s_pInstance;
	}
	~Camera() {};
	void setTarget(GameObject* target) { m_pTarget = target; };
	void setPosition(const Vector2D& position) { m_position = position; };
	void setMaxPosition(int maxPostion);
	int getMaxPosition();
	const Vector2D getPosition() const;
private:
	static Camera*s_pInstance;
	Camera() { m_position.setX(0); m_position.setY(0); m_maxPosition = 0; };
	GameObject* m_pTarget; // Objeto
	Vector2D m_position;
	int m_maxPosition;
};