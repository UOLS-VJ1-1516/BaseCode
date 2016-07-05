#pragma once
#include "GameObject.h"
class ImageSimple: public GameObject
{

public:
	ImageSimple();
	~ImageSimple();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	static GameObject * Create() { return new ImageSimple(); }
protected:
	const LoaderParams *pParams;
};

