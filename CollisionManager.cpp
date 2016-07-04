#include "CollisionManager.h"
#include "Camera.h"
bool Y = false;
bool Z = false;
Vector2D auxpos;

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::s_CollisionManager = 0;
bool CajaArribaIzquierda(GameObject* GO,Vector2D caja) {
	if ((GO->getPosition().getX() - Camera::Instance()->getPosition().getX() > caja.getX()) && (GO->getPosition().getY() < caja.getY())) {
		//printf("\nCajaArribaIzquierda SI");
		return true;
	}
	//printf("\nCajaArribaIzquierda NO");
	return false;
}
bool CajaAbajoIzquierda(GameObject* GO, Vector2D caja) {
	if ((GO->getPosition().getX() - Camera::Instance()->getPosition().getX() > caja.getX()) && (GO->getPosition().getY() > caja.getY())) {
		//printf("\nCajaAbajoIzquierda SI");
		return true;
	}
	//printf("\nCajaAbajoIzquierda NO");
	return false;
}
bool CajaArribaDerecha(GameObject* GO, Vector2D caja) {
	if ((GO->getPosition().getX() - Camera::Instance()->getPosition().getX() < caja.getX()) && (GO->getPosition().getY() < caja.getY())) {
		//printf("\nCajaArribaDerecha SI");
		return true;
	}
	//printf("\nCajaArribaDerecha NO");
	return false;
}
bool CajaAbajoDerecha(GameObject* GO, Vector2D caja) {
	if ((GO->getPosition().getX() - Camera::Instance()->getPosition().getX() < caja.getX()) && (GO->getPosition().getY() > caja.getY())) {
		//printf("\nCajaAbajoDerecha SI");
		return true;
	}
	//printf("\nCajaAbajoDerecha NO");
	return false;
}

void CollisionManager::checkCollision(std::vector<GameObject *> mGameObjects)
{
	//Ahora sabemos que mGameObjects[0] es el player
	//printf("TAMAÑO %d", collisionObject->size());
	Y = false;
	Z = false;
	auxpos = mGameObjects[0]->getPosition();

	//----0->Arriba Izquieda   1->Abajo Izquierda  2-> Arriba Derecha  3-> Abajo Derecha
	MiCaja[0].setX(auxpos.getX()-50);
	MiCaja[0].setY(auxpos.getY()+50);
	MiCaja[1].setX(auxpos.getX() - 50);
	MiCaja[1].setY(auxpos.getY() - 50);
	MiCaja[2].setX(auxpos.getX() + 50);
	MiCaja[2].setY(auxpos.getY() + 50);
	MiCaja[3].setX(auxpos.getX() + 50);
	MiCaja[3].setY(auxpos.getY() - 50);
	
	for (int i = 1; i < mGameObjects.size(); i++) //Bucle para los gameObjects
	{
		/*CajaArribaIzquierda(mGameObjects[i], MiCaja[0]);
		CajaAbajoIzquierda(mGameObjects[i], MiCaja[1]);
		CajaArribaDerecha(mGameObjects[i], MiCaja[2]);
		CajaAbajoDerecha(mGameObjects[i], MiCaja[3]);
		printf("\n-------------------");*/
		
		if((CajaArribaIzquierda(mGameObjects[i], MiCaja[0]))&& (CajaAbajoIzquierda(mGameObjects[i], MiCaja[1])) && (CajaArribaDerecha(mGameObjects[i], MiCaja[2])) && (CajaAbajoDerecha(mGameObjects[i], MiCaja[3])))
		{
			mGameObjects[i]->getTextureID();
			
				
			std::string x = mGameObjects[i]->getTextureID();

			cout << mGameObjects[i]->getTextureID()  << endl;
			cout << x<< endl;
			//printf("%s\n",mGameObjects[i]->m_texid);
			
				
			
			if (x == "meta") {
				printf("eooo");
				Z = true;

			}
			else {
				Y = true;
			}
		}
	}
		

}

bool CollisionManager::YColision()
{
	
	
	if (Y) {
		if (Y)
		return true;
		
	}
	else {
		return false;
	}
	

}

bool CollisionManager::YColisionMeta()
{


	if (Z) {
		if (Z)
			return true;

	}
	else {
		return false;
	}

}
