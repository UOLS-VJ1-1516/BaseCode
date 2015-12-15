#pragma once

#include <tinyxml2.h>
#include "Tileset.h"
#include "TileLayer.h"
#include <iostream>
#include <vector>
#include <zlib.h>
#include "libs\base64\base64.h"

#define Layerer LayerParser::GetInstance()

class LayerParser
{
private:
	static LayerParser * instance;
	void ParseTileset(tinyxml2::XMLElement *, Tileset *);
	std::vector<std::vector<int>> ParseData(std::string, int, int);
public:
	static LayerParser * GetInstance() 
	{
		if (instance == NULL)
		{
			instance = new LayerParser();
		}
		return instance;
	}

	TileLayer * ParseTileLayer(std::string);
};