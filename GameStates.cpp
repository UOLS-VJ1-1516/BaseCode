#include "GameStates.h"
#include "Game.h"

using namespace std;

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
	map<string, int> keys = EventHandler::GetInstance()->GetKeyEvents();
	for each (auto key in keys)
	{
		if (key.second == DOWN)
		{
			if (key.first == "4")
			{
				player->xAccel = NEGATIVE;
			}
			else if (key.first == "7")
			{
				player->xAccel = POSITIVE;
			}
			else if (key.first == "41")
			{
				TheGame->GetManager()->PushState(new StatePause());
			}
		}
		else if (key.second == UP)
		{
			if (key.first == "4" || key.first == "7")
			{
				player->xAccel = NULL;
			}
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
	play->Update();
	exit->Update();
}

void StateMenu::Render()
{
	for each (Button * var in entitats)
	{		
		var->Draw();
	}
}

void StateMenu::HandleEvents()
{
	
}

bool StateMenu::OnEnter()
{
	EntityParams * playParams = new EntityParams
		("playButton", 100, 100, 400, 150, 0, 0);

	EntityParams * exitParams = new EntityParams
		("exitButton", 100, 300, 400, 150, 0, 0);

	play = new Button();
	exit = new Button();

	play->Load(playParams, "startButton.png");
	exit->Load(exitParams, "exitButton.png");

	play->SetOnClickListener([]() {
		TheGame->GetManager()->ChangeState(new StateGame());
	});

	exit->SetOnClickListener([]() {
		TheGame->Close();
	});

	entitats.push_back(play);
	entitats.push_back(exit);

	return true;
}

bool StateMenu::OnExit()
{
	return true;
}

StatePause::StatePause()
{
	OnEnter();
}

void StatePause::Update()
{
	restore->Update();
	exit->Update();
}

void StatePause::Render()
{
	for each (Button * var in entitats)
	{
		var->Draw();
	}
}

void StatePause::HandleEvents()
{
	map<string, int> keys = EventHandler::GetInstance()->GetKeyEvents();
	for each (auto var in keys)
	{
		if (var.second == DOWN)
		{
			if (var.first == "41")
			{
				TheGame->GetManager()->PopState();
			}
		}
	}
}

bool StatePause::OnEnter()
{
	EntityParams * playParams = new EntityParams
		("playButton", 100, 100, 400, 150, 0, 0);

	EntityParams * exitParams = new EntityParams
		("exitButton", 100, 300, 400, 150, 0, 0);

	restore = new Button();
	exit = new Button();

	restore->Load(playParams, "restoreButton.png");
	exit->Load(exitParams, "exitButton.png");

	restore->SetOnClickListener([]() {
		TheGame->GetManager()->PopState();
	});

	exit->SetOnClickListener([]() {
		TheGame->GetManager()->ChangeState(new StateMenu());
	});

	entitats.push_back(restore);
	entitats.push_back(exit);

	return true;
}

bool StatePause::OnExit()
{
	return false;
}

