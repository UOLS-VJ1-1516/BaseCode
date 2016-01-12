#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	virtual void draw();
	virtual void load(const LoaderParams *pParams);
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Enemy(); }
private: 
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};
