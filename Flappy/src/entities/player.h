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
		Texture2D playertexture;
		Rectangle playerRec = { 0, 0, 0, 0 }; 
		float frameTime = 0.1f;
		float timer = 0.0f;
		bool isAnimating = false; 

		Vector2 playerPos = { 0.0f,0.0f };
		float velocity;
		float gravity;
		float jumpForce;
		float radius;
		bool matchStart = false;
	};
	void InitPlayer(Player& player);
	void UpdatePlayer(Player& player, SCENEMANAGMENT& scene, Rectangle enemyRec, Rectangle enemyRecUp);
	bool circleRect(float radius, Rectangle enemyRec, Vector2 playerPos);
	void DrawPlayer(Player player);
}