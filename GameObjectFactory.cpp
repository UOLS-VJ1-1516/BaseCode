#include "GameObject.h"


GameObject* GameObjectFactory::createGameObject(ID id)
{
	switch (id)
	{
	case "PLAYER":
		return new Player();
		break;
	case "ENEMY":
		return new Enemy();
		break;
		// lots more object types
	}
};