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

		UnloadTexture(player.playerSprite);

		Close();
	}

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			player.currentFrame = 0;
			player.framesCounter = 0;
			player.framesSpeed = 8;
			player.playerSprite = LoadTexture("Flappy/res/Meow-Knight_Jump.png");
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " Francisco Jonas Flappy v0.1 ");
			scene = SCENEMANAGMENT::GAME;
<<<<<<< Updated upstream
			gamePlayer::InitPlayer(player.playerRec, player.playerPos, player.velocity, player.radius,player.gravity,player.jumpForce);
=======
			gamePlayer::InitPlayer(player.playerRec, player.playerSprite, player.frameRec, player.playerPos, player.velocity, player.radius, player.gravity, player.jumpForce);
>>>>>>> Stashed changes
			gameEnemy::InitEnemy(enemy.enemyRec, enemy.enemyPos, enemy.velocity);
			player.matchStart = false;

		default:
			break;
		}
	}

	//input here only usefull for future menu
	
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
		case SCENEMANAGMENT::NONE:
			scene = SCENEMANAGMENT::GAME;
<<<<<<< Updated upstream
			gamePlayer::InitPlayer(player.playerRec, player.playerPos, player.velocity,
=======
			player.frameRec = { 0.0f, 0.0f, (float)player.playerSprite.width / 6, (float)player.playerSprite.height };
			gamePlayer::InitPlayer(player.playerRec, player.playerSprite, player.frameRec, player.playerPos, player.velocity,
>>>>>>> Stashed changes
				player.radius, player.gravity, player.jumpForce);
			gameEnemy::InitEnemy(enemy.enemyRec, enemy.enemyPos, enemy.velocity);
			player.matchStart = false;
			break;

		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player.playerRec,player.playerPos,player.velocity,
				player.matchStart,enemy.enemyRec,player.radius,scene,player.gravity,player.jumpForce);
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
