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
		Rectangle frameRec = { 0.0f,0.0f,0.0f,0.0f };
		int currentFrame = 0;
		int framesCounter = 0;
		int framesSpeed = 8;            // Number of spritesheet frames shown by second

		Rectangle playerRec{ 0.0f,0.0f,0.0f,0.0f };
		Vector2 playerPos = { 0.0f,0.0f };
		float velocity;
		float gravity;
		float jumpForce;
		float radius;
		bool matchStart;
	};
	void InitPlayer(Player& player);
	void UpdatePlayer(Player& player, SCENEMANAGMENT& scene, Rectangle enemyRec);
	bool circleRect(float radius, Rectangle enemyRec, Vector2 playerPos);
	void DrawPlayer(Rectangle playerRec, bool matchStart);
}