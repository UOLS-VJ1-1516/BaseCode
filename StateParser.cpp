#include "StateParser.h"
#include "string"
#include "GameObject.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"
#include "Game.h"
#include "TextureManager.h"
#include "string"

bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<std::string>* pTextureIDs)
{
	// create the XML document
	XMLDocument xmlDoc;
	// load the state file

	if (!xmlDoc.LoadFile(stateFile))
	{
//		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}
	// get the root element
	XMLElement* pRoot = xmlDoc.RootElement();
	// pre declare the states root node
	XMLElement* pStateRoot = 0;
	// get this states root node and assign it to pStateRoot
	for (XMLElement* e = pRoot->FirstChildElement(); e != NULL; e =	e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}
	// pre declare the texture root
	XMLElement* pTextureRoot = 0;
	// get the root of the texture elements
	for (XMLElement* e = pStateRoot->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{

			pTextureRoot = e;
		}
	}
	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);
	// pre declare the object root node
	XMLElement* pObjectRoot = 0;
	// get the root node and assign it to pObjectRoot
	for (XMLElement* e = pStateRoot->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
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

void StateParser::parseObjects(XMLElement * pStateRoot, std::vector<GameObject*>* pObjects)
{
	for (XMLElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, speed_x, speed_y, speed_max, friction;
		const char* textureID;

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
		textureID = e->Attribute("textureID");
		//e->Attribute("callbackID", &callbackID);

		GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, speed_x,speed_y,speed_max,friction));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(XMLElement * pStateRoot, std::vector<std::string>* pTextureIDs)
{
	for (XMLElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		const char* filename = e->Attribute("filename");
		const char* ID = e->Attribute("ID");
		pTextureIDs->push_back(ID); // push into list
		TextureManager::Instance()->load(filename, ID, Game::Instance()->getRender());
	}
}
