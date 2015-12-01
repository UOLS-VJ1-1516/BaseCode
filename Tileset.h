#pragma once
#include "string"
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int numColumns;
	std::string name;
};