#include "LevelParser.h"
#include "base64.h"
#include "zlib.h"
#include "TileLayer.h"
#include "Game.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "ObjectLayer.h"
#include "Level.h"


Level * LevelParser::parseLevel(const char * levelFile) {
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(levelFile);

	Level * pLevel = new Level();

	TiXmlElement * pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &m_TileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);

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
			
			if (e->FirstChildElement()->Value() == std::string("object"))
			{
				parseObjectLayer(e, pLevel->getLayers());
			}
			else if (e->FirstChildElement()->Value() == std::string("data")) {
				parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
			}
		}
		
	}
	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement * pTilesetRoot, std::vector<Tileset>*pTilesets) {
	std::string file = "Data/" + std::string(pTilesetRoot->FirstChildElement()->Attribute("source"));
	TextureManager::Instance()->load(file.c_str(), pTilesetRoot->Attribute("name"), Game::Instance()->getRender());
	Tileset tileset;

	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);


	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement * pTileElement, std::vector<Layer*>*pLayers, const std::vector<Tileset>*pTilesets) {
	TileLayer * pTileLayer = new TileLayer(m_TileSize, *pTilesets);

	std::vector<std::vector<int>>data;
	std::string decodedIDs;

	TiXmlElement *pDataNode;

	for (TiXmlElement * e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			pDataNode = e;
		}
	}
	for (TiXmlNode * e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling()) {

		TiXmlText* text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}
		uLongf numGids = m_width * m_height * sizeof(int);
		std::vector<unsigned> gids(numGids);
		uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
		std::vector<int> layerRow(m_width);
		for (int j = 0; j < m_height + 2; j++)
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
		pLayers->push_back(pTileLayer);
	
}
void LevelParser::parseTextures(TiXmlElement*pTextureRoot) {
	TextureManager::Instance()->load(pTextureRoot->Attribute("value"), pTextureRoot->Attribute("name"), Game::Instance()->getRender());
}
void LevelParser::parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*>*pLayers) {
	ObjectLayer * pObjectLayer = new ObjectLayer();
	std::cout << pObjectElement->FirstChildElement()->Value();

	for (TiXmlElement*e = pObjectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("object")) {
			int x, y, width, height, spriteNum, callbackID, animSpeed;
			std::string textureID;

			e->Attribute("x", &x);
			e->Attribute("y", &y);
			GameObject*pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));

			for (TiXmlElement * propierties = e->FirstChildElement(); propierties != NULL; propierties = propierties->NextSiblingElement()) {
				if (propierties->Value() == std::string("properties")) {
					for (TiXmlElement*property = propierties->FirstChildElement(); property != NULL; property = property->NextSiblingElement()) {
						if (property->Value() == std::string("property")) {
							if (property->Attribute("name") == std::string("spriteNum")) {
								property->Attribute("value", &spriteNum);
							}
							else if (property->Attribute("name") == std::string("textureHeight")) {
								property->Attribute("value", &height);
							}
							else if (property->Attribute("name") == std::string("textureID")) {
								textureID = property->Attribute("value");
							}
							else if (property->Attribute("name") == std::string("textureWidth")) {
								property->Attribute("value", &width);
							}
							else if (property->Attribute("name") == std::string("callbackID")) {
								property->Attribute("value", &callbackID);
							}
							/*else if (property->Attribute("name") == std::string("animSpeed")) {
								property->Attribute("value", &animSpeed);
							}*/
						}
					}
				}
			}
			pGameObject->load(new LoaderParams(x, y, width, height,spriteNum, textureID, callbackID));
			pObjectLayer->getGameObjects()->push_back(pGameObject);

		}
	}
	pLayers->push_back(pObjectLayer);

}
