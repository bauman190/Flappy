#pragma once

#include "entities/player.h"
#include "entities/enemy.h"

#include "gameSettings/sceneManage.h"
#include "gameSettings/constants.h"

namespace Game
{
	void RunGame();

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure enemy);
	//void Input(SCENEMANAGMENT& scene);
	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure enemy);
	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene, gameEnemy::enemyStructure enemy);
	void Close();
}
