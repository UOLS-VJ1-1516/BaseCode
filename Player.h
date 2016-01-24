#pragma once
#include "CollisionObject.h"

//Classe para crear un game object Player
class Player : public CollisionObject
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
	void jump();
	static GameObject * Create() { return new Player(); }
};