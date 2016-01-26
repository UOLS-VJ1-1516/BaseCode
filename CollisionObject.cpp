#include "CollisionObject.h"
#include "game.h"

CollisionObject::CollisionObject() {}
CollisionObject::~CollisionObject() {}

void CollisionObject::load(const LoaderParams* pParams) {}

void CollisionObject::draw() {}

void CollisionObject::update() {
	//Velocidad maxima en X
	if (m_velocity.m_x >= m_maxVelocity.m_x) {
		m_velocity.m_x = m_maxVelocity.m_x;
	} else if (m_velocity.m_x <= m_minVelocity.m_x) {
		m_velocity.m_x = m_minVelocity.m_x;
	}

	m_velocity.m_x += m_acceleration.m_x;

	Vector2D nuevaPos = m_position;

	nuevaPos.m_x = m_position.m_x + m_velocity.m_x;
	//Colisión en X
	if (!isCollisionWithTile(nuevaPos)) {
		m_position.m_x = nuevaPos.m_x;
	}
	else {
		m_velocity.m_x = 0;
		if (m_textureID == "enemy1" || m_textureID == "enemy") {
			speed = speed * -1;
			direction = direction * -1;
		}
	}

	//Control margenes del mapa
	if (m_position.m_x >= Game::Instance()->getGameWidth() - m_width) {
		m_position.setX(Game::Instance()->getGameWidth() - m_width);
	}
	else if (m_position.m_x <= 0) {
		m_position.setX(0);
		if (m_textureID == "enemy1" || m_textureID == "enemy") {
			speed = speed * -1;
			direction = direction * -1;
		}
	}

	if (m_position.m_y >= Game::Instance()->getGameHeight()) {
		m_position.setY(Game::Instance()->getGameHeight() - m_height);		
	}
	

	nuevaPos = m_position;
	//Velocidad maxima en Y
	if (m_velocity.m_y >= m_maxVelocity.m_y) {
		m_velocity.m_y = m_maxVelocity.m_y;
	}
	else if (m_velocity.m_y <= m_minVelocity.m_y) {
		m_velocity.m_y = m_minVelocity.m_y;
	}

	m_velocity.m_y += m_acceleration.m_y;
	nuevaPos.m_y += m_velocity.m_y;
	//Colisión en Y
	if (!isCollisionWithTile(nuevaPos))	{
		m_position.m_y = nuevaPos.m_y;
	}
	else {
		maxJump = 0;
		m_velocity.m_y = 0;
		buenaPos = m_position;		
	}
}

void CollisionObject::clean() {}

bool CollisionObject::isCollisionWithTile(Vector2D newPos) {
	if (newPos.m_y + m_height >= Game::Instance()->getGameHeight() + 38) {
		return false;
	}
	else {
		for (std::vector<TileLayer*>::iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it) {
			TileLayer* pTileLayer = (*it);

			std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
			Vector2D layerPos = pTileLayer->getPosition();

			int x, y, tileColumn, tileRow, tileid = 0;
			x = layerPos.getX() / pTileLayer->getTileSize();
			y = layerPos.getY() / pTileLayer->getTileSize();

			Vector2D startPos = newPos;
			startPos.m_x += 10;
			startPos.m_y += 4;

			Vector2D endPos;
			endPos.m_x = newPos.m_x + (m_width - 15);
			endPos.m_y = (newPos.m_y) + m_height - 4;

			for (int i = startPos.m_x; i < endPos.m_x; i++) {
				for (int j = startPos.m_y; j < endPos.m_y; j++) {
					tileColumn = i / pTileLayer->getTileSize();
					tileRow = j / pTileLayer->getTileSize();
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0) {
						return true;
					}
				}
			}
		}
		return false;
	}
}
