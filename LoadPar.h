#pragma once
#ifndef LOADPAR_h
#define LOADPAR_H

class LoadPar {

public:	

	LoadPar(char* id, int x, int y, int width, int height, int currentRow, int currentFrame,int sprits, int flip) {
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_currentFrame = currentFrame;
		m_currentRow = currentRow;
		m_texid = id;
		m_sprits = sprits;
		m_flip = flip;
	}
	int getx() const { return m_x; }
	int gety() const { return m_y; }
	int getwidth() const { return m_width; }
	int getheight() const { return m_height; }
	int getcurrentRow() const { return m_currentRow; }
	int getcurrentFrame() const { return m_currentFrame; }
	int getsprits() const { return m_sprits; }
	int getflip() const { return m_flip; }
	char* gettexid() const { return m_texid; }



private:
	int m_width, m_height, m_currentFrame, m_currentRow, m_x, m_y, m_flip,m_sprits;
	char* m_texid;


};
#endif LOADPAR_H