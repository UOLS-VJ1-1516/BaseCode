#include "GameStates.h"
#include "Game.h"
#include "StateParser.h"

using namespace std;

void StateGame::Update()
{
	for each (LivingEntity * var in entitats)
	{
		if ((var->GetYPos() + var->GetHeight()) < Tools::GetHeight())
		{
			var->yAccel = POSITIVE;
		}
		else
		{
			var->yAccel = NULL;
		}
		
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
	map<int, int> keys = EventHandler::GetInstance()->GetKeyEvents();
	for each (auto key in keys)
	{
		if (key.second == DOWN)
		{
			cout << key.first;			

			if (key.first == 4)
			{
				player->xAccel = NEGATIVE;
			}
			else if (key.first == 7)
			{
				player->xAccel = POSITIVE;
			}
			else if (key.first == 41)
			{
				TheGame->GetManager()->PushState(new StatePause());
			}
			else if (key.first == 44 && player->GetYPos() != Tools::GetHeight())
			{
				player->Jump();
			}
		}
		else if (key.second == UP)
		{
			if (key.first == 4 || key.first == 7)
			{
				player->xAccel = NULL;
			}
		}		
	}
}

bool StateGame::OnEnter()
{
	StateParser::ParseState("game.xml", this->gameID, &entitats, &textures);
	for each (LivingEntity * var in entitats)
	{
		if (Player * pl = dynamic_cast<Player *>(var))
		{
			player = pl;
		}
	}
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
	callbacks.push_back(NULL);
	callbacks.push_back(
		([]() {
			TheGame->GetManager()->ChangeState(new StateGame());
		})
	);

	callbacks.push_back(
		([]() {
			TheGame->Close();
		})
	);

	for each (Button * var in entitats)
	{
		var->SetOnClickListener(callbacks.at(var->CallbackID));
	}
	return true;
}

bool StateMenu::OnExit()
{
	callbacks.clear();
	entitats.clear();
	textures.clear();
	return true;
}

StatePause::StatePause()
{
	
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
	map<int, int> keys = EventHandler::GetInstance()->GetKeyEvents();
	for each (auto var in keys)
	{
		if (var.second == DOWN)
		{
			if (var.first == 41)
			{
				TheGame->GetManager()->PopState();
			}
		}
	}
}

bool StatePause::OnEnter()
{
	StateParser::ParseState("pause.xml", this->pauseID, &entitats, &textures);

	callbacks.push_back(NULL);
	callbacks.push_back(
		([]() {
			TheGame->GetManager()->PopState();
		})
	);

	callbacks.push_back(
		([]() {
			TheGame->GetManager()->ChangeState(new StateMenu());
		})
	);

	for each (Button * var in entitats)
	{
		var->SetOnClickListener(callbacks.at(var->CallbackID));
	}
	return true;
}

bool StatePause::OnExit()
{
	callbacks.clear();
	entitats.clear();
	textures.clear();
	return true;
}

void StateIntro::Update()
{
}

void StateIntro::Render()
{
	for each (InertEntity * var in entitats)
	{
		var->Draw();
	}

	SDL_Delay(2000);
	OnExit();
}

void StateIntro::HandleEvents()
{
}

bool StateIntro::OnEnter()
{
	StateParser::ParseState("intro.xml", GetStateID(), &entitats, &textures);
	return true;
}

bool StateIntro::OnExit()
{
	TheGame->GetManager()->ChangeState(new StateMenu());
	return true;
}
