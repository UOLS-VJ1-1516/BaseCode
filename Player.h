#pragma once
#include "GameObject.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameObject
{
public:
	Player();
	~Player();
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
	void horizontal();
	void aceleracion();
	void friccion();
	bool calcula_aceleracion();
	bool calcula_friccion();
	void inicio();
	void handleInput();


private:
	bool cambio;
	bool m_calc_aceleracion;
	bool m_calc_friccion;
	bool ev_right_down;
	bool ev_left_down;
	bool ev_right_up;
	bool ev_left_up;
};
#endif PLAYER_H
