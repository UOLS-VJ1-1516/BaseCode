#include "Loaders.h"
#include "Game.h"
#include <string>
#include <sstream>

using namespace std;

TextureManager * TextureManager::instancia = 0;

bool TextureManager::Load(const char * filename, const char * id)
{
	stringstream ss;
	ss << ASSETS_FOLDER << IMG_FOLDER << filename;
	string file;
	ss >> file;
	SDL_Surface * surface = IMG_Load(file.c_str());
	SDL_Texture * textura = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surface);
	SDL_FreeSurface(surface);
	textures[id] = textura;
	if (textura == NULL) {	   
		printf("Error al carregar la textura %s.", file.c_str());
		return false;
	}
	return true;
}

TextureManager::TextureManager()
{
	instancia = 0;
}

TextureManager::~TextureManager()
{
	instancia = NULL;
	textures.~map();
}


void EntityFactory::Register(const string & name, CreateNewEntity creator)
{
	factoryMap[name] = creator;
}

Entity * EntityFactory::CreateEntity(const string & name)
{
	Entity * ent = factoryMap[name]();
	return ent;
}
