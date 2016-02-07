#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "SoundManager.h"


Game* Game::s_pInstance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	m_screenWidth = 800;
	m_screenHeight = 600;
	ms = new MenuState();
	gsm = new GameStateMachine();
	InputHandler* TheInputHandler;
	TextureManager* TheTextureManager;
	TheTextureManager = TextureManager::Instance();
	TheInputHandler = InputHandler::Instance();
	TheGameObjectFactory = GameObjectFactory::Instance();

	SoundManager::Instance()->load("Outside.wav", "play", SOUND_MUSIC);
	SoundManager::Instance()->load("jump.wav", "jump", SOUND_SFX);
	SoundManager::Instance()->load("Death.wav", "death", SOUND_MUSIC);
	SoundManager::Instance()->load("menu.wav", "menu", SOUND_MUSIC);
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
			SDL_GetWindowSize(g_pWindow, &width, &height);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		m_screenWidth = width;
		m_screenHeight = height;
		SDL_GetWindowSize(g_pWindow, &width, &height);
		
		if (g_pWindow != 0) {
			TheGameObjectFactory->Register("Player", &Player::Create);
			TheGameObjectFactory->Register("Enemy", &Enemy::Create);
			TheGameObjectFactory->Register("StaticObjects", &StaticObjects::Create);
			TheGameObjectFactory->Register("KeyObject", &KeyObject::Create);
			TheGameObjectFactory->Register("MenuButton", &MenuButton::Create);

			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			gsm->pushState(ms);
		}

		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	gsm->render();
	SDL_RenderPresent(g_pRenderer);
}

void Game::update() {
	InputHandler::Instance()->update();
	gsm->update();
}

void Game::handleEvents() {
}

void Game::clean() {
	flag = false;
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return flag;
}

SDL_Renderer* Game::getRender() {
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

int Game::getScreenWidth()
{
	return m_screenWidth;
}

int Game::getScreenHeight()
{
	return m_screenHeight;
}

void Game::setflag(bool b){
	flag = b;
};

GameStateMachine* Game::getGameStateMachine() {
	return gsm;
};

