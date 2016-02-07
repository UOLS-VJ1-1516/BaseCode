#pragma once
#include "GameObject.h"
#include "CollisionObject.h"

class Enemy : public CollisionObject
{
public:
	Enemy();
	~Enemy();
	void draw();
	void load(const LoaderParams* pParams);
	int getCallbackID() const { return m_callbackID; }
	void setCallback(void(*callback)()) { m_callback = callback; }
	static GameObject* Enemy::Create() {return new Enemy();}
	void update();
	void clean();
	void onCollsion(GameObject* other);
private :
	bool stateFlip;
	int m_callbackID;
	void(*m_callback)();
};
#pragma once
