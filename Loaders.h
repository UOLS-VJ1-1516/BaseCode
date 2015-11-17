#pragma once
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include "AllEntities.hpp"

#define Manager TextureManager::GetInstance()
#define EntityCreator EntityFactory::GetInstance()
#define NULL 0

class TextureManager
{
private:
	TextureManager();
	std::map<const char*, SDL_Texture *> textures;
	static TextureManager * instancia;
	const char * ASSETS_FOLDER = "assets/";
	const char * IMG_FOLDER = "img/";
public:	
	static TextureManager * GetInstance()
	{
		if (instancia == NULL)
		{
			instancia = new TextureManager();
		}
		return instancia;
	}
	
	bool Load(const char* filename, const char* id);
	std::map<const char *, SDL_Texture *> GetArray() {
		return textures;
	};
	~TextureManager();
};

typedef Entity* (*CreateEntity)();

class EntityFactory
{
private:
	EntityFactory();
	static EntityFactory * instance;
	map<string, CreateEntity> factoryMap;
public:
	virtual ~EntityFactory() {}
	static EntityFactory * GetInstance()
	{
		if (instance == NULL)
		{
			instance = new EntityFactory();
		}
		return instance;
	}
	void Register(const string &, CreateEntity creator);
	Entity * CreateEntity(const string &);
};