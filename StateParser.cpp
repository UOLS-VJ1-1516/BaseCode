#include "StateParser.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "Game.h"
#include "LoaderParams.h"
#include <string>

bool StateParser::parseState(const char* stateFile, string stateID,
	std::vector<GameObject*> * pObjects, std::vector<string> * pTextureIDs)
{
	// create the XML document
	TiXmlDocument xmlDoc;

	// load the state file
	if (!xmlDoc.LoadFile(stateFile)){		
		return false;
	}

	// get the root element
	TiXmlElement* pRoot = xmlDoc.RootElement();

	// pre declare the states root node
	TiXmlElement* pStateRoot = 0;
	// get this states root node and assign it to pStateRoot
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
			break;
		}
	}

	// pre declare the texture root
	TiXmlElement* pTextureRoot = 0;

	// get the root of the texture elements
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == string("TEXTURES"))
		{
			pTextureRoot = e;
			break;
		}
	}

	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);

	// pre declare the object root node
	TiXmlElement* pObjectRoot = 0;

	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == string("OBJECTS"))
		{
			pObjectRoot = e;
			break;
		}
	}

	// now parse the objects
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<string> *pTextureIDs)
{
	// for each texture we get the file name and the desired ID and add them to the texture manager
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		const char* filenameAttribute, *idAttribute;

		filenameAttribute = e->Attribute("filename");
		idAttribute = e->Attribute("ID");

		pTextureIDs->push_back(idAttribute); 
		TextureManager::Instance()->load(filenameAttribute, idAttribute, Game::Instance()->getRenderer());
	}
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, std::vector<GameObject *> *pObjects)
{
	int width;
	int height;
	string textureID;
	int currentRow;
	int sprits;
	int flip;
	Vector2D position, velocity, maxVelocity, acceleration, friction;
	int px, py;
	int vx, vy;
	int mvx, mvy;
	int ax, ay;
	int fx, fy;
	int callbackId;

	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		e->Attribute("px", &px);
		e->Attribute("py", &py);
		e->Attribute("vx", &vx);
		e->Attribute("vy", &vy);
		e->Attribute("mvx", &mvx);
		e->Attribute("mvy", &mvy);
		e->Attribute("ax", &ax);
		e->Attribute("ay", &ay);
		e->Attribute("fx", &fx);
		e->Attribute("fy", &fy);
		e->Attribute("callbackID", &callbackId);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		textureID = e->Attribute("textureID");
		e->Attribute("currentRow", &currentRow);
		e->Attribute("numFrames", &sprits);
		e->Attribute("flip", &flip);		

		position = *(new Vector2D(px, py));
		velocity = *(new Vector2D(vx, vy));
		maxVelocity = *(new Vector2D(mvx, mvy));
		acceleration = *(new Vector2D(ax, ay));
		friction = *(new Vector2D(fx, fy));			
		
		GameObject* tGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));		
		tGameObject->load(new LoaderParams(width,height,textureID,currentRow,sprits,flip, callbackId,position,velocity, maxVelocity,acceleration,friction));
		pObjects->push_back(tGameObject);
	}
}