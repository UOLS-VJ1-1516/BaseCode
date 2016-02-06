//#include "tinyxml.h"
//#include <iostream>
#include "tinyxml.h"
#include <vector>
//#include "tinystr.h"

#ifndef STATEPARSER_H
#define STATEPARSER_H


class GameObject;
class StateParser
{
public:
	static bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> * pObjects, std::vector<std::string>* pTextureIDs);
private:
	static void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string>* pTextureIDs);
	static void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*>* pObjects);
};
#endif STATEPARSER_H
