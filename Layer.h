#pragma once
#ifndef LAYER_H
#define LAYER_H
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};
class Layer
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
protected:
	virtual ~Layer() {}
};
#endif