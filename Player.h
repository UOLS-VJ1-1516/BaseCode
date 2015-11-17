#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	~Player();
	virtual void draw();
	void load(const LoaderParams *pParams);
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Player(); }
private:
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};
