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
		Texture2D playerSprite; // Texture loading
		Rectangle frameRec;
		int currentFrame = 0;
		int framesCounter = 0;
		int framesSpeed = 8;            // Number of spritesheet frames shown by second

		Rectangle playerRec;
		Vector2 playerPos;
		float velocity;
		float gravity;
		float jumpForce;
		float radius;
		bool matchStart;
	};

<<<<<<< Updated upstream
	void InitPlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity,
		float& radius, float& gravity, float& jumpForce);


=======
	void InitPlayer(Rectangle& playerRec, Texture2D playerSprite, Rectangle& frameRect, Vector2& playerPos, float& velocity,
		float& radius, float& gravity, float& jumpForce);

>>>>>>> Stashed changes
	void UpdatePlayer(Rectangle& playerRec, Vector2& playerPos, float& velocity,
		bool& matchStart, Rectangle enemyRec, float radius,
		SCENEMANAGMENT& scene, float& gravity, float& jumpForce);
	bool circleRect(float radius, Rectangle enemyRec, Vector2 playerPos);
	void DrawPlayer(Rectangle playerRec, bool matchStart);
}