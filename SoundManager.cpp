#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = 0;

SoundManager::SoundManager() {
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
	Mix_VolumeMusic(35);
}

SoundManager::~SoundManager() {
	SoundManager::stopMusic();
}

bool SoundManager::loadSound(std::string fileName, std::string id) {
	Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
	m_sounds[id] = pChunk;
	return true;
}

bool SoundManager::loadMusic(std::string fileName, std::string id) {
	Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
	m_musics[id] = pMusic;
	return true;
}

void SoundManager::playMusic(std::string id, int loop) {
	Mix_PlayMusic(m_musics[id], loop);
}
void SoundManager::playSound(std::string id, int loop) {
	Mix_PlayChannel(-1, m_sounds[id], loop);
}

void SoundManager::stopMusic() {
	Mix_CloseAudio();
}