#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
//#include LoaderParams.h
class GameObject
{
	public:
		//virtual void load(const LoaderParams* pParams) = 0;
		virtual void load(int x, int y, int width, int height, const char* textureID) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;
	protected:
		GameObject();
		virtual ~GameObject();
};
#endif GAMEOBJECT_H
