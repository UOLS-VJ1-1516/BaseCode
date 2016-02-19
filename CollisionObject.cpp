#include "CollisionObject.h"
#include "Camera.h"

CollisionObject::CollisionObject() {}

CollisionObject::~CollisionObject() {}

void CollisionObject::load(const LoaderParams * pParams)
{}

void CollisionObject::draw()
{
}

void CollisionObject::update()
{
	if (m_velocity.getX() >= m_maxVelocity.getX())
	{
		m_velocity.setX(m_maxVelocity.getX());
	}
	else if (m_velocity.getX() <= -m_maxVelocity.getX())
	{
		m_velocity.setX(-m_maxVelocity.getX());
	}
	Vector2D prePos = m_position;
	prePos.setX(m_position.getX() + m_velocity.getX());

	if (!isCollisionWithTile(prePos))
	{
		//printf("no collision  \n");
		collision = false;
		m_position.setX(prePos.getX());
	}
	else
	{
		collision = true;
		//printf("X collision \n ");
		m_velocity.setX( 0 );
	}

	prePos = m_position;
	if (m_velocity.getY() >= m_maxVelocity.getY())
	{
		m_velocity.setY(m_maxVelocity.getY());
	}
	else if (m_velocity.getY() <= -m_maxVelocity.getY())
	{
		m_velocity.setY(-m_maxVelocity.getY());
	}
	m_velocity.setY( m_velocity.getY() + m_acceleration.getY());
	prePos.setY(m_position.getY() + m_velocity.getY());

	if (!isCollisionWithTile(prePos))
	{
		m_position.setY(prePos.getY());
	}
	else
	{	
		maxJump = 0;
		m_velocity.setY(0);
	}
}

void CollisionObject::clean()
{
}

bool CollisionObject::isCollisionWithTile(Vector2D BPos)
{
	if (BPos.getY() + m_height >= Game::Instance()->getVisibleHeight() - 32)
	{
		return false;
	}
	else
	{
		for (std::vector<TileLayer*>::iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); it++)
		{
			TileLayer* pTileLayer = (*it);

			std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
			Vector2D position_Layer (pTileLayer->getPosition().getX(),
				pTileLayer->getPosition().getY());
			int x = 0, y = 0, tileColumn = 0, tileRow = 0, tileid = 0;
			x = position_Layer.getX() / pTileLayer->getTileWidth();
			y = position_Layer.getY() / pTileLayer->getTileHeight();
			Vector2D startPos (BPos.getX()+25,BPos.getY()+20);
			Vector2D endPos;
			endPos.setX(BPos.getX() + (m_width - 25));
			endPos.setY(BPos.getY() + (m_height - 4));
			
			
			for (int i = startPos.getX(); i < endPos.getX(); i++)
			{
				for (int j = startPos.getY(); j < endPos.getY(); j++)
				{
					tileColumn = i / pTileLayer->getTileHeight();
					tileRow = j / pTileLayer->getTileWidth();
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0)
					{ //detecta colision
						return true;
					}
				}
			}
			//no hay colision
			return false;
		}
	}
}
