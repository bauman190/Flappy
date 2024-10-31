#include "enemy.h"

namespace gameEnemy
{
	void InitEnemy(Rectangle& enemyRec, Vector2& enemyPos, float& velocity)
	{
		float enemyStartPosX = ((screenWidth / 6) * 5);
		float enemyStartPosY = ((screenHeight / 6) * 5);

		velocity = 300.0f;

		enemyPos.x = enemyStartPosX;
		enemyPos.y = enemyStartPosY;

		enemyRec.x = enemyPos.x;
		enemyRec.y = enemyPos.y;
		enemyRec.width = 30.0f;
		enemyRec.height = 250.0f;
	}

	void UpdateEnemy(Rectangle& enemyRec, Vector2& enemyPos, float& velocity, bool isGameRunning)
	{
		if (isGameRunning == true)
		{
			//future sprite updated pos
			enemyPos.x -= velocity * GetFrameTime();
			enemyRec.x = enemyPos.x;

			//chekeo de limites horizontales
			//left
			if (enemyPos.x < -enemyRec.width)
			{
				enemyPos.x = screenWidth + enemyRec.width;
				enemyRec.x = enemyPos.x;
				enemyPos.y = static_cast<float> (GetRandomValue(0 + static_cast<int>(enemyRec.height), static_cast<int>(screenHeight - enemyRec.height)));
				enemyRec.y = enemyPos.y;
			}
			//right
			/*if (enemyPos.x > screenWidth)
				enemyPos.x = -enemyRec.width;*/
			//chekeo de limites verticales
			//left
			if (enemyPos.y < -enemyRec.width)
				enemyPos.y = screenWidth + enemyRec.width;
			//right
			if (enemyPos.y > screenHeight)
				enemyPos.y = -enemyRec.width;
		}
	}

	void DrawEnemy(Rectangle rectangle)
	{
		DrawRectangleRec(rectangle, LIGHTGRAY);
	}
}