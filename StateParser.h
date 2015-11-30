#pragma once
#include <iostream>
#include <tinyxml2.h>
#include <vector>
#include <sstream>

#define XMLPath "Externo/"

using namespace tinyxml2;

class GameObject;

class StateParser{

public:
	static bool parseState(const char* stateFile, std::string stateID,
		std::vector<GameObject*> * pObjects, std::vector<std::string> * pTextureIDs
		);
private:
	static void parseObjects(XMLElement* pStateRoot, std::vector<GameObject*>* pObjects);
	
	static void parseTextures(XMLElement* pStateRoot, std::vector<std::string>* pTextureIDs);
};
