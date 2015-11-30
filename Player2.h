#pragma once
#include "GameObject.h"

class Player2 : public GameObject
{
public:
	Player2();
	~Player2();
	void draw();
	void load(const LoaderParams* pParams);
	int getCallbackID() const { return m_callbackID; }
	void setCallback(void(*callback)()) { m_callback = callback; }
	static GameObject* Player2::Create() { return new Player2(); }
	void update();
	void clean();
private :
	bool stateFlip;
	int m_callbackID;
	void(*m_callback)();
};
#pragma once
