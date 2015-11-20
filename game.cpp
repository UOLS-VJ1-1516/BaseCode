#include "game.h"
#include "Player.h"
#include "NPC.h"

Game * Game::instance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
}

Game::~Game() {}

SDL_Renderer * Game::getRenderer() {
	return m_pRenderer;
}

SDL_Window * Game::getWindow()
{
	return m_pWindow;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, alpha);
		}
	}
	else {
		return false; // sdl could not initialize
	}
	running = true;
	//LoaderParams loaderparams(,,,)
	//player->load(new LoaderParams(100, 200, 50, 90, "img_player"));
	//OBJECTS
	GameObject* player = new Player("player");
	player->load(new LoaderParams(
		(SDL_GetWindowSurface(m_pWindow)->w / 2),
		(SDL_GetWindowSurface(m_pWindow)->h / 2),
		128 / 4,
		48
	));
	((Player*) player)->setTexture("img_player", "assets/images/player_allmove.png", 4, 1);

	GameObject* npc1 = new NPC("princess");
	npc1->load(new LoaderParams(
		(SDL_GetWindowSurface(m_pWindow)->w / 2) - (128/4),
		((SDL_GetWindowSurface(m_pWindow)->h / 3)*2),
		128 / 4,
		196 / 4
	));
	((NPC*)npc1)->setTexture("img_princess", "assets/images/princess_allmove.png", 4, 4);

	GameObject* npc2 = new NPC("npc");
	npc2->load(new LoaderParams(
		(SDL_GetWindowSurface(m_pWindow)->w) - ((128 / 4)*2),
		(SDL_GetWindowSurface(m_pWindow)->h / 3),
		128 / 4,
		196 / 4
	));
	((NPC*)npc2)->setTexture("img_npc", "assets/images/guy_allmove.png", 4, 4);

	gameObjects.push_back(player);
	gameObjects.push_back(npc1);
	gameObjects.push_back(npc2);
	//TEXTURES
	TextureManager* tManager = TextureManager::getInstance();
	tManager->load(((Player*)player)->getTexturePath(), ((Player*)player)->getTextureId(), m_pRenderer);
	tManager->load(((NPC*)npc1)->getTexturePath(), ((NPC*)npc1)->getTextureId(), m_pRenderer);
	tManager->load(((NPC*)npc2)->getTexturePath(), ((NPC*)npc2)->getTextureId(), m_pRenderer);

	return true;
}

void Game::render() {
	// clear the window to black
	SDL_RenderClear(m_pRenderer);
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->draw();
	}

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	//OBJECTS
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
	}

	//BACKGROUND COLOR

	//RED
	if (red < maxColorValue && green == 0 && blue == 0 || red < maxColorValue && green == 0 && blue == maxColorValue) {
		red++;
	}
	else {
		if (red > 0 && green == maxColorValue && blue == 0) red--;
	}
	//GREEN
	if (red == maxColorValue && green < maxColorValue && blue == 0) {
		green++;
	}
	else {
		if (red == 0 && green > 0 && blue == maxColorValue) green--;
	}
	//BLUE
	if (red == 0 && green == maxColorValue && blue < maxColorValue) {
		blue++;
	}
	else {
		if (red == maxColorValue && green == 0 && blue > 0) blue--;
	}
	SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, alpha);
}

void Game::handleEvents() {
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		//OBJECTS
		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->handleEvents(event);
		}

		//INTERFACE
			//EXIT
		if (event.type == SDL_KEYUP && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			running = false;
		}
	}
}

void Game::clean() {
	gameObjects.clear();
	SDL_Quit();
}

bool Game::isRunning() { return running; }