#pragma once
#include <tinyxml.h>
#include <vector>
#define PATH "assets/xml/"

using namespace std;

class Entity;

class StateParser
{
private:
	static void parseObjects(TiXmlElement * stateRoot, vector<Entity *> * entities);
	static void parseTextures(TiXmlElement * stateRoot, vector<string> * textures);
public:
	static bool ParseState(const char * stateFile, string stateID,
		vector<Entity *> * entitats, vector<string> * textures);
};