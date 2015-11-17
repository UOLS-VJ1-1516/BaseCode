#include "StateParser.h"
#include "Loaders.h"
#include "AllEntities.hpp"

void StateParser::parseObjects(TiXmlElement * stateRoot, vector<Entity*>* entities)
{
	string type = stateRoot->Attribute("type");
	string id = stateRoot->Attribute("texture");

	int x = atoi(stateRoot->Attribute("x"));
	int y = atoi(stateRoot->Attribute("y"));
	int width = atoi(stateRoot->Attribute("width"));
	int height = atoi(stateRoot->Attribute("height"));
	int numFrames = atoi(stateRoot->Attribute("numFrames"));
	int row = atoi(stateRoot->Attribute("row"));

	int callback = atoi(stateRoot->Attribute("callback"));

	Entity * ent = EntityCreator->CreateEntity(type);
	if (dynamic_cast<Button *>(ent) && callback > 0)
	{
		dynamic_cast<Button *>(ent)->CallbackID = callback;
	}
	EntityParams * params = new EntityParams(id.c_str(), x, y, width, height, numFrames, row);
	ent->Load(params);
}

void StateParser::parseTextures(TiXmlElement * stateRoot, vector<string>* textures)
{
	string file = stateRoot->Attribute("file");
	string id = stateRoot->Attribute("ID");
	Manager->Load(file.c_str(), id.c_str());
	textures->push_back(id);
}

bool StateParser::ParseState(const char * stateFile, string stateID, vector<Entity*>* entitats, vector<string>* textures)
{
	TiXmlDocument doc;
	string path = PATH;
	path.append(stateFile);
	doc.Parse(path.c_str());

	TiXmlElement * state = doc.FirstChildElement("state");
	TiXmlElement * tex = state->FirstChildElement("textures");
	for (auto e = tex->FirstChildElement("textura"); 
	e != NULL; e = e->NextSiblingElement("textura"))
	{
		parseTextures(e, textures);
	}

	TiXmlElement * obj = state->FirstChildElement("objects");
	for (auto e = obj->FirstChildElement("object");
	e != NULL; e = e->NextSiblingElement("object"))
	{
		parseObjects(e, entitats);
	}
}
