#include "Tools.h"

using namespace std;

void takeScreenShot(int width, int height, SDL_Renderer * renderer)
{
	chrono::time_point<std::chrono::system_clock> now = chrono::system_clock::now();
	time_t time_ = chrono::system_clock::to_time_t(now);

	string str;
	str.append(to_string((int)time(&time_)));
	str.append(".png");

	cout << str << endl;

	SDL_Surface * sshot = SDL_CreateRGBSurface(0, width, height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	SDL_SaveBMP(sshot, str.c_str());
	SDL_FreeSurface(sshot);
}