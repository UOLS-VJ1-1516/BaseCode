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
};
