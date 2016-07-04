#pragma once
#include "CollisionObject.h"
#ifndef META_H
#define META_H
class Meta : public CollisionObject
{
public:
	Meta();
	~Meta();

		void draw(SDL_Renderer* lRender);
		void draw();
		void load(const LoadPar* lPar);
		void load(float x, float y, int width, int height,std::string texid);
		void update();
		void clean();
		static GameObject * Create() { return new Meta(); }

 private:
	 const LoadPar * Params;
		};
#endif META_H
