#include "CollisionObject.h"
#include "game.h"


CollisionObject::CollisionObject() {

}
CollisionObject::~CollisionObject() {

}
void CollisionObject::load(const LoadPar* pParams) {

}
void CollisionObject::draw()
{

}
void CollisionObject::update()
{
}
void CollisionObject::clean()
{

}

bool CollisionObject::isCollisionWithTile()
{
	
	
	//Diria que... //y+1  x-1 -> Miro izquierda 
			//y-1 x-1 -> Miro arriba 
			//y+1 x+1 -> Miro abajo
	// y-1][tileColumn + x+1];   Miro derecha
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
	{

		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		m_tileSize = pTileLayer->getTileSize();
		Vector2D layerPos = pTileLayer->getPosition();
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		//m_TileWith = pTileLayer->getTileWith(); //Miro ancho de mi mapa
		//m_TileHeight = pTileLayer->getTileHeight();  //Miro alto de mi mapa
		//x = pTileLayer->getPosition().getX() / m_tileSize;  //Cojo la posicion del objeto que ha llamado esta funcion
		//y = pTileLayer->getPosition().getY() / m_tileSize; //Cojo la posicion del objeto que ha llamado esta funcion
		
		 // Si me estoy moviedno a derecha o arriba
		if (getVelocity().getX() > 0 || getVelocity().getY() > 0)
		{
			tileColumn = ((getPosition().getX() +getWidth()-30) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight()-62)/ pTileLayer->getTileSize());
			tileid = tiles[tileRow + y][tileColumn + x];
		}

		// Si me estoy moviedno a izquierda o abajo
		else if (getVelocity().getX() < 0 || getVelocity().getY() < 0) // if moving backwards or downwards
		{
			tileColumn =( getPosition().getX() + getWidth()-70) / pTileLayer ->getTileSize();
			tileRow = (getPosition().getY() + getHeight()-62) / pTileLayer ->getTileSize();
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

		//m_TileWith = pTileLayer->getTileWith(); //Miro ancho de mi mapa
		//m_TileHeight = pTileLayer->getTileHeight();  //Miro alto de mi mapa
		//x = pTileLayer->getPosition().getX() / m_tileSize;  //Cojo la posicion del objeto que ha llamado esta funcion
		//y = pTileLayer->getPosition().getY() / m_tileSize; //Cojo la posicion del objeto que ha llamado esta funcion

		// Si me estoy moviedno a derecha o arriba
		if (getVelocity().getX() > 0 || getVelocity().getY() > 0)
		{
			tileColumn = ((getPosition().getX() + getWidth() - 30) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight() - 62) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y-1][tileColumn + x+1];  //Aqui me aseguro que estaré mirando colisión derecha
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

		/*
		Vector2D cajainicial = posicio;
		cajainicial.setX(cajainicial.getX()+100);
		cajainicial.setY(cajainicial.getY() + 50);

		Vector2D cajafinal;
		cajafinal.setX(cajafinal.getX() -100);
		cajafinal.setY(cajafinal.getY()-50);


		for (int i = cajainicial.getX(); i < cajafinal.getX(); i++) {
			for (int j = cajainicial.getY(); j < cajafinal.getY(); j++) {
				tileColumn = i / pTileLayer->getTileSize();
				tileRow = j / pTileLayer->getTileSize();
				tileid = tiles[tileRow + y][tileColumn + x]; 
					if (tileid != 0) {
						return true;
					}
			}
		}
					
		}*/
			
			
	
