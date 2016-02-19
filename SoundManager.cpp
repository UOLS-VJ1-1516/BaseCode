#include "SoundManager.h"

SoundManager *SoundManager::s_pInstance = 0;

bool SoundManager::loadMusic(std::string fileName, std::string id) {
	Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
	if (pMusic == 0) {
		return false;
	}
	m_music[id] = pMusic;
	return true;
}

bool SoundManager::loadSound(std::string fileName, std::string id) {
	Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
	if (pChunk == 0) {
		return false;
	}
	m_sounds[id] = pChunk;
	return true;
}

void SoundManager::playMusic(std::string id, int loop) {
	Mix_PlayMusic(m_music[id], loop);
}

void SoundManager::playSound(std::string id, int loop) {
	Mix_PlayChannel(-1, m_sounds[id], loop);
}
void SoundManager::stopMusic() {
	Mix_HaltMusic();
}