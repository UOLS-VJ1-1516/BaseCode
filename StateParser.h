#pragma once

#include <vector>
#include "tinyxml.h"



class GameObject;
class StateParser
{
public:
	static bool parseState(const char* stateFile, std::string stateID,
		std::vector<GameObject*> * pObjects, std::vector<const char *> * pTextureIDs
		);
private:
	static void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*>
		* pObjects);
	static void parseTextures(TiXmlElement* pStateRoot, std::vector<const char *>
		* pTextureIDs);
};
