#include "EntityParams.h"

EntityParams::EntityParams(const char * id, int xPos, int yPos, int width, int height, int maxFrame, int row)
{
	this->id = id;
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
	this->maxFrame = maxFrame;
	this->row = row;
	this->flipped = false;
	this->frame = 0;
}

void EntityParams::AddFrame()
{
	frame++;
	if (frame == maxFrame)
		frame = 0;
}

void EntityParams::AddXPos(int xPos)
{
	this->xPos += xPos;
}