#pragma once
#include "GameObject.h"

class Enemy : public GameObject
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
private :
	bool stateFlip;
	int m_callbackID;
	void(*m_callback)();
};
#pragma once
