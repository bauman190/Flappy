#pragma once

#include "raylib.h"
#include "raymath.h"
#include "ctime"


#include "player.h"
#include "gameSettings/constants.h"

namespace gameEnemy
{
	struct enemyStructure
	{
		Rectangle enemyRecDown;
		Rectangle enemyRecUp;
		Vector2 enemyPos;
		float velocity;
	};

	void InitEnemy(Rectangle& enemyRec, Rectangle& enemyRecUp, Vector2& enemyPos, float& velocity);
	void UpdateEnemy(Rectangle& enemyRec, Rectangle& enemyRecUp, Vector2& enemyPos, float& velocity, bool isGameRunning);
	void DrawEnemy(Rectangle enemyRec, Rectangle enemyRecUp);
}