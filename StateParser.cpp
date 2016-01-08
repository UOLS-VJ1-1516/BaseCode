#include "StateParser.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

//Función para crear el estado seleccionado mediante XML
bool StateParser::parseState(const char *stateFile, std::string stateID, std::vector<GameObject *> *pObjects, std::vector<std::string> *pTextureIDs)
{

	TiXmlDocument xmlDoc;

	if (!xmlDoc.LoadFile(stateFile))
	{

		return false;
	}

	TiXmlElement* pRoot = xmlDoc.RootElement();

	TiXmlElement* pStateRoot = 0;

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e =e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}

	TiXmlElement* pTextureRoot = 0;

	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}

	StateParser::parseTextures(pTextureRoot, pTextureIDs);

	TiXmlElement* pObjectRoot = 0;

	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}

	StateParser::parseObjects(pObjectRoot, pObjects);
	return true;
}

//Función que rellena el vector con las texturas recogidas del xml para ese estado
void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=NULL; e = e->NextSiblingElement())
	{
		std::string filenameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute);
		TheTextureManager->load(filenameAttribute, idAttribute, TheGame->getRenderer());
	}
}

//Función que rellena el vector con los game objets recogidos del xml para ese estado
void StateParser::parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject *> *pObjects)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e !=NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, spriteNum, rowNum, callbackID, flip;
		std::string textureID, fileName;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("spriteNum", &spriteNum);
		e->Attribute("rowNum", &rowNum);
		e->Attribute("callbackID", &callbackID);
		e->Attribute("flip", &flip);
		textureID = e->Attribute("textureID");
		fileName = e->Attribute("fileName");
		GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, spriteNum, rowNum, flip, callbackID));
		pObjects->push_back(pGameObject);
	}
}