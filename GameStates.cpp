#include "GameStates.h"
#include "Game.h"
#include "StateParser.h"

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
	StateParser::ParseState("game.xml", this->gameID, &entitats, &textures);
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
	for each (Button * var in entitats)
	{
		var->Update();
	}
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
	StateParser::ParseState("menu.xml", this->menuID, &entitats, &textures);
	callbacks[0] = NULL;
	callbacks[1] = ([]() {
		TheGame->GetManager()->ChangeState(new StateGame());
	});

	callbacks[2] = ([]() {
		TheGame->Close();
	});
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
	for each (Button * var in entitats)
	{
		var->Update();
	}
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
	StateParser::ParseState("pause.xml", this->pauseID, &entitats, &textures);

	callbacks[0] = NULL;
	callbacks[1] = ([]() {
		TheGame->GetManager()->PopState();
	});

	callbacks[2] = ([]() {
		TheGame->GetManager()->ChangeState(new StateMenu());
	});

	return true;
}

bool StatePause::OnExit()
{
	return false;
}

