#pragma once
#include "tinyxml.h"
#include <vector>

class GameObject;
class StateParser
{
public:
	static bool parseState(const char* stateFile, std::string stateID,
		std::vector<GameObject*> * pObjects, std::vector<std::string> * pTextureIDs
		);
private:
	static void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*>
		* pObjects);
	static void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string>
		* pTextureIDs);
};