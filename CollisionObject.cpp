#include "CollisionObject.h"
#include "GameObject.h"
#include "game.h"

int marginH = 62;
int marginW = 30;
int marginHLeft = 62;
int marginWLeft = 50;
int marginHDown = 48;
int marginWDown = 0;


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
	//position = pos;
	//printf("\nPosition x:%f  y:%f ", position.getX(), position.getY());

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
			tileColumn = ((getPosition().getX() +getWidth()-marginW) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight()-marginH)/ pTileLayer->getTileSize());
			tileid = tiles[tileRow + y][tileColumn + x];
		}

		// Si me estoy moviedno a izquierda o abajo
		else if (getVelocity().getX() < 0 || getVelocity().getY() < 0) // if moving backwards or downwards
		{
			tileColumn =( getPosition().getX() + getWidth()- marginW) / pTileLayer ->getTileSize();
			tileRow = (getPosition().getY() + getHeight()- marginH) / pTileLayer ->getTileSize();
			tileid = tiles[tileRow + y +1][tileColumn + x+1];  //Le digo que hay una posicion menos as� puedo estar en colision
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


		// Si me estoy moviedno a derecha o arriba
		if (getVelocity().getX() > 0 )
		{
			tileColumn = ((getPosition().getX() + getWidth() - marginW) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight() - marginH) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y-1][tileColumn + x+1];  //Aqui me aseguro que estar� mirando colisi�n derecha
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
		
			tileColumn = (getPosition().getX() + getWidth() - marginWLeft) / pTileLayer->getTileSize();
			tileRow = (getPosition().getY() + getHeight() - marginHLeft) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x -1];  //Le digo que hay una posicion menos as� puedo estar en colision
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
	mEnemy->m_position.getX();
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
		printf("\nPosition enemy x:%.2f  y:%.2f ", m_position.getX(), mEnemy->m_position.getY());


		if (mEnemy->m_velocity.getY() <= 0)
		{
			
			tileColumn = (mEnemy->m_position.getX() + getWidth() - 50) / pTileLayer->getTileSize();
			tileRow = (mEnemy->m_position.getY() + getHeight() - 150) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x - 1];  //Le digo que hay una posicion menos as� puedo estar en colision
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionWithDown()
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
		//printf("\nPosition Player x:%.2f  y:%.2f ", getPosition().getX(), getPosition().getY());
	
		
		 if (getVelocity().getY() >= 0) 
		{
			//printf("Entro");
			tileColumn = (getPosition().getX() + getWidth() -50) / pTileLayer->getTileSize();
			tileRow = (getPosition().getY() + getHeight() - marginHDown) / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y - 1][tileColumn + x - 1];  //Le digo que hay una posicion menos as� puedo estar en colision
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
			tileColumn = ((getPosition().getX() + getWidth() - marginW) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight() - marginH) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y + 1][tileColumn + x - 1];  //Aqui me aseguro que estar� mirando colisi�n derecha
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
