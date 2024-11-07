#pragma once

#include "entities/player.h"
#include "entities/enemy.h"
#include "entities/mouse.h"
#include "gamePlay/gameMenu.h"
#include "gameSettings/sceneManage.h"
#include "gameSettings/constants.h"

namespace Game
{
	void RunGame();

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy,
		gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse, gameMenu::Menu& credits);
	void Input(SCENEMANAGMENT& scene, gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse, gameMenu::Menu& credits);
	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy,
		 gameMouse::Mouse& mouse);
	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene, gameEnemy::enemyStructure enemy,
		gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse, gameMenu::Menu credits);
	void Close();
}
