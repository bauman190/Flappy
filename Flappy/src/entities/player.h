#pragma once

#include <ctime>

#include "gameSettings/constants.h"
#include "gameSettings/sceneManage.h"

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
		float gravity;
		float jumpForce;
		float radius;
		bool matchStart;
	};

	void InitPlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity,
		float& radius, float& gravity, float& jumpForce);


	void UpdatePlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity,
		bool& matchStart, Rectangle enemyRec, float radius,
		SCENEMANAGMENT& scene, float& gravity, float& jumpForce);
	bool circleRect(float radius, Rectangle enemyRec, Vector2 playerPos);
	void DrawPlayer(Rectangle playerRec, bool matchStart);
}