#include "gamePlay.h"

#include "entities/backAnim.h"

namespace Game
{
	SCENEMANAGMENT lastSene = SCENEMANAGMENT::NONE;
	gamePlayer::Player player2;
	gameSprite::Sprite player2Sprt;
	void RunGame()
	{
		gamePlayer::Player player;
		gameEnemy::enemyStructure enemy{};
		gameMenu::Menu mainMenu;
		gameMenu::Menu credits;
		gameMouse::Mouse mouse;
		gameSprite::Sprite playerSprt;
		SCENEMANAGMENT scene;
		scene = SCENEMANAGMENT::NONE;

		Init(player, scene, enemy, mainMenu, mouse, credits, playerSprt);

		while (!WindowShouldClose())
		{
			Input(scene, mainMenu, mouse, credits);
			Update(player, scene, enemy, mouse,playerSprt);
			Draw(player, scene, enemy, mainMenu, mouse, credits, playerSprt);
		}

		DeInit(playerSprt);

		Close();
	}

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy,
		gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse, gameMenu::Menu& credits,
		gameSprite::Sprite& playerSprt)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:

			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " Francisco Jonas Flappy v0.2 ");

			gamePlayer::InitPlayer(player, ((screenWidth / 6) * 2), ((screenHeight / 6) * 2));
			gamePlayer::InitPlayer(player2, ((screenWidth / 7) * 2), (screenHeight / 6) * 2);

			playerSprt = gameSprite::CreatePlayerSprite(player);
			player2Sprt = gameSprite::CreatePlayerSprite(player2);
			gameBackAnim::CreateBackScene();
			//playerSprt.playerSprt = LoadTexture("res/Meow-Knight_JumpAdjust.png");
			scene = SCENEMANAGMENT::MAINMENU;
			mainMenu = gameMenu::CreateMainMenu();
			credits = gameMenu::CreateCredits();
			mouse = gameMouse::CreateMouse(mouse);

			gameEnemy::InitEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity);
			break;
		default:
			break;
		}
	}

	void Input(SCENEMANAGMENT& scene, gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse, gameMenu::Menu& credits)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::InputMainMenu(mainMenu, mouse, scene);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameMenu::InputCredits(credits, mouse, scene);
			break;
		default:
			break;
		}
	}

	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, gameEnemy::enemyStructure& enemy,
		gameMouse::Mouse& mouse, gameSprite::Sprite& playerSprt)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			if (lastSene == SCENEMANAGMENT::GAME)
			{
				scene = SCENEMANAGMENT::GAME;
			}
			else if (lastSene == SCENEMANAGMENT::GAME2PLAYERS)
			{
				scene = SCENEMANAGMENT::GAME2PLAYERS;
			}
			gamePlayer::InitPlayer(player, ((screenWidth / 6) * 2), ((screenHeight / 6) * 2));
			gamePlayer::InitPlayer(player2, ((screenWidth / 9) * 2), (screenHeight / 6) * 2);
			gameEnemy::InitEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity);
			player.matchStart = false;
			player2.matchStart = false;
			break;
		case SCENEMANAGMENT::GAME:
			gameMouse::UpdateMousePos(mouse);
			gamePlayer::UpdatePlayer(player, scene, enemy.enemyRecDown, enemy.enemyRecUp, KEY_SPACE);
			gameEnemy::UpdateEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity, player.matchStart);
			gameSprite::UpdateSprite(playerSprt, player);
			gameBackAnim::UpdateBackground( player.matchStart);
			lastSene = SCENEMANAGMENT::GAME;
			break;
		case SCENEMANAGMENT::GAME2PLAYERS:
			gameMouse::UpdateMousePos(mouse);
			gamePlayer::UpdatePlayer(player, scene, enemy.enemyRecDown, enemy.enemyRecUp, KEY_SPACE);
			gamePlayer::UpdatePlayer(player2, scene, enemy.enemyRecDown, enemy.enemyRecUp, KEY_UP);
			gameEnemy::UpdateEnemy(enemy.enemyRecDown, enemy.enemyRecUp, enemy.enemyPos, enemy.velocity, player.matchStart);
			gameSprite::UpdateSprite(playerSprt, player);
			gameSprite::UpdateSprite(player2Sprt, player2);
			gameBackAnim::UpdateBackground(player.matchStart);
			lastSene = SCENEMANAGMENT::GAME2PLAYERS;
			break;
		case SCENEMANAGMENT::MAINMENU:
			gameMouse::UpdateMousePos(mouse);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameMouse::UpdateMousePos(mouse);
			break;
		default:
			break;
		}
	}

	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene, gameEnemy::enemyStructure enemy,
		gameMenu::Menu& mainMenu, gameMouse::Mouse& mouse, gameMenu::Menu credits, gameSprite::Sprite playerSprt)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (scene)
		{
		case SCENEMANAGMENT::GAME:
			gameBackAnim::DrawBackground();
			gameEnemy::DrawEnemy(enemy.enemyRecDown, enemy.enemyRecUp);
			gamePlayer::DrawPlayer(player);
#ifdef _DEBUG
			DrawCircle(static_cast<int>(player.playerPos.x + player.radius / 2), static_cast<int>(player.playerPos.y + player.radius / 2), player.radius, BLACK);
#endif
			gameSprite::DrawSprite(playerSprt);
			
			break;
		case SCENEMANAGMENT::GAME2PLAYERS:
			gameBackAnim::DrawBackground();
			gameEnemy::DrawEnemy(enemy.enemyRecDown, enemy.enemyRecUp);
			gamePlayer::DrawPlayer(player);
			gameSprite::DrawSprite(playerSprt);
			gameSprite::DrawSprite(player2Sprt);
			break;
		case SCENEMANAGMENT::MAINMENU:
			gameBackAnim::DrawBackground();
			gameMenu::DrawMainMenuorPause(mainMenu, scene, mouse);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameBackAnim::DrawBackground();
			gameMenu::DrawCredits(credits, mouse);
			break;
		default:
			break;
		}

		EndDrawing();
	}

	void DeInit(gameSprite::Sprite playerSprt)
	{
		gameSprite::UnloadTextures(playerSprt);
		gameBackAnim::UnloadTextures();
	}

	void Close()
	{
		CloseWindow();
	}
}
