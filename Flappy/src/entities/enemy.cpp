#include "enemy.h"

namespace gameEnemy
{


	void InitEnemy(Rectangle& enemyRec, Vector2& enemyPos, float& velocity)
	{
		float enemyStartPosX = ((screenWidth / 6) * 5);
		float enemyStartPosY = ((screenHeight / 6) * 5);

		velocity = 200.0f;

		enemyPos.x = enemyStartPosX;
		enemyPos.y = enemyStartPosY;

		enemyRec.x = enemyPos.x;
		enemyRec.y = enemyPos.y;
		enemyRec.width = 50.0f;
		enemyRec.height = 150.0f;
	}

	void UpdateEnemy(Rectangle& enemyRec, Vector2& enemyPos, float& velocity, bool isGameRunning)
	{
		if (isGameRunning)
		{
			//future sprite updated pos
			enemyPos.x += GetFrameTime() * velocity;
			enemyPos.y += GetFrameTime() * velocity;

			//chekeo de limites horizontales
			//left
			if (enemyPos.x < -enemyRec.width)
			{
				enemyPos.x = screenWidth + enemyRec.width;
				enemyPos.y = static_cast<float> (GetRandomValue(0, static_cast<int>(screenHeight)));
			}
			//right
			if (enemyPos.x > screenWidth + enemyRec.width)
				enemyPos.x = -enemyRec.width;
			//chekeo de limites verticales
			//left
			if (enemyPos.y < -enemyRec.width)
				enemyPos.y = screenWidth + enemyRec.width;
			//right
			if (enemyPos.y > screenHeight + enemyRec.width)
				enemyPos.y = -enemyRec.width;
		}
	}
	void DrawEnemy(Rectangle rectangle, Vector2& enemyPos)
	{
		DrawRectangleRec(rectangle, WHITE);

		if (enemyPos.x < rectangle.width)
		{
			DrawRectangleRec(rectangle, WHITE);
		}
	}

	float GetMousePosRespectFromPlayer(Rectangle rectangle, Vector2 mouse, int index)
	{
		float dx = mouse.x - rectangle.x;
		float dy = mouse.y - rectangle.y;

		//angulo(?) en radianes
		float theta = static_cast <float>(atan2(dy, dx));

		//Convierto el ángulo a grados
		float thetaGrados = theta * (180.0f / PI);

		return thetaGrados;
	}
}