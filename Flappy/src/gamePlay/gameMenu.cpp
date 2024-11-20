#include "gamePlay/gameMenu.h"

namespace gameMenu
{
	//BUTTON SIZE
	const float buttonWidth = 150.0f;
	const float buttonHeiht = 40.0f;
	const int textFontSize = 25;
	const int titleFontSize = 50;
	const float auxXCorrect = 75.0f;
	const float auxTitleXCorrect = 25.0f;
	//BUTTON CENTER
	const float buttonCenterX = (buttonWidth / 4.0f) + 10.0f;
	const float buttonCenterY = buttonHeiht / 4.0f;

	//MAINMENU settings---------------------------------
	//PAUSE MENU settings------------------------------------------
	//button default pos
	const float auxButtonPosX = midScreenWidth - auxXCorrect;
	const float auxButtonPosY_1 = screenHeightDiv6 * 1.0f;
	const float auxButtonPosY_2 = screenHeightDiv6 * 2.0f;
	const float auxButtonPosY_3 = screenHeightDiv6 * 3.0f;
	const float auxButtonPosY_4 = screenHeightDiv6 * 4.0f;
	//text main menu
	const float titleTextPosX = auxButtonPosX;
	const float titleTextPosY = auxButtonPosY_1;
	const float playTextPosX = auxButtonPosX + buttonCenterX;
	const float playTextPosY = auxButtonPosY_2 + buttonCenterY;
	const float creditsTextButtonPosX = auxButtonPosX + buttonCenterX / 2;
	const float creditsTextButtonPosY = auxButtonPosY_3 + buttonCenterY;
	const float exitTextButtonPosX = auxButtonPosX + buttonCenterX;
	const float exitTextButtonPosY = auxButtonPosY_4 + buttonCenterY;


	static Button Cats;
	static Button Backgraund;

	////EXIT-----------------------------------------------
	////question text1
	//const float auxExitTextPosX = screenWidth / 3;
	//const float exitText1PosY = (screenHeight / 7);
	////button YES NO exit
	//const float auxExitButtonPosY = (screenHeight / 5) * 4;
	//const float auxExitButtonPosX_1 = (screenWidth / 5) * 2;
	//const float auxExitButtonPosX_2 = (screenWidth / 5) * 4;
	////text YES NO exit
	//const float auxExitText2PosY = (screenHeight / 7) * 2;
	//const float exitText3PosX = auxExitButtonPosX_1;
	//const float exitText1PosX = auxExitButtonPosX_2;

	////WIN/LOSE SCREEN------------------------------------------
	////TO MENU and RESTART button
	////WIN LOSE title
	//const float auxWinLoseTextPosX = auxButtonPosX;
	//const float winLoseTextPosY = auxButtonPosY_1;
	//const float restartTextPosY = auxButtonPosY_2;
	//const float toMenuTextPosY = auxButtonPosY_3;

	////use auxbuttonpos for X position
	//const float restartButtonPosY_3 = screenHeightDiv6 * 4;
	//const float toMenuButtonPosY_4 = screenHeightDiv6 * 5;

	Menu CreateMainMenu()
	{
		Menu menu;
		//PLAY BUTTON
		menu.secondButton.buttonPos.x = auxButtonPosX;
		menu.secondButton.buttonPos.y = auxButtonPosY_2;

		menu.secondButton.buttonSize.x = buttonWidth;
		menu.secondButton.buttonSize.y = buttonHeiht;

		menu.secondButton.buttonCenterPos.x = buttonCenterX;
		menu.secondButton.buttonCenterPos.y = buttonCenterY;

		//CREDITS BUTTON
		menu.thirdButton.buttonPos.x = auxButtonPosX;
		menu.thirdButton.buttonPos.y = auxButtonPosY_3;

		menu.thirdButton.buttonSize.x = buttonWidth;
		menu.thirdButton.buttonSize.y = buttonHeiht;

		menu.thirdButton.buttonCenterPos.x = buttonCenterX;
		menu.thirdButton.buttonCenterPos.y = buttonCenterY;

		////EXIT BUTTON
		//mainAndPauseMenu.fourthButton.buttonPos.x = auxButtonPosX;
		//mainAndPauseMenu.fourthButton.buttonPos.y = auxButtonPosY_4;

		//mainAndPauseMenu.fourthButton.buttonSize.x = buttonWidth;
		//mainAndPauseMenu.fourthButton.buttonSize.y = buttonHeiht;

		//mainAndPauseMenu.fourthButton.buttonCenterPos.x = buttonCenterX;
		//mainAndPauseMenu.fourthButton.buttonCenterPos.y = buttonCenterY;

		return menu;
	}
	Menu CreateCredits()
	{
		Menu credits;

		float backButtonPosX = 10.0f;
		float backButtonPosY = screenHeight - 50.0f;
		/*float backButtonTextPosX = 10.0f;
		float backButtonTextPosY = screenHeight - 10.0f;*/
		credits.firstButton.buttonPos.x = backButtonPosX;
		credits.firstButton.buttonPos.y = backButtonPosY;
		credits.firstButton.buttonSize.x = buttonWidth;
		credits.firstButton.buttonSize.y = buttonHeiht;

		credits.buttonText.textPos.x = backButtonPosX+45.0f;
		credits.buttonText.textPos.y = backButtonPosY+10.0f;
		credits.buttonText.fontSize = textFontSize;

		return credits;
	}
	/*Menu CreateWinLoseScreen(Menu winScreen)
	{
		return winScreen;
	}
	Menu CreateExitScreen(Menu exitScreen)
	{
		return exitScreen;
	}*/

	void InputMainMenu(Menu mainAndPauseMenu, gameMouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// PLAY BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse,
			mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::GAME;
		}
		// CREDITS BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse,
			mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize))
		{
			scene = SCENEMANAGMENT::CREDITS;
		}
		//// EXIT BUTTON
		//if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse,
		//	mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize))
		//{
		//	scene = SCENEMANAGMENT::EXIT;
		//}
	}
	void InputCredits(Menu credits, gameMouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse,
			credits.firstButton.buttonPos, credits.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::MAINMENU;
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse,
			Cats.buttonPos, Cats.buttonSize))
		{
			std::string CatsUrl = "https://9e0.itch.io/cute-legends-cat-heroes";
			std::string command = "start chrome \"" + CatsUrl + "\"";
			system(command.c_str());
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse,
			Backgraund.buttonPos, Backgraund.buttonSize))
		{
			std::string BackgraundUrl = "https://edermunizz.itch.io/free-pixel-art-forest";
			std::string command = "start chrome \"" + BackgraundUrl + "\"";
			system(command.c_str());
		}

		//// BACK BUTTON
		//if (IsKeyPressed(KEY_ESCAPE))
		//{
		//	if (IsKeyReleased(KEY_ESCAPE))
		//	{
		//		scene = SCENEMANAGMENT::MAINMENU;
		//	}
		//}
	}
	//void InputPauseMenu(Menu mainAndPauseMenu, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	//{
	//	// RESUME BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.firstButton.buttonPos, mainAndPauseMenu.firstButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::GAME;
	//	}
	//	if (IsKeyPressed(KEY_ESCAPE))
	//	{
	//		if (IsKeyReleased(KEY_ESCAPE))
	//		{
	//			scene = SCENEMANAGMENT::GAME;
	//		}
	//	}
	//	// RESET BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::CREDITS;
	//	}
	//	// BACKMENU BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::EXIT;
	//	}
	//}
	//void InputWinLoseScreen(Menu winLoseScreen, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	//{
	//	// RESUME BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, winLoseScreen.firstButton.buttonPos, winLoseScreen.firstButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::RESETGAME;
	//	}
	//	// RESET BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, winLoseScreen.secondButton.buttonPos, winLoseScreen.secondButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::MAINMENU;
	//	}
	//}
	//void InputExitScreen(Menu exitScreen, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	//{
	//	// EXIT BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, exitScreen.firstButton.buttonPos, exitScreen.firstButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::LEAVESIM;
	//	}
	//	// GOBACK BUTTON
	//	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, exitScreen.secondButton.buttonPos, exitScreen.secondButton.buttonSize))
	//	{
	//		scene = SCENEMANAGMENT::MAINMENU;
	//	}
	//}

	void DrawMainMenuorPause(Menu mainAndPauseMenu, SCENEMANAGMENT scene, gameMouse::Mouse gameMouse)
	{
		//PLAY or RESUME
		if (isOverButon(gameMouse, mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
			DrawButton(mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize, LIGHTGRAY);
		else
			DrawButton(mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize, WHITE);
		//CREDITS or RESET
		if (isOverButon(gameMouse, mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize))
			DrawButton(mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize, LIGHTGRAY);
		else
			DrawButton(mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize, WHITE);
		//EXIT or BACKTOMENU
		/*if (isOverButon(gameMouse, mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize))
			DrawButton(mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize, LIGHTGRAY);
		else
			DrawButton(mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize, WHITE);*/

		if (scene == SCENEMANAGMENT::MAINMENU)
		{
			PrintText("FLAPPY", (titleTextPosX - auxTitleXCorrect), titleTextPosY, titleFontSize, RED);
			PrintText("PLAY", playTextPosX, playTextPosY, textFontSize, RED);
			PrintText("CREDITS", creditsTextButtonPosX, creditsTextButtonPosY, textFontSize, RED);
			PrintText("0.3", static_cast<float>(screenWidth * 0.95), static_cast<float>(screenHeight * 0.95), textFontSize, RED);
			//PrintText("EXIT", exitTextButtonPosX, exitTextButtonPosY, textFontSize, RED);
		}

		/*else
		{
			PrintText("PAUSE", (titleTextPosX - auxTitleXCorrect), titleTextPosY, titleFontSize, RED);
			PrintText("RESUME", mainAndPauseMenu.firstButton.buttonPos.x, mainAndPauseMenu.firstButton.buttonPos.y, textFontSize, RED);
			PrintText("RESTART", mainAndPauseMenu.secondButton.buttonPos.x, mainAndPauseMenu.secondButton.buttonPos.y, textFontSize, RED);
			PrintText("MENU", mainAndPauseMenu.thirdButton.buttonPos.x, mainAndPauseMenu.thirdButton.buttonPos.y, textFontSize, RED);
		}*/

	}
	void DrawCredits(Menu credits, gameMouse::Mouse gameMouse)
	{
		//CREDITS settings-----------------------------------
		const float auxCreditsTextPosX = screenWidth / 8;
		const float creditsText1PosY = (screenHeight / 7);
		const float creditsText2PosY = (screenHeight / 7) * 2;
		const float creditsText3PosY = (screenHeight / 7) * 3;
		const float creditsText4PosY = (screenHeight / 7) * 4;
		//const float creditsText5PosY = (screenHeight / 7) * 5;
		//const float creditsText6PosY = (screenHeight / 7) * 6;
		//const float creditsText7PosY = (screenHeight / 7) * 7;
		//const float backButtonPosX = screenWidth / 5;
		//const float backButtonPosY = screenWidth / 5;
		Cats.buttonPos.x = auxCreditsTextPosX;
		Cats.buttonPos.y = creditsText3PosY;
		Cats.buttonSize.x = buttonWidth;
		Cats.buttonSize.y = buttonHeiht;
		Backgraund.buttonPos.x = auxCreditsTextPosX;
		Backgraund.buttonPos.y = creditsText4PosY;
		Backgraund.buttonSize.x = buttonWidth;
		Backgraund.buttonSize.y = buttonHeiht;
		PrintText("CREDITS", auxCreditsTextPosX, creditsText1PosY, textFontSize, RED);
		PrintText("Made by FRANCISCO JONAS and Juan Bautista Castignani", auxCreditsTextPosX, creditsText2PosY, textFontSize, RED);
		PrintText("Background", auxCreditsTextPosX, creditsText4PosY, textFontSize, RED);

		if (isOverButon(gameMouse, credits.firstButton.buttonPos, credits.firstButton.buttonSize))
			DrawButton(credits.firstButton.buttonPos, credits.firstButton.buttonSize, LIGHTGRAY);
		else
			DrawButton(credits.firstButton.buttonPos, credits.firstButton.buttonSize, WHITE);
		PrintText("BACK", credits.buttonText.textPos.x, credits.buttonText.textPos.y, textFontSize, RED);

		if(isOverButon(gameMouse, Cats.buttonPos, Cats.buttonSize))
			DrawButton(Cats.buttonPos, Cats.buttonSize, LIGHTGRAY);
		else
			DrawButton(Cats.buttonPos, Cats.buttonSize, WHITE);

		if (isOverButon(gameMouse, Backgraund.buttonPos, Backgraund.buttonSize))
			DrawButton(Backgraund.buttonPos, Backgraund.buttonSize, LIGHTGRAY);
		else
			DrawButton(Backgraund.buttonPos, Backgraund.buttonSize, WHITE);

		
		PrintText("Background", auxCreditsTextPosX, creditsText4PosY, textFontSize, RED);
		PrintText("By: edermunizz", auxCreditsTextPosX + Cats.buttonSize.x, creditsText4PosY, textFontSize, RED);
		PrintText("Cats", auxCreditsTextPosX, creditsText3PosY, textFontSize, RED);
		PrintText("By: 9EO", auxCreditsTextPosX + Backgraund.buttonSize.x, creditsText3PosY, textFontSize, RED);
	}
	/*void DrawExitMenu(Menu exitScreen)
	{
		PrintText("EXIT here", exitScreen.firstButton.buttonPos.x, exitScreen.firstButton.buttonPos.y, textFontSize, RED);
	}
	void DrawWinLoseScreen(Menu winLoseScreen)
	{
		winLoseScreen.firstButton.buttonPos.x = 0.0f;
	}*/

	void PrintText(const char* text, float posX, float posY, int fontSize, Color color)
	{
		DrawText(text, static_cast<int>(posX), static_cast<int>(posY), fontSize, color);
	}

	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color)
	{
		DrawRectangle(static_cast<int>(buttonPos.x), static_cast<int>(buttonPos.y), static_cast<int>(buttonSize.x), static_cast<int>(buttonSize.y), color);
	}
	bool isOverButon(gameMouse::Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension)
	{
		if (mouse.mousePos.x >= buttonPos.x &&
			mouse.mousePos.x <= buttonPos.x + buttonDimension.x &&
			mouse.mousePos.y >= buttonPos.y &&
			mouse.mousePos.y <= buttonPos.y + buttonDimension.y)
		{
			return true;
		}
		return false;
	}
}