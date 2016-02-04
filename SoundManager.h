#pragma once
#include <iostream>
#include <map>
#include "SDL_mixer.h"
class SoundManager
{
public:
	static SoundManager* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new SoundManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool loadSound(std::string fileName, std::string id);
	bool loadMusic(std::string fileName, std::string id);
	void playSound(std::string id, int loop);
	void playMusic(std::string id, int loop);
	void stopMusic();
	~SoundManager() {}
private:
	static SoundManager* s_pInstance;
	std::map<std::string, Mix_Chunk*> m_sounds;
	std::map<std::string, Mix_Music*> m_music;
	SoundManager() { 
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	}


};