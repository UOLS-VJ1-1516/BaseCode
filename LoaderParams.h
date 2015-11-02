#pragma once

#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, const char* textureID, int spriteNum) {
		p_x = x;
		p_y = y;
		p_width = width;
		p_height = height;
		p_textureID = textureID;
		p_num = spriteNum;
	}
	int getX() const { return p_x; }
	int getY() const { return p_y; }
	int getWidth() const { return p_width; }
	int getHeight() const { return p_height; }
	const char* getTextureID() const { return p_textureID; }
	int getNum() const { return p_num; }
private:
	int p_x;
	int p_y;
	int p_width;
	int p_height;
	int p_num;
	const char* p_textureID;
};
#endif