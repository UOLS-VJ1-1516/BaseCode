#include "StateParser.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "MenuButton.h"
#include "Player.h"
#include "NPC.h"
#include "TextureManager.h"
#include "game.h"
#include "GameObjectFactory.h"

#include <iostream>

using namespace std;

bool StateParser::parseState(string stateFile, std::string stateID, std::vector<GameObject*>* objects, std::vector<std::string>* textureIDs) {
	XMLDocument xml;
	xml.LoadFile(stateFile.c_str());
	if (xml.Error()) {
		cout << "XML ERROR: " << endl << xml.ErrorName() << endl;
		return false;
	}
	XMLElement * state = (xml.FirstChildElement("STATES"))->FirstChildElement(stateID.c_str());
	StateParser::parseObjects(state->FirstChildElement("GAMEOBJECTS"), objects);
	StateParser::parseTextures(state->FirstChildElement("TEXTURES"), textureIDs);
	return true;
}

void StateParser::parseObjects(XMLElement * stateRoot, std::vector<GameObject*>* objects) {
	for (auto object = stateRoot->FirstChildElement("GAMEOBJECT");
		object != NULL;
		object = object->NextSiblingElement("GAMEOBJECT")) {
		LoaderParams * params;
		string type;
		GameObject * go = GameObjectFactory::getInstance()->CreateGameObject(type = object->Attribute("type"));

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
			((MenuButton*)go)->setTexture(
				((string)object->Attribute("textureID")),
				atoi(object->Attribute("textureCols")),
				atoi(object->Attribute("textureRows"))
			);
		}
		else if (type == "NPC") {
			params = new LoaderParams(
				object->Attribute("id"),
				x,
				y,
				width,
				height
			);
			((NPC*)go)->setTexture(
				((string)object->Attribute("textureID")),
				atoi(object->Attribute("textureCols")),
				atoi(object->Attribute("textureRows"))
			);
		} else if (type == "Player") {	
			params = new LoaderParams(
				object->Attribute("id"),
				x,
				y,
				width,
				height
			);
			((Player*)go)->setTexture(
				((string)object->Attribute("textureID")),
				atoi(object->Attribute("textureCols")),
				atoi(object->Attribute("textureRows"))
			);
		} else {
			params = new LoaderParams(
				x,
				y,
				width,
				height
			);
		}

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
