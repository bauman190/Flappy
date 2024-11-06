#include "gamePlay.h"

namespace Game
{
	void RunGame()
	{
		gamePlayer::Player player;
		gameEnemy::enemyStructure enemy{};
		gameMenu::Menu mainMenu;
		gameMouse::Mouse mouse;
		SCENEMANAGMENT scene;
		scene = SCENEMANAGMENT::NONE;

		Init(player, scene, enemy, mainMenu, mouse);

		while (!WindowShouldClose())
		{
			Input(scene, mainMenu, mouse);
			Update(player, scene, enemy, mainMenu, mouse);
			Draw(player, scene, enemy, mainMenu, mouse);
		}

		UnloadTexture(player.playerSprite);

		Close();
	}

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy, gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			player.currentFrame = 0;
			player.framesCounter = 0;
			player.framesSpeed = 8;
			player.playerSprite = LoadTexture("Flappy/res/Meow-Knight_JumpHor.png");
			player.matchStart = false;

			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " Francisco Jonas Flappy v0.1 ");

			scene = SCENEMANAGMENT::MAINMENU;
			mainMenu = gameMenu::CreateMainMenu();
			gamePlayer::InitPlayer(player);
			gameEnemy::InitEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity);
			break;
		default:
			break;
		}
	}

	void Input(SCENEMANAGMENT& scene, gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::InputMainMenu(mainMenu, mouse, scene);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameMenu::InputCredits(scene);
			break;
		default:
			break;
		}
	}

	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy, gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			scene = SCENEMANAGMENT::GAME;
			player.frameRec = { 0.0f, 0.0f, (float)player.playerSprite.width / 6, (float)player.playerSprite.height };
			gamePlayer::InitPlayer(player);
			gameEnemy::InitEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity);
			player.matchStart = false;
			break;
		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player, scene, enemy.enemyRecDown);
			gameEnemy::UpdateEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity, player.matchStart);
			break;
		default:
			break;
		}
	}
	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene, gameEnemy::enemyStructure enemy, gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (scene)
		{

		case SCENEMANAGMENT::GAME:
			gameEnemy::DrawEnemy(enemy.enemyRecDown, enemy.enemyRecUp);
			gamePlayer::DrawPlayer(player.playerRec, player.matchStart);
			break;
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::DrawMainMenuorPause(mainMenu, scene, mouse);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameMenu::DrawCredits()
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
