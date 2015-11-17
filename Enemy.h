#pragma once
#include "LivingEntity.h"
#include "Player.h"

#define STATIC_ENEMY 0
#define FOLLOWER_ENEMY 1
#define IGNORE_ENEMY 2

class Enemy :
	public LivingEntity
{
private:
	int type = 0;
	void FollowPlayer(Player *);
	void BeStatic(Player *);
	void TheIgnored();
public:
	Enemy(int);
	~Enemy();
	void Update(Player *);
	static Enemy * Create(int type) { return new Enemy(type); }
};
