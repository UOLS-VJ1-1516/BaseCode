#include "CollisionObject.h"
#include "Game.h"

CollisionObject::CollisionObject() {};
CollisionObject::~CollisionObject() {};

void CollisionObject::load(const LoaderParams * pParams)
{
}

void CollisionObject::draw()
{
}

void CollisionObject::clean()
{
	
}

bool CollisionObject::isCollisionWithTile(Vector2D newPos)
{
	if (newPos.getY() + m_height >= Game::Instance()->getGameHeight() - 32)
	{
		return false;
	}
	else
	{
		for (std::vector<TileLayer*>::iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it)
		{
			TileLayer* pTileLayer = (*it);

			std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
			Vector2D layerPos = pTileLayer->getPosition();
			int x, y, tileColumn, tileRow, tileid = 0;
			x = layerPos.getX() / pTileLayer->getTileSize();
			y = layerPos.getY() / pTileLayer->getTileSize();
			Vector2D startPos = newPos;
			startPos.setX(startPos.getX() + 15);
			startPos.setY(startPos.getY() + 20);
			Vector2D endPos;
			endPos.setX(newPos.getX() + (m_width - 15));
			endPos.setY((newPos.getY()) + m_height - 4);
			for (int i = startPos.getX(); i < endPos.getX(); i++)
			{
				for (int j = startPos.getY(); j < endPos.getY(); j++)
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
			return false;
		}
	}
	
}

void CollisionObject::update()
{
	if (m_velocity.getX() >= m_maxVelocity) {
		m_velocity.setX(m_maxVelocity);
	}
	else if (m_velocity.getX() <= m_maxVelocity)
	{
		m_velocity.getX();
	}
	m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

	Vector2D nuevaPos = m_position;

	nuevaPos.setX(m_position.getX() + m_velocity.getX());

	if (!isCollisionWithTile(nuevaPos))
	{

		m_position.setX(nuevaPos.getX());
	}
	else
	{

		m_velocity.setX(0);
	}
	nuevaPos = m_position;

	if (m_velocity.getY() >= m_maxVelocity)
	{
		m_velocity.setY(m_maxVelocity);
	}
	else if (m_velocity.getY() <= m_maxVelocity)
	{
		m_velocity.setY(m_velocity.getY());

		m_velocity.setY(m_velocity.getY() + m_acceleration.getY());
		nuevaPos.setY(nuevaPos.getY() + m_velocity.getY());

		if (!isCollisionWithTile(nuevaPos))
		{

			m_position.setY(nuevaPos.getY());
		}
		else
		{
			topeJump = 0;

			m_velocity.setX(0);

			buenaPos = m_position;

			if (m_velocity.getX() > 0)
			{
				buenaPos.setX(buenaPos.getX() - 100);
			}
			else if (m_velocity.getX() < 0)
			{
				buenaPos.setX(buenaPos.getX() + 100);
			}
		}
	}
}

