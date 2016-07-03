#include "LevelParser.h"
#include "TextureManager.h"
#include "game.h"
#include "tinyxml.h"
#include "tinystr.h"
#include "libs\zlib\include\zconf.h"
#include "libs\zlib\include\zlib.h"
#include "base64.h"
#include "ObjectLayer.h"
#include "GameObjectFactory.h"


LevelParser::LevelParser()
{
}


LevelParser::~LevelParser()
{
}

Level* LevelParser::parseLevel(const char *levelFile){
	// create a TinyXML document and load the map XML
	TiXmlDocument levelDocument;
	int flag=0;
	levelDocument.LoadFile(levelFile);
	// create the level object
	Level* pLevel = new Level();
	Level* pLevel2 = new Level();
	// get the root node
	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &m_tileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);
	// parse the tilesets
	for (TiXmlElement * e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("properties")) {
			TiXmlElement * pPropierties = e;
			for (TiXmlElement * e = pPropierties->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
				parseTextures(e);
			}
		}

		if (e->Value() == std::string("tileset")) {
			parseTilesets(e, pLevel->getTilesets());
			
		}

		if (e->Value() == std::string("objectgroup") || e->Value() == std::string("layer")) {
			//parseObjectLayer(e, pLevel->getLayers());
			if (e->FirstChildElement()->Value() == std::string("object"))
			{
				parseObjectLayer(e, pLevel->getLayers(), pLevel);
				flag = 1;
			}
			else if (e->FirstChildElement()->Value() == std::string("data")|| e->FirstChildElement()->Value() == std::string("properties")) {
				parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets(), pLevel->getCollisionLayers());
			}
		}
		/*
		if (flag == 1) {
			pLevel2 = pLevel;
			flag = 0;
			//return pLevel2;
		}
		*/
	}
	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets){
	// first add the tileset to texture manager
	TextureManager::Instance()->load(pTilesetRoot ->FirstChildElement()->Attribute("source"), pTilesetRoot ->Attribute("name"), Game::Instance()->getRender());
	// create a tileset object
	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);
	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*>* p_colisionLayers){
	TileLayer* pTileLayer = new TileLayer(m_tileSize, m_width, m_height, *pTilesets);
	// tile data
	std::vector<std::vector<int>> data;
	std::string decodedIDs;
	bool isColision = false;
	TiXmlElement* pDataNode;
	for (TiXmlElement* e = pTileElement->FirstChildElement(); e !=NULL; e = e->NextSiblingElement()){
		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
		else if (e->Value() == std::string("properties")){
			TiXmlElement* properties = e->FirstChildElement();
			if (properties->Attribute("name") == std::string("isColision")) {
				if (strcmp(properties->Attribute("value"),"true")==0) {
					isColision = true;
					p_colisionLayers->push_back(pTileLayer);
				}
				else {
					isColision = false;
				}
				pTileLayer->setisColision(isColision);
			}
		}
	}
	for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e =e->NextSibling()){
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

	for (int rows = 0; rows < m_height; rows++) {
		for (int cols = 0; cols < m_width; cols++)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}

	pTileLayer->setTileIDs(data);
	pLayers->push_back(pTileLayer);
}

void LevelParser::parseTextures(TiXmlElement* pTextureRoot)
{
	TextureManager::Instance()->load(pTextureRoot ->Attribute("value"), pTextureRoot->Attribute("name"), Game::Instance()->getRender());
}

void LevelParser::parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level* pLevel) {
	// create an object layer
	ObjectLayer* pObjectLayer = new ObjectLayer();
	std::cout << pObjectElement->FirstChildElement()->Value();
	for (TiXmlElement* e = pObjectElement->FirstChildElement(); e !=NULL; e = e->NextSiblingElement()){
		std::cout << e->Value();
		if (e->Value() == std::string("object")){
			int x, y, width, height, numFrames, callbackID, animSpeed;
			std::string textureID;
			// get the initial node values type, x and y
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e ->Attribute("type"));
			// get the property values
			for (TiXmlElement* properties = e->FirstChildElement(); properties != NULL; properties = properties->NextSiblingElement())
			{
				if (properties->Value() == std::string("properties"))
				{
					for (TiXmlElement* property = properties ->FirstChildElement(); property != NULL; property = property ->NextSiblingElement())
					{
						if (property->Value() == std::string("property"))
						{
							if (property->Attribute("name") == std::string("numFrames"))
							{
								property->Attribute("value", &numFrames);
							}
							else if (property->Attribute("name") == std::string("textureHeight"))
							{
								property->Attribute("value", &height);
							}
							else if (property->Attribute("name") == std::string("textureID"))
							{
								textureID = property->Attribute("value");
							}

							else if (property->Attribute("name") == std::string("textureWitdh"))
							{
								property->Attribute("value", &width);
							}
							else if (property->Attribute("name") == std::string("callbackID"))
							{
								property->Attribute("value", &callbackID);
							}
							//else if (e->Attribute("name") == std::string("animSpeed"))
							//{
								//property->Attribute("value", &animSpeed);
							//}
						}
					}
				}
			}
			if (dynamic_cast<CollisionObject*>(pGameObject))
			{
				CollisionObject* pCollisionObj = dynamic_cast<CollisionObject*>(pGameObject);
				pCollisionObj->setCollisionLayers(pLevel->getCollisionLayers());
			}

			pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID));
			//pGameObject->load(new LoaderParams(200, 200, 80, 100, "nina", 0, 0));
			pObjectLayer->getGameObjects()->push_back(pGameObject);
		}
	}
	pLayers->push_back(pObjectLayer);
}
