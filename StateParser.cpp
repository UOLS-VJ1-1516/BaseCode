#include "StateParser.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "game.h"
#include "GameObjectFactory.h"

using namespace std;

bool StateParser::parseState(string stateFile, std::string stateID, std::vector<GameObject*>* objects, std::vector<std::string>* textureIDs) {
	XMLDocument xml;
	xml.LoadFile(stateFile.c_str());
	if (xml.Error()) {
		cout << "XML ERROR: " << endl << xml.ErrorName() << endl;
		return false;
	}
	XMLElement * state = (xml.FirstChildElement("STATES"))->FirstChildElement(stateID.c_str());
	StateParser::parseTextures(state->FirstChildElement("TEXTURES"), textureIDs);
	StateParser::parseObjects(state->FirstChildElement("GAMEOBJECTS"), objects);
	return true;
}

void StateParser::parseObjects(XMLElement * stateRoot, std::vector<GameObject*>* objects) {
	for (auto object = stateRoot->FirstChildElement("TEXTURE");
		object != NULL;
		object = object->NextSiblingElement("TEXTURE")) {
		LoaderParams * params;
		GameObject * go;

		string type = object->Attribute("type");
		int x = atoi(object->Attribute("x"));
		int y = atoi(object->Attribute("y"));
		int width = atoi(object->Attribute("width"));
		int height = atoi(object->Attribute("height"));
		if (type == "Button") {
			params = new LoaderParams(
				x,
				y,
				width,
				height,
				atoi(object->Attribute("callbackID"))
			);
		}
		else if (type == "Player" || type == "NPC") {
			params = new LoaderParams(
				object->Attribute("id"),
				x,
				y,
				width,
				height
			);
		}
		else {
			params = new LoaderParams(
				x,
				y,
				width,
				height
			);
		}
		go = GameObjectFactory::getInstance()->CreateGameObject(type);
		go->load(params);
		objects->push_back(go);
	}
}

void StateParser::parseTextures(XMLElement * stateRoot, std::vector<std::string>* textureIDs) {
	for (auto texture = stateRoot->FirstChildElement("TEXTURE");
		texture != NULL;
		texture = texture->NextSiblingElement("TEXTURE")) {
		///////////////////////////////////////
		string filepath = texture->Attribute("path");
		string textureId = texture->Attribute("id");
		TextureManager::getInstance()->load(
			filepath,
			textureId,
			Game::getInstance()->getRenderer()
		);
		textureIDs->push_back(textureId);
	}
	
}
