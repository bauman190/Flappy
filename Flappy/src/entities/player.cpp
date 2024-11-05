#include "player.h"

#include <iostream>

#include "cmath"

#include "gameSettings/constants.h"
#include "raymath.h"

namespace gamePlayer
{
	//PLAYER settings
	const float playerSpeed = 450.0f;
	const float playerPosX = screenWidth / 2.0f;
	const float playerPosY = screenHeight / 2.0f;


	void InitPlayer(Rectangle& playerRec, Texture2D playerSprite, Rectangle& frameRect, Vector2& playerPos, float& velocity,
		float& radius, float& gravity, float& jumpForce)
	{
		frameRect = { 0.0f, 0.0f, static_cast <float>(playerSprite.width / 6), static_cast<float>(playerSprite.height) };

		float enemyStartPosX = ((screenWidth / 6) * 2);
		float enemyStartPosY = ((screenHeight / 6) * 2);

		velocity = 0.0f;
		gravity = 980.0f;
		jumpForce = -450.0f;
		radius = 30.0f;

		playerPos.x = enemyStartPosX;
		playerPos.y = enemyStartPosY;

		frameRect.x = playerPos.x;
		frameRect.y = playerPos.y;
		playerRec.x = playerPos.x;
		playerRec.y = playerPos.y;
		playerRec.width = 40.0f;
		playerRec.height = 40.0f;
	}

	void UpdatePlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity,
		bool& matchStart, Rectangle enemyRec, float radius, SCENEMANAGMENT& scene,
		float& gravity, float& jumpForce)
	{
		if (IsKeyPressed(KEY_ENTER) || matchStart == true)
		{
			matchStart = true;

			if (IsKeyPressed(KEY_SPACE))
			{
				velocity = jumpForce;
			}
			
			velocity += gravity * GetFrameTime();
			playerPos.y += velocity * GetFrameTime();

			//future sprite updated pos
			playerRec.x = playerPos.x;
			playerRec.y = playerPos.y;
			//techo
			if (playerPos.y < 0 )
				playerPos.y = playerRec.height;
			//el suelo resetea
			if (playerPos.y > screenHeight)
				scene = SCENEMANAGMENT::NONE;

			////chekeo de limites horizontales
			//if (playerPos.x < -playerRec.width)
			//	playerPos.x = screenWidth + playerRec.width;

			//if (playerPos.x > screenWidth)
			//	playerPos.x = -playerRec.width;
			//chekeo de limites verticales
		}

		bool isCollision = circleRect(radius, enemyRec, playerPos);

		if (isCollision == true)
		{
			scene = SCENEMANAGMENT::NONE;
		}
	}

	bool circleRect(float radius, Rectangle enemyRec, Vector2 playerPos)
	{
		// temporary variables to set edges for testing
		float testX = playerPos.x;
		float testY = playerPos.y;

		// which edge is closest?
		if (playerPos.x < enemyRec.x)
			testX = enemyRec.x;      // test left edge

		else if (playerPos.x > enemyRec.x + enemyRec.width)
			testX = enemyRec.x + enemyRec.width;   // right edge

		if (playerPos.y < enemyRec.y)
			testY = enemyRec.y;      // top edge

		else if (playerPos.y > enemyRec.y + enemyRec.height)
			testY = enemyRec.y + enemyRec.height;   // bottom edge

		// get distance from closest edges
		float distX = playerPos.x - testX;
		float distY = playerPos.y - testY;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the radius, collision!
		if (distance <= radius) {
			return true;
		}
		return false;
	}

	void DrawPlayer(Rectangle playerRec, bool matchStart)
	{
		DrawRectangleRec(playerRec, WHITE);

		if (matchStart == false)
		{
			DrawText("Press ENTER to start", 350, 350, 30, LIGHTGRAY);
		}
	}
}

