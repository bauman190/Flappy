#pragma once

#include "entities/player.h"

#include "gameSettings/sceneManage.h"
#include "gameSettings/constants.h"

namespace Game
{
	void RunGame();

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene);
	void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene);
	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene);
	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene);
	void Close();
}
