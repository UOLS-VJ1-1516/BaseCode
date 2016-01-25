#include "LevelParser.h"
#include "GameObjectFactory.h"

Level* LevelParser::parseLevel(const char *levelFile)
{
	// create a TinyXML document and load the map XML
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(levelFile);
	// create the level object
	Level* pLevel = new Level();
	// get the root node
	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &m_tileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);

	// parse the tilesets
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("properties"))
		{
			parseTextures(e->FirstChildElement());
		}

		if (e->Value() == std::string("tileset"))
		{
			parseTilesets(e, pLevel->getTilesets());
		}
	}

	// parse any object layers
	// parse any object layers
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{

		if (e->Value() == std::string("objectgroup"))
		{
			parseObjectLayer(e, pLevel->getLayers(), pLevel);
		}
		else if (e->Value() == std::string("layer"))
		{
			parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets(), pLevel->getCollisionLayers());
		}

	}

	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot,
	std::vector<Tileset>* pTilesets)
{
	// first add the tileset to texture manager
	TextureManager::Instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"),
		pTilesetRoot->Attribute("name"),
		Game::Instance()->getRenderer());
	//parsear atributos y crear el tileset element
	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width",
		&tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height",
		&tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth +
		tileset.spacing);
	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement * pTileElement, std::vector<Layer*>* pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*>* pCollisionLayers)
{
	bool collidable = false;
	//crar un nuevo tileLayer
	TileLayer* pTileLayer = new TileLayer(m_tileSize, *pTilesets);
	// tile data
	std::vector<std::vector<int>> data;
	std::string decodedIDs;
	TiXmlElement* pDataNode = NULL;
	////////

	for (TiXmlElement* e = pTileElement->FirstChildElement(); e !=
		NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("properties"))
		{
			for (TiXmlElement* property = e->FirstChildElement(); property
				!= NULL; property = property->NextSiblingElement())
			{
				if (property->Value() == std::string("property"))
				{
					if (property->Attribute("name") == std::string("coli") && property->Attribute("value") == std::string("True"))
					{
						collidable = true;
					}
				}
			}
		}
		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}

	/////////
	for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e =
		e->NextSibling())
	{
		TiXmlText* text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}
	// uncompress zlib compression
	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0], &numGids, (const
		Bytef*)decodedIDs.c_str(), decodedIDs.size());
	std::vector<int> layerRow(m_width);
	for (int j = 0; j < m_height; j++)
	{
		data.push_back(layerRow);
	}
	for (int rows = 0; rows < m_height; rows++) {
		for (int cols = 0; cols < m_width; cols++)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}
	pTileLayer->setTileIDs(data);

	if (collidable)
	{
		pCollisionLayers->push_back(pTileLayer);
	}
	
		pLayers->push_back(pTileLayer);
	

	
}



void LevelParser::parseTextures(TiXmlElement* pTextureRoot)
{
	TextureManager::Instance()->load(pTextureRoot->Attribute("value"), pTextureRoot->Attribute("name"), Game::Instance()->getRenderer());
	file = pTextureRoot->Attribute("value");
}

void LevelParser::parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level *pLevel)
{
	ObjectLayer* pObjectLayer = new ObjectLayer();

	for (TiXmlElement* e = pObjectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("object"))
		{

			int x, y, width, height, spriteNum, rowNum, callbackID;
			std::string textureID, fileName;
			// get the initial node values type, x and y
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			e->Attribute("width", &m_width);
			e->Attribute("height", &m_height);
			
			GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
			// get the property values
			for (TiXmlElement* properties = e->FirstChildElement(); properties != NULL; properties = properties->NextSiblingElement())
			{
				if (properties->Value() == std::string("properties"))
				{
					for (TiXmlElement* property = properties->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
					{
						if (property->Value() == std::string("property"))
						{
							if (property->Attribute("name") == std::string("callbackID"))
							{
								property->Attribute("value", &callbackID);
							}
							else if (property->Attribute("name") == std::string("rowNum"))
							{
								property->Attribute("value", &rowNum);
							}
							else if (property->Attribute("name") == std::string("spriteNum"))
							{
								property->Attribute("value", &m_spriteNum);
							}
							else if (property->Attribute("name") == std::string("fileName"))
							{
								property->Attribute("value", &m_fileName);
							}
							else if (property->Attribute("name") == std::string("textureID")) {
								textureID = property->Attribute("value");
							}
							
						}
					}
				}
			}
			if (m_fileName == 1) { file = "gorda.png"; }
			else if (m_fileName == 2) { file = "cine.png"; }

			
			pObjectLayer->getGameObjects()->push_back(pGameObject);

			if (pGameObject != NULL) {
				pGameObject->load(new LoaderParams(x, y - m_height, m_width, m_height, textureID, file, m_spriteNum, rowNum, callbackID));
			    pGameObject->setCollisionLayers(pLevel->getCollisionLayers());
				if (textureID == "player") // check if it's the player
				{
					//Camera::Instance()->setTarget(pGameObject);
				}
				pObjectLayer->getGameObjects()->push_back(pGameObject);
			}
		}
	}
	pLayers->push_back(pObjectLayer);
}