#include "StateParser.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "Game.h"
//#include "LoaderParams.h"
#include <string>

bool StateParser::parseState(const char* stateFile, std::string stateID, std::vector<GameObject *> *pObjects, std::vector<std::string> *pTextureIDs) {
	
	// create the XML document
	TiXmlDocument xmlDoc;
	//load the state file
	
	if (!xmlDoc.LoadFile(stateFile)) {
		printf(">>>>%s\n", xmlDoc.ErrorDesc());
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
	
	//Aqui ya no peta
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

void StateParser::parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects)
{
	int i = 100;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		int x, y, width, height, numFrames, callbackID;
		//const char* textureID;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);

		const size_t len = strlen(e->Attribute("textureID"));
		char * textureID = new char[len + 1];
		strncpy(textureID, e->Attribute("textureID"), len);
		textureID[len] = '\0';

		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callbackID);

		GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string>* pTextureIDs)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		const char* filenameAttribute = e->Attribute("filename");
		const char* idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute); // push into list
		TextureManager::Instance()->load(filenameAttribute, idAttribute, Game::Instance()->getRender());
	}
}
