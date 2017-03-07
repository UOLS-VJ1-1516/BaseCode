#pragma once
#include "SDL.h"
 
class Player
{
private:
	const char * textureId;
	int xPos, yPos;
	int width, height;
	int frame;
	int maxFrame;
	bool flipped = false;
	int row;
public:
	Player();
	Player(const char *, int, int, int maxFrame = 0, int row = 0);
	~Player();
	void Move(int);
	const char * GetId();
	int GetPos(char);
	int GetSize(char);
	void SetPosY(int);
	bool IsFlipped();
	bool HaveAnimation() { return maxFrame > 1; }
	int GetFrame() { return frame; }
	int GetRow() { return row; }
};