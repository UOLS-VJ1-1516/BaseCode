#include "GameObject.h"
#include "TextureManager.h"
#include "game.h"
#include "CollisionObject.h"
#include "Vector2D.h"

//Constructor y destructor
CollisionObject::CollisionObject()
{
}

CollisionObject::~CollisionObject()
{
}

//Función para cargar los parametros de los diferentes game objects
void CollisionObject::load(const LoaderParams* pParams) {
}

void CollisionObject::draw()
{
}

void CollisionObject::update()
{
	Vector2D nuevaPos = m_position;
	nuevaPos.setX(m_position.m_x + m_velocity.m_x);
	if (!isCollisionWithTile(nuevaPos))
	{
		m_position.setX(nuevaPos.getX());
		
	}
	else
	{
		m_velocity.setX(0);
		if (m_textureID == "enemy") {
			run  = run * (-1);
			lado = lado * (-1);
		}
	}

	nuevaPos = m_position;
	nuevaPos.setY(nuevaPos.getY() + m_velocity.getY());
	if (!isCollisionWithTile(nuevaPos))
	{
		m_position.setY(nuevaPos.getY());
	}
	else
	{
		saltoMax = 0;
		m_velocity.m_y = 0;
	}
}
void CollisionObject::clean()
{
}

bool CollisionObject::isCollisionWithTile(Vector2D newPos){

	if (newPos.m_y + m_height >= Game::Instance()->getScreenHeight() - 10)
	{
		return false;
	}
	else
	{
		for (std::vector<TileLayer*>::iterator it = pCollisionLayers->begin(); it != pCollisionLayers->end(); ++it)
		{
			TileLayer* pTileLayer = (*it);

			std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
			Vector2D layerPos = pTileLayer->getPosition();
			int x, y, tileColumn, tileRow, tileid = 0;
			x = layerPos.getX() / pTileLayer->getTileSize();
			y = layerPos.getY() / pTileLayer->getTileSize();
			Vector2D startPos = newPos;
			startPos.m_x += 15;
			startPos.m_y += 20;
			Vector2D endPos;
			endPos.m_x = newPos.m_x + (m_width - 15);
			endPos.m_y = (newPos.m_y) + m_height - 4;
			for (int i = startPos.m_x; i < endPos.m_x; i++)
			{
				for (int j = startPos.m_y; j < endPos.m_y; j++)
				{
					tileColumn = i / pTileLayer->getTileSize();
					tileRow = j / pTileLayer->getTileSize();
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
}