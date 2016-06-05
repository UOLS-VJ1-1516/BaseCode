#include "CollisionObject.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Teclas.h"
#include "Camera.h"
#include "game.h"
#include "Player.h"

int marginH = 62;
int marginW = 30;
int marginHLeft = 62;
int marginWLeft = 50;
int marginHDown = 48;
int marginWDown = 0;
int global;
Vector2D auxposplayer;
Vector2D auxposenemys;
Vector2D auxposteclas;
bool colision = false;
GameObject *mPlayer;


CollisionObject::CollisionObject() {

}
CollisionObject::~CollisionObject() {

}
void CollisionObject::load(const LoadPar* pParams) {

}
void CollisionObject::draw()
{

}
void CollisionObject::update(Vector2D pos)
{
	

}

bool CollisionObject::checkCollision(GameObject* enemy)
{
	if (!colision) {
		//------------FALTARIAN Y
		//printf("\nPosition Enemy:%f  Player:%f ", enemyaux->getPosition().getX(), auxpos.getX());
		for (int margen = 0; margen < 60; margen++) {
			if (enemy->getPosition().getX() == auxposplayer.getX() + margen) { //
				
				setCollision(true);
				return true;
			}
			
		}
	
		
		return false;
	}
	return false;
	
}



void CollisionObject::clean()
{

}

bool CollisionObject::isCollisionWithTile()
{
	
	
	
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{
		

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();
		
		 // Si me estoy moviedno a derecha o arriba
		if (getVelocity().getX() > 0 || getVelocity().getY() > 0)
		{
			tileColumn = ((getPosition().getX() + Camera::Instance()->getPosition().getX() +getWidth()-marginW) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight()-marginH)/ pTileLayer->getTileSize());
			tileid = tiles[tileRow + y][tileColumn + x];
		}

		// Si me estoy moviedno a izquierda o abajo
		else if (getVelocity().getX() < 0 || getVelocity().getY() < 0) // if moving backwards or downwards
		{
			tileColumn =( getPosition().getX() + Camera::Instance()->getPosition().getX() + getWidth()- marginW) / pTileLayer ->getTileSize();
			tileRow = (getPosition().getY() + getHeight()- marginH) / pTileLayer ->getTileSize();
			tileid = tiles[tileRow + y +1][tileColumn + x+1];  //Le digo que hay una posicion menos así puedo estar en colision
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionWithRight()
{



	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		printf("Camara X:%f \n", Camera::Instance()->getPosition().getX());
		printf("Player X:%f \n", getPosition().getX());
		// Si me estoy moviedno a derecha o arriba
		if (getVelocity().getX() > 0 )
		{
			tileColumn = ((getPosition().getX()+Camera::Instance()->getPosition().getX() + getWidth() - marginW) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight() - marginH) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y-1][tileColumn + x+1];  //Aqui me aseguro que estaré mirando colisión derecha
		}  

		
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionEnemyWithRight(GameObject *enemy)
{


	mEnemy = enemy;
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();
		

		// Si me estoy moviedno a derecha o arriba
		if (mEnemy->getVelocity().getX() > 0)
		{
			tileColumn = ((mEnemy->getPosition().getX() + getWidth() - marginW) / pTileLayer->getTileSize());
			tileRow = ((mEnemy->getPosition().getY() + getHeight() - marginH) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y - 1][tileColumn + x + 1];  //Aqui me aseguro que estaré mirando colisión derecha
		}


		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}


bool CollisionObject::isCollisionWithLeft()
{
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

	
	  if (getVelocity().getX() < 0 ){ // if moving backwards or downwards
		
			tileColumn = (getPosition().getX() + Camera::Instance()->getPosition().getX() + getWidth() - marginWLeft) / pTileLayer->getTileSize();
			tileRow = (getPosition().getY() + getHeight() - marginHLeft) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x -1];  //Le digo que hay una posicion menos así puedo estar en colision
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionEnemyWithLeft(GameObject* enemy)
{
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{
		mEnemy = enemy;
		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

	
		if (mEnemy->getVelocity().getX() < 0) { // if moving backwards or downwards
		
			tileColumn = (mEnemy->getPosition().getX() + getWidth() - marginWLeft) / pTileLayer->getTileSize();
			tileRow = (mEnemy->getPosition().getY() + getHeight()- marginHLeft) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x - 1];  //Le digo que hay una posicion menos así puedo estar en colision
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
		
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionEnemyWithDown(GameObject* enemy)
{
	mEnemy = enemy;
	auxposenemys = mEnemy->getPosition();
	//printf("\n Enemy  x:%.2f  y:%.2f ", m_position.getX(), mEnemy->m_velocity.getY());
	
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();
		// NO ES NECESARI PASAR L'OBJECTE ENEMY JA QUE HEREDA DE GAMEOBJECT Y JA TENIM LA SEVA VARIABE AL IGUAL QUE PLAYER PER AIXO PODEM CRIDAR LAS SEVES FUNCIONS I ATRIBUTS
	//	printf("\nPosition  x:%.2f  y:%.2f ", m_position.getX(),mEnemy->m_velocity.getY());


		if (mEnemy->getVelocity().getY() <= 0)
		{
			
			tileColumn = (mEnemy->getPosition().getX() + getWidth() - 50) / pTileLayer->getTileSize();
			tileRow = (mEnemy->getPosition().getY() + getHeight() - marginHDown) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x - 1];  //Le digo que hay una posicion menos así puedo estar en colision
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionWithDown(GameObject* pPlayer)
{
	auxposplayer = m_position;
	mPlayer = pPlayer;
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();
		//printf("\nPosition  x:%.2f  y:%.2f ", m_position.getX(), m_velocity.getY());
	
		
		 if (m_velocity.getY() >= 0) 
		{
			//printf("Entro");
			tileColumn = (m_position.getX() + Camera::Instance()->getPosition().getX() + m_width -50) / pTileLayer->getTileSize();
			tileRow = (m_position.getY() + m_height - marginHDown) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x - 1];  //Le digo que hay una posicion menos así puedo estar en colision
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}


bool CollisionObject::isCollisionWithUp()
{

	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		// Si me estoy moviedno a derecha o arriba
		if (getVelocity().getY() < 0)
		{
			tileColumn = ((getPosition().getX()+Camera::Instance()->getPosition().getX() + getWidth() - marginW) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight() - marginH) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y + 1][tileColumn + x - 1];  //Aqui me aseguro que estaré mirando colisión derecha
																  //y+1  x-1 -> Miro izquierda 
																  //y-1 x-1 -> Miro arriba 
																  //y+1 x+1 -> Miro abajo
		}

		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}
