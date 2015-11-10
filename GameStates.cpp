#include "GameStates.h"
#include "Game.h"

using namespace std;

void StateGame::HandleKeys(SDL_Scancode code)
{
	switch (code)
	{
	case SDL_SCANCODE_ESCAPE:
		break;
	case SDL_SCANCODE_A:
		player->xAccel = NEGATIVE;
		break;
	case SDL_SCANCODE_D:
		player->xAccel = POSITIVE;
		break;
	}
}

void StateGame::Update()
{
	for each (LivingEntity * var in entitats)
	{
		if (Enemy * en = dynamic_cast<Enemy *>(var)) {
			en->Update(player);
		}
		var->Update();
	}
}

void StateGame::Render()
{
	for each (LivingEntity * var in entitats)
	{
		if (var->HaveAnimation())
			var->DrawFrame();
		else
			var->Draw();
	}
}

void StateGame::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (&event == NULL)
			return;
		switch (event.type) {
		case SDL_KEYDOWN:
			HandleKeys(event.key.keysym.scancode);
			break;
		case SDL_KEYUP:
			SDL_Scancode code = event.key.keysym.scancode;
			if (code == SDL_SCANCODE_A || code == SDL_SCANCODE_D)
			{
				player->xAccel = NULL;
			}
			break;
		}
	}
}

bool StateGame::OnEnter()
{
	player = new Player();
	EntityParams * params = new EntityParams("player", 0, 0, 32, 32, 3, 6);
	player->Load(params, "Actor3.png");
	entitats.push_back(player);

	Enemy * enemy1 = new Enemy(IGNORE_ENEMY);
	EntityParams * enemy1Params = new EntityParams("enemy1", 150, 135, 32, 32, 3, 6);
	enemy1->Load(enemy1Params, "Monster1.png");
	entitats.push_back(enemy1);

	Enemy * enemy2 = new Enemy(FOLLOWER_ENEMY);
	EntityParams * enemy2Params = new EntityParams("enemy2", 150, 75, 32, 32, 3, 2);
	enemy2->Load(enemy2Params, "Monster1.png");
	entitats.push_back(enemy2);

	return true;
}

bool StateGame::OnExit()
{
	return true;
}

StateMenu::StateMenu()
{

}

void StateMenu::Update()
{

}

void StateMenu::Render()
{
	play.Draw();
	exit.Draw();
}

void StateMenu::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			play.Check();
		}
	}
}

bool StateMenu::OnEnter()
{
	EntityParams * playParams = new EntityParams
		("playButton", 100, 100, 150, 150, 0, 0);

	EntityParams * exitParams = new EntityParams
		("exitButton", 100, 100, 150, 150, 0, 0);

	play.Load(playParams, "playButton.png");
	exit.Load(exitParams, "exitButton.png");

	play.SetOnClickListener([]() {
		TheGame->GetManager()->ChangeState(new StateGame());
	});

	exit.SetOnClickListener([]() {
		TheGame->Close();
	});

	return true;
}

bool StateMenu::OnExit()
{
	return true;
}