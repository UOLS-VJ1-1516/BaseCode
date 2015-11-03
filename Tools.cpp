#include "Tools.h"
#include "SDL.h"
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include "Game.h"

using namespace std;
double lastFrame = GetTime();

void takeScreenShot(int width, int height)
{
	chrono::time_point<std::chrono::system_clock> now = chrono::system_clock::now();
	time_t time_ = chrono::system_clock::to_time_t(now);

	string str;
	str.append(to_string((int)time(&time_)));
	str.append(".png");

	cout << str << endl;

	SDL_Surface * sshot = SDL_CreateRGBSurface(0, width, height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(Game::GetInstance()->GetRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	IMG_SavePNG(sshot, str.c_str());
	SDL_FreeSurface(sshot);
}

double GetDeltaTime()
{
	long currentTime = GetTime();
	double delta = ((double)currentTime - lastFrame) / 1000;
	lastFrame = GetTime();
	return delta;
}

long GetTime()
{
	return SDL_GetTicks() * 1000;
}