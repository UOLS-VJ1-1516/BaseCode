#include "StateParser.h"
#include <string>
#include "tinyxml.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "Game.h"
#include "LoaderParams.h"


bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<std::string>* pTextureIDs)
{
	TiXmlDocument xmlDoc;
	if (!xmlDoc.LoadFile(stateFile))
	{
		std::cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}

	TiXmlElement* pRoot = xmlDoc.RootElement();
	TiXmlElement* pStateRoot = 0;
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e =
		e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}

	TiXmlElement* pTextureRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{
			pTextureRoot = e;
			//std::string p = e->Value();
		}
	}
	parseTextures(pTextureRoot, pTextureIDs);


	TiXmlElement* pObjectRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=
		NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("GAMEOBJECTS"))
		{
			pObjectRoot = e;
			//std::string p = e->Value();
		}
	}
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseObjects(TiXmlElement * pStateRoot, std::vector<GameObject*>* pObjects)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		
		int x, y, width, height, spriteNum, callbackID, velocity;
		std::string textureID;
	
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("spriteNum", &spriteNum);
		textureID = e->Attribute("textureID");
		e->Attribute("callbackID", &callbackID);
		
		
		

		GameObject* pGameObject;
		pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, spriteNum, textureID, callbackID));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement * pStateRoot, std::vector<std::string>* pTextureIDs)
{
	
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		std::string filenameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute);
		TextureManager::Instance()->load(filenameAttribute, idAttribute, Game::Instance()->getRender());
	}
}
