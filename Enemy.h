#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	void draw();
	void load(const LoaderParams *pParams);
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Player(); }
private: 
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};
