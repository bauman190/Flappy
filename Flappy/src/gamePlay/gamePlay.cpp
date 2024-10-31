#include "gamePlay.h"

namespace Game
{
	void RunGame()
	{
		gamePlayer::Player player;
		gameEnemy::enemyStructure enemy{};
		SCENEMANAGMENT scene;
		scene = SCENEMANAGMENT::NONE;

		Init(player, scene, enemy);

		while (!WindowShouldClose())
		{
			//Input(player, scene);
			Update(player, scene, enemy);
			Draw(player, scene, enemy);
		}

		Close();
	}

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " RunGame by Francisco Jonas ");
			scene = SCENEMANAGMENT::GAME;
			gamePlayer::InitPlayer(player.playerRec, player.playerPos, player.velocity);
			gameEnemy::InitEnemy(enemy.enemyRec, enemy.enemyPos, enemy.velocity);

		default:
			break;
		}
	}

	//void Input(SCENEMANAGMENT& scene)
	//{
	//	switch (scene)
	//	{
	//
	//		//for future menu
	//
	//	default:
	//		break;
	//	}
	//}

	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player.playerRec,player.playerPos,player.velocity,player.matchStart);
			gameEnemy::UpdateEnemy(enemy.enemyRec, enemy.enemyPos, enemy.velocity, player.matchStart);
			break;
		
		default:
			break;
		}
	}
	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene, gameEnemy::enemyStructure enemy)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (scene)
		{
	
		case SCENEMANAGMENT::GAME:
			gameEnemy::DrawEnemy(enemy.enemyRec);
			gamePlayer::DrawPlayer(player.playerRec,player.matchStart);
			break;
		
		default:
			break;
		}

		EndDrawing();
	}

	void Close()
	{
		CloseWindow();
	}
}
