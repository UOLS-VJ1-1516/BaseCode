#include "CollisionManager.h"
bool Y = false;
Vector2D auxpos;

CollisionManager::CollisionManager()
{
	
}

CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::s_CollisionManager = 0;
bool CajaArribaIzquierda(GameObject* GO,Vector2D caja) {
	if ((GO->getPosition().getX() > caja.getX()) && (GO->getPosition().getY() < caja.getY())) {
		//printf("\nCajaArribaIzquierda SI");
		return true;
	}
	//printf("\nCajaArribaIzquierda NO");
	return false;
}
bool CajaAbajoIzquierda(GameObject* GO, Vector2D caja) {
	if ((GO->getPosition().getX() > caja.getX()) && (GO->getPosition().getY() > caja.getY())) {
		//printf("\nCajaAbajoIzquierda SI");
		return true;
	}
	//printf("\nCajaAbajoIzquierda NO");
	return false;
}
bool CajaArribaDerecha(GameObject* GO, Vector2D caja) {
	if ((GO->getPosition().getX() < caja.getX()) && (GO->getPosition().getY() < caja.getY())) {
		//printf("\nCajaArribaDerecha SI");
		return true;
	}
	//printf("\nCajaArribaDerecha NO");
	return false;
}
bool CajaAbajoDerecha(GameObject* GO, Vector2D caja) {
	if ((GO->getPosition().getX() < caja.getX()) && (GO->getPosition().getY() > caja.getY())) {
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
			
				
				Y = true;
			
		}
	}
		
		/*
		for (int margen = 0; margen < 50; margen++) { //Es el margen para que no me joda la velocidad, ya que si corro 3 posiciones me salto esa X.
			
			printf("\n  Player: ( %f , %f )", mGameObjects[0]->getPosition().getX() + margen, mGameObjects[0]->getPosition().getY()+margen);
			printf("\n  Enemy:  ( %f , %f )", mGameObjects[3]->getPosition().getX()-3, mGameObjects[3]->getPosition().getY());
			if ((mGameObjects[3]->getPosition().getX()-3 == mGameObjects[0]->getPosition().getX() + margen)&&(mGameObjects[3]->getPosition().getY() == mGameObjects[0]->getPosition().getY()+margen)){
				//if (mGameObjects[i]->getPosition().getY() - margen == mGameObjects[0]->getPosition().getY()) { //
					printf("\n HI\n");
					Y = true;
				//}
			}*/
			//OJO QUE HAS DE HACER LA Yª!!!!
			//Si la colision fuera con el objeto que nos interesa para transportar es mGameObjects[objeto que itneresa];
			
		
		
		//printf("\nLa posicion del object %d, es X: %f e y: %f",i, mGameObjects[i]->getPosition().getX(), mGameObjects[i]->getPosition().getY());
	//}
	//Y = false;

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
	
	//PARA ASEGURAR QUE NO SE TOCAN
	//return A.x < B.x + B.w && A.x + A.w > B.x && A.y < B.y + B.h && A.y + A.h > B.y;
}