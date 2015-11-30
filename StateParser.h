#pragma once

#include "tinyxml.h"
#include <iostream>
#include <vector>

typedef std::string string;

class GameObject;
class StateParser
{
public:
	static bool parseState(const char* stateFile, string stateID,
		std::vector<GameObject*> * pObjects, std::vector<string> * pTextureIDs);
private:
	static void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*>	* pObjects);
	static void parseTextures(TiXmlElement* pStateRoot, std::vector<string> * pTextureIDs);
};

