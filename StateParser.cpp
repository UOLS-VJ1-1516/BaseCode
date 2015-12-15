#pragma once
#include "StateParser.h"
#include <vector>
#include "TextureManager.h"
#include "game.h"
#include "GameObjectFactory.h"
//#include "GameObject.h"
//#include "LoaderParams.h"

bool StateParser::parseState(std::string stateFile, std::string stateID, std::vector<GameObject*> * pObjects, std::vector<std::string> *pTextureIDs)
{
	// create the XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(stateFile)) {
		return false;
	}

	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;

	// get this states root node and assign it to pStateRoot
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == stateID) {
			pStateRoot = e;
		}
	}

	// pre declare the texture root
	TiXmlElement* pTextureRoot = 0;

	// get the root of the texture elements
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("TEXTURES")) {
			pTextureRoot = e;
		}
	}

	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);

	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;

	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("OBJECTS")) {
			pObjectRoot = e;
		}
	}

	// now parse the objects
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject *> *pObjects)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		int x, y, width, height, spriteNum, callbackID;
		std::string fileName;
		std::string textureID;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("spriteNum", &spriteNum);
		e->Attribute("callbackID", &callbackID);
		textureID = e->Attribute("textureID");
		fileName = e->Attribute("fileName");
		GameObject* pGameObject = TheGameObjectFactory->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, fileName, spriteNum, callbackID));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		std::string filename = e->Attribute("filename");
		std::string id = e->Attribute("ID");
		pTextureIDs->push_back(id); // push into list
		TextureManager::Instance()->load(filename, id, Game::Instance()->getRender());
	}
}