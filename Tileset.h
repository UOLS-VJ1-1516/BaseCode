/*
esta clase contiene toda la informacion del tile
*/
#pragma once
#include "map"

class Tileset
{
public:
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
	
};