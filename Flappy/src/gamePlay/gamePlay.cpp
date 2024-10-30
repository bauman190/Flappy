#include "gamePlay.h"

namespace Game
{
	void RunGame()
	{
		gamePlayer::Player player;
		SCENEMANAGMENT scene;

		Init(player, scene);

		while (!WindowShouldClose())
		{
			Input(player, scene);
			Update(player, scene);
			Draw(player, scene);
		}

		Close();
	}

	void Init(gamePlayer::Player& player, SCENEMANAGMENT& scene)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " RunGame by Francisco Jonas ");
			scene = SCENEMANAGMENT::MAINMENU;
			player = gamePlayer::CreatePlayer(player);
		default:
			break;
		}
	}
	void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			break;

		case SCENEMANAGMENT::CREDITS:
			break;

		case SCENEMANAGMENT::GAME:
			gamePlayer::InputPlayer(player);
			break;

		case SCENEMANAGMENT::WINLOSESCRREN:
			break;

		case SCENEMANAGMENT::PAUSE:
			break;

		case SCENEMANAGMENT::EXIT:
			break;
		default:
			break;
		}
	}
	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player);

			break;
		case SCENEMANAGMENT::RESETGAME:

			break;
		case SCENEMANAGMENT::WINLOSESCRREN:
			break;

		default:
			break;
		}
	}
	void Draw(gamePlayer::Player& player, SCENEMANAGMENT scene)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:

			break;
		case SCENEMANAGMENT::CREDITS:

			break;
		case SCENEMANAGMENT::GAME:

			gamePlayer::DrawPlayer(player);

			break;
		case SCENEMANAGMENT::WINLOSESCRREN:

			break;
		case SCENEMANAGMENT::PAUSE:

			break;
		case SCENEMANAGMENT::EXIT:

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
