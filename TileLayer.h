#pragma once
#include <iostream>
#include "Tileset.h"
#include "Vector2D.h"
#include <vector>
#include "Player.h"

class TileLayer
{
private:
	int tileWidth;
	int tileHeight;
	Vector2D position;
	std::vector<Tileset> tilesets;
	std::vector<std::vector<int>> tileIDs;
	void Draw(std::string, int, int, int, int, int, int, int, int);
public:
	TileLayer(int, int, std::vector<Tileset>);
	virtual ~TileLayer();
	void Update(Player *);
	void Render();
	void SetTileIDs(const std::vector<std::vector<int>>&);
	Tileset * GetTileset(int);
};