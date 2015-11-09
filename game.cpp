#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"


const int altura = 800;
const int ancho = 800;
Game * Game::s_pInstance = 0;
Game::Game()
{
	g_pWindow = 0;
	g_pRenderer = 0;
	state = false;
}


bool Game::init(const char* tittle, int xPos, int yPos, int typeWindow)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(tittle, xPos, yPos, ancho, altura, 0);
		if (g_pWindow != 0) g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		state = true;

		GameObject *Player23 = new Player2();
		Player23->load(new LoaderParams(300, 310, "dragon", 1, 8, 0, *(new Vector2D(0, 10)), *(new Vector2D(3, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

		m_gameObjects.push_back(Player23);
		TextureManager::Instance()->load("dragon.bmp", "dragon", g_pRenderer);

		GameObject *Player24 = new Player2();
		Player24->load(new LoaderParams(125, 100, "vulture", 1, 6, 0, *(new Vector2D(50, 300)), *(new Vector2D(8, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

		m_gameObjects.push_back(Player24);
		TextureManager::Instance()->load("vulture_sprites.bmp", "vulture", g_pRenderer);

		GameObject *player = new Player();
		player->load(new LoaderParams(116, 200, "player", 1, 6, 0, *(new Vector2D(300, 500)), *(new Vector2D(0, 0)), *(new Vector2D(18, 0)), *(new Vector2D(4, 0)), *(new Vector2D(4, 0))));

		m_gameObjects.push_back(player);
		TextureManager::Instance()->load("player1.bmp", "player", g_pRenderer);

		return 0;

	}
	return 1;
}

void Game::render()
{
	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(g_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(g_pRenderer);
}

void Game::update(int delay)
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}


}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			InputHandler::Instance()->update(event.key.keysym.sym);
		}
		if (event.type == SDL_KEYUP) {
			if (event.key.keysym.sym == SDLK_ESCAPE) { state = false; break; }
			InputHandler::Instance()->updateKeyUp(event.key.keysym.sym);
		}
	}
}

void Game::clean()
{
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}


bool Game::isRunning()
{
	return state;
}


int Game::getTicks() { return (int)(SDL_GetTicks()); };

const int Game::get_ancho_ventana() const
{
	return ancho;
}