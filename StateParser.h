#pragma once
#include "tinyxml2.h"
#include <vector>
class GameObject;

using namespace tinyxml2;
class StateParser {
public:
	static bool parseState(std::string stateFile, std::string stateID,
		std::vector<GameObject*> * pObjects, std::vector<std::string> * pTextureIDs);
private:
	static void parseObjects(XMLElement* pStateRoot, std::vector<GameObject*>* pObjects);
	static void parseTextures(XMLElement* pStateRoot, std::vector<std::string>* pTextureIDs);
};
