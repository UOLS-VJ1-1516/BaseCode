#include "StateParser.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "MenuButton.h"

using namespace std;

bool StateParser::parseState(const char * stateFile, std::string stateID, std::vector<GameObject*>* pObjects, std::vector<std::string>* pTextureIDs)
{
	XMLDocument doc;
	stringstream ss;
	ss << XMLPath << stateFile;

	string arxiu;
	ss >> arxiu;
	ss.clear();
	doc.LoadFile (arxiu.c_str());

	if (doc.Error())
	{
		cout << doc.ErrorName() << endl;
		return false;
	}
	XMLElement* state = doc.FirstChildElement("States");

	//XML llegim els tags i el que hi ha a dintre de textures
	XMLElement* textures = state->FirstChildElement("Textures");
	for (XMLElement* tex = textures->FirstChildElement("texture"); tex != NULL; tex = tex->NextSiblingElement("texture")) {	
		parseTextures(tex, pTextureIDs);		
	}

	
	//XML llegim els tags i el que hi ha a dintre de objects
	XMLElement* objects = state->FirstChildElement("objects");
	for (XMLElement* tex = objects->FirstChildElement("object"); tex != NULL; tex = tex->NextSiblingElement("object")) {		
		parseObjects(tex, pObjects);		
	}

	return true;
}

void StateParser::parseObjects(XMLElement * pStateRoot, std::vector<GameObject*>* pObjects)
{
	
	string type = pStateRoot->Attribute("type");
	int x = atoi(pStateRoot->Attribute("x"));
	int y = atoi(pStateRoot->Attribute("y"));
	int width = atoi(pStateRoot->Attribute("width"));
	int height = atoi(pStateRoot->Attribute("height"));
	string textureID = pStateRoot->Attribute("textureID");
	int numFrames = atoi(pStateRoot->Attribute("numFrames"));

	GameObject* Go = GameObjectFactory::Instance()->CreateGameObject(type);
	if (dynamic_cast<MenuButton*>(Go)) {
		int callbackID = atoi(pStateRoot->Attribute("callbackID"));
		if(callbackID != 0){
			dynamic_cast<MenuButton*>(Go)->setcallbackID(callbackID);
		}
	}

	LoaderParams* Params = new LoaderParams(x, y, width, height, textureID.c_str(), numFrames);
	Go->load(Params);

	pObjects->push_back(Go);
	
}

void StateParser::parseTextures(XMLElement * pStateRoot, std::vector<std::string>* pTextureIDs)
{
	string file = pStateRoot->Attribute("filename");
	string id = pStateRoot->Attribute("ID");
	Manager->load(file.c_str(), id.c_str());
	pTextureIDs->push_back(id);
}
