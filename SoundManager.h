#pragma once
#include <vector>
#include <map>
#include "SDL_mixer.h"

class SoundManager
{
public:
	static SoundManager* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new SoundManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	~SoundManager();
	bool loadSound(std::string fileName, std::string id);
	bool loadMusic(std::string fileName, std::string id);
	void playSound(std::string id, int loop);
	void playMusic(std::string id, int loop);
	void stopMusic();

private:
	static SoundManager* s_pInstance;
	std::map<std::string, Mix_Chunk*> m_sounds;
	std::map<std::string, Mix_Music*> m_musics;
	SoundManager();
};