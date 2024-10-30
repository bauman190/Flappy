#pragma once

#include <ctime>

#include "gameSettings/constants.h"

namespace gamePlayer
{
	enum class PLAYERDIRECTION
	{
		STOP = 1,
		MOVING,
		DERIVA
	};

	struct Player
	{
		Rectangle playerRec;
		Vector2 playerPos;
		float velocity;
		bool matchStart;
	};

	void InitPlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity);

	void UpdatePlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity, bool& matchStart);
	void DrawPlayer(Rectangle playerRec, bool matchStart);
}