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


	void InitPlayer(Player& player)
	{
		float playerStartPosX = ((screenWidth / 6) * 2);
		float playerStartPosY = ((screenHeight / 6) * 2);

		player.velocity = 0.0f;
		player.gravity = 980.0f;
		player.jumpForce = -450.0f;
		player.radius = 30.0f;

		player.playerPos.x = playerStartPosX;
		player.playerPos.y = playerStartPosY;
		
		player.playerRec.x = player.playerPos.x;
		player.playerRec.y = player.playerPos.y;
		player.playerRec.width = 40.0f;
		player.playerRec.height = 40.0f;
	}

	void UpdatePlayer(Player& player, SCENEMANAGMENT& scene, Rectangle enemyRec, Rectangle enemyRecUp)
	{

		if (IsKeyPressed(KEY_ENTER) || player.matchStart == true)
		{
			player.matchStart = true;

			if (IsKeyPressed(KEY_SPACE))
			{
				player.velocity = player.jumpForce;
				player.isAnimating = !player.isAnimating;
			}

			player.velocity += player.gravity * GetFrameTime();
			player.playerPos.y += player.velocity * GetFrameTime();

			////future sprite updated pos
			player.playerRec.x = player.playerPos.x;
			player.playerRec.y = player.playerPos.y;
			//techo
			if (player.playerPos.y < 0 )
				player.playerPos.y = player.playerRec.height;
			//el suelo resetea
			if (player.playerPos.y > screenHeight)
				scene = SCENEMANAGMENT::NONE;
		}
		bool isCollision = circleRect(player.radius, enemyRec, player.playerPos) || circleRect(player.radius, enemyRecUp, player.playerPos);
		

		if (isCollision == true)
		{
			scene = SCENEMANAGMENT::NONE;
		}
	}

	bool circleRect(float radius, Rectangle enemyRec, Vector2 playerPos)
	{
		// temporary variables to set edges for testing
		float testX = playerPos.x + radius / 2;
		float testY = playerPos.y + radius / 2;

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

	void DrawPlayer(Player player)
	{
		
		if (player.matchStart == false)
		{
			DrawText("Press ENTER to start", 350, 350, 30, LIGHTGRAY);
		}
	}
}

