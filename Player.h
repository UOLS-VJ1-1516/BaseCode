#pragma once
#include "GameObject.h"

//Classe para crear un game object Player
class Player : public GameObject
{
public:
	Player();
	~Player();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	void moveLeft();
	void moveRight();
	void noMoveX();
	void controlPosition();
	static GameObject * Create() { return new Player(); }
};