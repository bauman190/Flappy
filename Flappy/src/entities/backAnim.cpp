#include "backAnim.h"

namespace gameBackAnim
{
	static Background backScene;

	void CreateBackScene()
	{
		backScene.background = LoadTexture("res/background.png");
		backScene.midground = LoadTexture("res/midground.png");
		backScene.frontground = LoadTexture("res/frontground.png");
		backScene.front2ground = LoadTexture("res/front2ground.png");

		backScene.scrollingBack = 0.0f;
		backScene.scrollingMid = 0.0f;
		backScene.scrollingFront = 0.0f;
		backScene.scrollingFront2 = 0.0f;

		backScene.backSpeed = 100.0f;
		backScene.midSpeed = 100.0f;
		backScene.frontSpeed = 100.0f;
		backScene.front2Speed = 100.0f;
	}

	void UpdateBackground(bool matchStart)
	{
		if (matchStart)
		{
			backScene.scrollingBack -= 0.1f * GetFrameTime();
			backScene.scrollingMid -= 0.5f * GetFrameTime();
			backScene.scrollingFront -= 1.0f * GetFrameTime();
			backScene.scrollingFront2 -= 1.0f * GetFrameTime();

			if (backScene.scrollingBack <= -backScene.background.width * 2)
				backScene.scrollingBack = 0;
			if (backScene.scrollingMid <= -backScene.midground.width * 2)
				backScene.scrollingMid = 0;
			if (backScene.scrollingFront <= -backScene.frontground.width * 2)
			{
				backScene.scrollingFront = 0;
				backScene.scrollingFront2 = 0;
			}
		}
	}

	void DrawBackground()
	{
		DrawTextureEx(backScene.background, { backScene.scrollingBack,0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backScene.background, { backScene.background.width * 2 + backScene.scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(backScene.midground,{backScene.scrollingMid, 20 }, 0.0f, 1.2f, WHITE);
		DrawTextureEx(backScene.midground,{ backScene.midground.width * 2 + backScene.scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(backScene.frontground,{ backScene.scrollingFront, 20 }, 0.0f, 1.2f, WHITE);
		DrawTextureEx(backScene.frontground,{ backScene.frontground.width * 2 + backScene.scrollingFront, 70 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backScene.front2ground, { backScene.scrollingFront2, 20 }, 0.0f, 1.2f, WHITE);
		DrawTextureEx(backScene.front2ground, { backScene.front2ground.width * 2 + backScene.scrollingFront2, 70 }, 0.0f, 2.0f, WHITE);
	}

	void UnloadTextures()
	{
		UnloadTexture(backScene.background);
		UnloadTexture(backScene.midground);
		UnloadTexture(backScene.frontground);
		UnloadTexture(backScene.front2ground);
	}
}