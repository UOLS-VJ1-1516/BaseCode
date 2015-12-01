#include "StateParser.h"
#include "string"
#include "GameObject.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"
#include "Game.h"
#include "TextureManager.h"
#include "string"

bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<const char *>* pTextureIDs)
{

	// create the XML document
	TiXmlDocument xmlDoc;
	// load the state file

	if (!xmlDoc.LoadFile(stateFile))
	{
//		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}
	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();
	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;
	// get this states root node and assign it to pStateRoot
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e =	e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}
	// pre declare the texture root
	TiXmlElement* pTextureRoot = 0;
	// get the root of the texture elements
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{

			pTextureRoot = e;
		}
	}
	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);
	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;
	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
	{
		
		if (e->Value() == std::string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}
	// now parse the objects
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseObjects(TiXmlElement * pStateRoot, std::vector<GameObject*>* pObjects)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, speed_x, speed_y, speed_max, friction, callbackID;
		//const char* textureID;

		x = atoi(e->Attribute("x"));
		y = atoi(e->Attribute("y"));
		width = atoi(e->Attribute("width"));
		height = atoi(e->Attribute("height"));
		numFrames = atoi(e->Attribute("numFrames"));
		speed_x = atoi(e->Attribute("speed_x"));
		speed_y = atoi(e->Attribute("speed_y"));
		speed_max = atoi(e->Attribute("speed_max"));
		friction = atoi(e->Attribute("friction"));
		numFrames = atoi(e->Attribute("numFrames"));
		callbackID = atoi(e->Attribute("callbackID"));		
		//
		const size_t len = strlen(e->Attribute("textureID"));
		char * textureID = new char[len + 1];
		strncpy(textureID, e->Attribute("textureID"), len);
		textureID[len] = '\0';
		//textureID = e->Attribute("textureID");
		//e->Attribute("callbackID", &callbackID);

		GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, speed_x,speed_y,speed_max,friction, callbackID));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement * pStateRoot, std::vector<const char *>* pTextureIDs)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		const size_t len = strlen(e->Attribute("filename"));
		char * filename = new char[len + 1];
		strncpy(filename, e->Attribute("filename"), len);
		filename[len] = '\0';

		const size_t len2 = strlen(e->Attribute("ID"));
		char * ID = new char[len2 + 1];
		strncpy(ID, e->Attribute("ID"), len2);
		ID[len2] = '\0';
		pTextureIDs->push_back(ID); // push into list
		TextureManager::Instance()->load(filename, ID, Game::Instance()->getRender());
	}
}
