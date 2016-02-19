#include "LevelParser.h"
#include "TextureManager.h"
#include "GameObjectFactory.h"
#include "game.h"
#include "Camera.h"
#include "Player.h"

Level * LevelParser::parseLevel(const char * levelFile)
{
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(levelFile);

	Level* parseLevel = new Level();

	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &m_tileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);


	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("properties"))
		{
			parseTextures(e->FirstChildElement());
		}
	}

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("tileset"))
		{
			parseTilesets(e, parseLevel->getTilesets());
		}
	}

	// parse any object layers
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{

		if (e->Value() == std::string("objectgroup"))
		{
			parseObjectLayer(e, parseLevel->getLayers(), parseLevel);
		}
		else if (e->Value() == std::string("layer"))
		{
			parseTileLayer(e, parseLevel->getLayers(), parseLevel->getTilesets(), parseLevel->getCollisionLayers());
		}
		
	}
	for (TiXmlElement* e = pRoot->FirstChildElement(); 
		e != NULL;
		e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("property"))
		{
			parseTextures(e);
		}
	}
	return parseLevel;
}



void LevelParser::parseTilesets(TiXmlElement * pTilesetRoot, std::vector<Tileset>* pTilesets)
{

	TextureManager::Instance()->load(pTilesetRoot ->FirstChildElement()->Attribute("source"), pTilesetRoot ->Attribute("name"), Game::Instance()->getRenderer());

	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width",&tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height",&tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);
	pTilesets->push_back(tileset);

}
void LevelParser::parseTileLayer(TiXmlElement * pTileElement, std::vector<Layer*>* pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*>* pCollisionlayers)
{
	TileLayer* pTileLayer = new TileLayer(m_tileSize, m_tileSize, m_width, m_height, *pTilesets);
	// tile data
	bool collisionable = false;
	std::vector<std::vector<int>> data;
	std::string decodedIDs;
	TiXmlElement* pDataNode;
	for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("properties"))
		{
			for (TiXmlElement* property = e->FirstChildElement();
				property != NULL;
				property = property->NextSiblingElement())
			{
				if (property->Value() == std::string("property"))
				{
					if (property->Attribute("name") == std::string("isCollision"))
					{
						property->QueryBoolAttribute("value", &collisionable);
					}
				}
			}
		}
		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}
	for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	{
		TiXmlText* text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}
	// uncompress zlib compression
	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
	std::vector<int> layerRow(m_width);
	for (int j = 0; j < m_height; j++)
	{
		data.push_back(layerRow);
	}
	for (int rows = 0; rows < m_height; rows++)
	{
		for (int cols = 0; cols < m_width; cols++)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}
	
	pTileLayer->setTileIDs(data);
	if (collisionable) {
		pCollisionlayers->push_back(pTileLayer);
	}
	pLayers->push_back(pTileLayer);
}

void LevelParser::parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level* parseLevel)
{
	// create an object layer
	ObjectLayer* pObjectLayer = new ObjectLayer();
	std::cout << pObjectElement->FirstChildElement()->Value();
	for (TiXmlElement* e = pObjectElement->FirstChildElement(); 
		e != NULL;
		e = e->NextSiblingElement())
	{
		std::cout << e->Value();
		if (e->Value() == std::string("object"))
		{
			int x, y, width, height, numFrames, callbackID, animSpeed;
			std::string textureID;
			// get the initial node values type, x and y
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			e->Attribute("width", &width);
			e->Attribute("height", &height);
			GameObject* pGameObject = TheGameObjectFactory->CreateGameObject(e ->Attribute("type"));
			// get the property values
			for (TiXmlElement* properties = e->FirstChildElement();
			properties != NULL; properties = properties->NextSiblingElement())
			{
				if (properties->Value() == std::string("properties"))
				{
					for (TiXmlElement* property = properties->FirstChildElement();
						property != NULL;
						property = property->NextSiblingElement())
					{
						if (property->Value() == std::string("property"))
						{
							if (property->Attribute("name") == std::string("numSprites"))
							{
								property->Attribute("value", &numFrames);
							}
							else if (property->Attribute("name") == std::string("textureID"))
							{
								textureID = property->Attribute("value");
							}
							else if (property->Attribute("name") == std::string("animSpeed"))
							{
								property->Attribute("value", &animSpeed);
							}
							else if (property->Attribute("name") == std::string("callbackID"))
							{
								property->Attribute("value", &callbackID);
							}
						}
					}
				}
			}
			pGameObject->load(new LoaderParams(x, y, width, height, numFrames, textureID, callbackID, animSpeed));
			if (textureID == "player") {
				Camera::Instance()->setTarget(pGameObject);
				parseLevel->setPlayer(dynamic_cast<Player*>(pGameObject));
				
			}
			parseLevel->m_gameobjects.push_back(pGameObject);
			pGameObject->setCollisionLayers(parseLevel->getCollisionLayers());
			pObjectLayer->getGameObjects()->push_back(pGameObject);
		}
	}
	pLayers->push_back(pObjectLayer);
}
void LevelParser::parseTextures(TiXmlElement* pTextureRoot)
{
	TextureManager::Instance()->load(pTextureRoot ->Attribute("value"), pTextureRoot->Attribute("name"),
		Game::Instance()->getRenderer());
}