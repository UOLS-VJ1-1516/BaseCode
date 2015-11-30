#include "GameObjectFactory.h"

using namespace std;

GameObjectFactory * GameObjectFactory::s_pInstance = 0;
GameObjectFactory::~GameObjectFactory(void)
{
}
//Reistrem guardem dintre el mapa la fucio de crear 
void GameObjectFactory::Register(const string & gameObjectName, CreateGameObjectFn pCreate) {
	m_FactoryMap[gameObjectName] = pCreate;


}
//Go agafa la clau gameObjectName.
GameObject* GameObjectFactory::CreateGameObject(const std::string & gameObjectName) {

	GameObject * Go = m_FactoryMap[gameObjectName]();

	return Go;

}

