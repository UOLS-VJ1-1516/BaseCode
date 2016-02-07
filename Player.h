#pragma once
#include "CollisionObject.h"
#include "SDL.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public CollisionObject
{
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	int getCallbackID() const { return m_callbackID; }
	void setCallback(void(*callback)()) { m_callback = callback; }

	void update();
	void clean();
	void registerEvents();

	bool calcula_aceleracion();
	bool calcula_friccion();
	void inicio();
	void horizontal();
	void handleInput();
	
	void aceleracion();
	void friccion();


	void impulseRight();
	void impulseLeft();
	void jump();
	void gravity();
	void incrementAccelerationY();
	void decrementAccelerationY();
	void onCollsion(GameObject* other);
	static GameObject * Create() { return new Player(); }
	void collision() {};
	bool nJump = false;
	bool mjumping = false;
	bool haycolision = false;
	void incrementFriction();
	//void incrementAccelerationX();



private:
	bool cambio;
	bool m_calc_aceleracion;
	bool m_calc_friccion;
	bool ev_right_down;
	bool ev_left_down;
	bool ev_right_up;
	bool ev_left_up;
	void(*m_callback)();
	int m_callbackID;

	void stopX(int);
	void stopY(int);
	bool aceleracionY;
	bool frictionY;
	bool mgravity;
	Vector2D m_lastStop;
};
#endif PLAYER_H
