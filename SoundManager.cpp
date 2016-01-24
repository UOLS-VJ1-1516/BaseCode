#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = 0;

SoundManager::SoundManager()
{
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{

}
bool SoundManager::load(std::string fileName, std::string id, sound_type type)
{
	if (type == SOUND_MUSIC)
	{
		std::string url = "../audio/" + fileName;
		Mix_Music* pMusic = Mix_LoadMUS(url.c_str());
		if (pMusic == 0)
		{
			std::cout << "Could not load music: ERROR - " << Mix_GetError() << std::endl;
			return false;
		}
		m_music[id] = pMusic;
		return true;
	}
	else if (type == SOUND_SFX)
	{
		std::string url = "../audio/" + fileName;
		Mix_Chunk* pChunk = Mix_LoadWAV(url.c_str());
		if (pChunk == 0)
		{
			std::cout << "Could not load SFX: ERROR - " << Mix_GetError() << std::endl;
			return false;
		}
		m_sfxs[id] = pChunk;
		return true;
	}
	return false;
}
void SoundManager::playSound(std::string id, int loop, int channel)
{
	Mix_PlayChannel(channel, m_sfxs[id], loop);
}
void SoundManager::playMusic(std::string id, int loop)
{
	Mix_PlayMusic(m_music[id], loop);
}
void SoundManager::stopMusic()
{
	Mix_HaltMusic();
}

SoundManager::SoundManager(const SoundManager&)
{
	Mix_CloseAudio();
}