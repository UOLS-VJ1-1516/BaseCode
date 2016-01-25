#include "StateParser.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"


bool StateParser::parseState(const char *stateFile, std::string stateID, std::vector<GameObject *> *pObjects, std::vector<std::string> *pTextureIDs)
{
	// instanciar xmldoc
	TiXmlDocument xmlDoc;

	// mira si esta cargada correctamente
	if (!xmlDoc.LoadFile(stateFile))
	{
		return false;
	}

	// conseguir el root
	TiXmlElement* pRoot = xmlDoc.RootElement();

	//declarar el nodo de <menu>...
	TiXmlElement* pStateRoot = 0;

	//busca el state segun el id que hemos pasado
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}

	// declarar el nodo de <texture>
	TiXmlElement* pTextureRoot = 0;


	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=
		NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}

	//buscar la textura
	parseTextures(pTextureRoot, pTextureIDs);

	// declarar el nodo <objeto> 
	TiXmlElement* pObjectRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}

	// buscar el objeto
	parseObjects(pObjectRoot, pObjects);
	return true;

}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	//buscar textura y anadirla 
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=NULL; e = e->NextSiblingElement())
	{
			std::string filenameAttribute = e->Attribute("filename");
			std::string idAttribute = e->Attribute("ID");
			pTextureIDs->push_back(idAttribute);
			TheTextureManager->load(filenameAttribute, idAttribute, Game::Instance()->getRenderer());
		
	}
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject *> *pObjects)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, spriteNum, rowNum, callbackID;
		std::string textureID, fileName;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("spriteNum", &spriteNum);
		e->Attribute("rowNum", &rowNum);
		e->Attribute("callbackID", &callbackID);
		textureID = e->Attribute("textureID");
		//fileName = e->Attribute("fileName");

		GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, fileName, spriteNum, rowNum, callbackID));
		pObjects->push_back(pGameObject);

	}
}