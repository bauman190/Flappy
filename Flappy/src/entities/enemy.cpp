#include "enemy.h"

namespace gameEnemy
{
	void InitEnemy(Rectangle& enemyRecDown, Rectangle& enemyRecUp, Vector2& enemyPos, float& velocity)
	{
		float enemyStartPosX = ((screenWidth / 6) * 5);
		float enemyStartPosY = ((screenHeight / 6) * 5);
		
		velocity = 300.0f;

		enemyPos.x = enemyStartPosX;
		enemyPos.y = enemyStartPosY;

		enemyRecDown.x = enemyPos.x;
		enemyRecDown.y = enemyPos.y;
		enemyRecDown.width = 30.0f;
		enemyRecDown.height = 500.0f;

		enemyRecUp.width = 30.0f;
		enemyRecUp.height = enemyRecDown.height;
		enemyRecUp.x = enemyRecDown.x;
		enemyRecUp.y = enemyRecDown.y - (enemyRecDown.height + structureSeparation);
	}

	void UpdateEnemy(Rectangle& enemyRecDown, Rectangle& enemyRecUp, Vector2& enemyPos, float& velocity, bool isGameRunning)
	{
		if (isGameRunning == true)
		{
			//future sprite updated pos
			enemyPos.x -= velocity * GetFrameTime();
			enemyRecDown.x = enemyPos.x;
			//update pilar superior
			enemyRecUp.x = enemyPos.x;
			

			//chekeo de limites horizontales
			//left
			if (enemyPos.x < -enemyRecDown.width)
			{
				enemyPos.x = screenWidth + enemyRecDown.width;
				enemyRecDown.x = enemyPos.x;
				enemyRecUp.x = enemyRecDown.x;
				enemyPos.y = static_cast<float> (GetRandomValue(0 + static_cast<int>(enemyRecDown.height), static_cast<int>(screenHeight - enemyRecDown.height)));
				enemyRecDown.y = enemyPos.y;
				enemyRecUp.y = enemyRecDown.y - (enemyRecDown.height + structureSeparation);
			}
			//left
			//if (enemyPos.y < -enemyRecDown.width)
			//	enemyPos.y = screenWidth + enemyRecDown.width;
			////right
			//if (enemyPos.y > screenHeight)
			//	enemyPos.y = -enemyRecDown.width;
		}
	}

	void DrawEnemy(Rectangle rectangle, Rectangle enemyRecUp)
	{
		DrawRectangleRec(rectangle, LIGHTGRAY);
		DrawRectangleRec(enemyRecUp, LIGHTGRAY);
	}
}