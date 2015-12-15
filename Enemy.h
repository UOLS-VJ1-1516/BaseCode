#pragma once
#include "GameObject.h"



class Enemy : public GameObject
{
public:



	Enemy();
	~Enemy();




	void load(const Params* pParams);

	//llamamos a las funciones


	void draw();
	void update();
	void clean();



	static GameObject * Create() { return new Enemy(); }




};