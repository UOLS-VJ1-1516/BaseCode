#include "Player.h"

Player::~Player()
{
}

Player::Player()
{
	xPos = 0;
	yPos = 0;
	frame = 0;
	row = 0;
}

bool Player::IsFlipped()
{
	return flipped;
}

Player::Player(const char * id, int width, int height, int maxFrame, int row) : Player()
{	
	this->textureId = id;
	this->width = width;
	this->height = height;
	this->maxFrame = maxFrame;
	this->row = row;
}

void Player::Move(int pos)
{
	if (pos < 0)
		flipped = true;
	else
		flipped = false;
	frame++;
	if (frame == maxFrame)
		frame = 0;
	xPos += pos;
}

const char * Player::GetId()
{
	return textureId;
}

int Player::GetPos(char value)
{
	int pos;
	switch (value)
	{
	case 'X':
		pos = xPos;
		break;
	case 'Y':
		pos = yPos;
		break;
	}
	return pos;
}

int Player::GetSize(char value)
{
	int size = 0;
	switch (value)
	{
	case 'w':
		size = width;
		break;
	case 'h':
		size = height;
		break;
	}
	return size;
}

void Player::SetPosY(int yPos)
{
	this->yPos = yPos;
}
