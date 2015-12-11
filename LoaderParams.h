#pragma once
#include <iostream>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height) {}
	LoaderParams(std::string id, int x, int y, int width, int height) : id(id), m_x(x), m_y(y), m_width(width), m_height(height) {}
	LoaderParams(int x, int y, int width, int height, void(*callback)() ): m_x(x), m_y(y), m_width(width), m_height(height), f_callback(callback){}
	LoaderParams(int x, int y, int width, int height, int callbackID) : m_x(x), m_y(y), m_width(width), m_height(height), callbackID(callbackID) {}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getId() const { return id; }
	int getCallbackID() const { return callbackID; }
	void(*f_callback)();

private:
	int m_x, m_y, m_width, m_height, callbackID;
	std::string id;
	
};