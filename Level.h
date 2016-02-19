#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "Vector2D.h"
#include "Layer.h"
#include "CollisionManager.h"
#include "Player.h"

class TileLayer;

class Level {
	public:
		~Level() {};

		void update();
		void render();

		std::vector<Tileset>* getTilesets() {
			return &m_tilesets;
		}

		std::vector<Layer*>* getLayers() {
			return &m_layers;
		}

		std::vector<TileLayer *>* getCollisionLayers() {
			return &m_CollisionsLayer;
		}

		Player* getPlayer() {
			return m_pPlayer;
		}

		void setPlayer(Player* pPlayer) {
			m_pPlayer = pPlayer;
		}

	private:
		Player* m_pPlayer;
		CollisionManager* m_collisionManager;
		std::vector<Tileset> m_tilesets;
		std::vector<Layer*> m_layers;
		std::vector<TileLayer*> m_CollisionsLayer;
		friend class LevelParser;
		Level();

};

#endif