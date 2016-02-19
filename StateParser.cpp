#include "StateParser.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "game.h"
#include "GameObjectFactory.h"

bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<const char* >* pTextureIDs) {
	TiXmlDocument xmlDoc;

	if (!xmlDoc.LoadFile(stateFile)) {
		return false;
	}
		
	TiXmlElement* pRoot = xmlDoc.RootElement();
		
	TiXmlElement* pStateRoot = 0;
		
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == stateID) {
			pStateRoot = e;
		}
	}

	TiXmlElement* pTextureRoot = 0;
		
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("TEXTURES")) {
			pTextureRoot = e;
		}
	}

	parseTextures(pTextureRoot, pTextureIDs);
		
	TiXmlElement* pObjectRoot = 0;
		
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("OBJECTS")) {
			pObjectRoot = e;
		}
	}

	parseObjects(pObjectRoot, pObjects);

	return false; 
}

void StateParser::parseObjects(TiXmlElement * pStateRoot, std::vector<GameObject*>* pObjects) {
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		int x, y, width, height, numSprite, speedX, speedY, maxSpeed, friction, callbackID;

		x = atoi(e->Attribute("x"));
		y = atoi(e->Attribute("y"));
		width = atoi(e->Attribute("width"));
		height = atoi(e->Attribute("height"));
		numSprite = atoi(e->Attribute("numSprite"));
		speedX = atof(e->Attribute("speedX"));
		speedY = atof(e->Attribute("speedY"));
		maxSpeed = atof(e->Attribute("maxSpeed"));
		friction = atof(e->Attribute("friction"));
		callbackID = atoi(e->Attribute("callbackID"));

		const size_t lenght = strlen(e->Attribute("textureID"));
		char* textureID = new char[lenght + 1];
		strncpy(textureID, e->Attribute("textureID"), lenght);
		textureID[lenght] = '\0';

		GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numSprite, speedX, speedY, maxSpeed, friction, callbackID));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement * pStateRoot, std::vector<const char* >* pTextureIDs) {
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		const char* fileName;
		const char* key;

		fileName = e->Attribute("fileName");
		key = e->Attribute("ID");

		pTextureIDs->push_back(key);

		TextureManager::Instance()->load(fileName, key, Game::Instance()->getRender());
	}
}
