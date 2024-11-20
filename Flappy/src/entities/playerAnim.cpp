#include "playerAnim.h"

namespace gameSprite
{
	Sprite gameSprite::CreatePlayerSprite(gamePlayer::Player player)
	{
		Sprite playerSprite;

		float scaleFramPosX = player.playerPos.x + 60.0f;
		float scaleFramPosY = player.playerPos.y + 7.0f;

		playerSprite.playerSprt = LoadTexture("res/Meow-Knight_JumpAdjust.png");

		playerSprite.frameRec = { 0.0f,0.0f,static_cast<float>(playerSprite.playerSprt.width / 10),
			static_cast<float>(playerSprite.playerSprt.height) };

		playerSprite.scaleFrame = { scaleFramPosX,scaleFramPosY,static_cast<float>(playerSprite.playerSprt.width * 0.5f),
			static_cast<float>(playerSprite.playerSprt.height * 2.5f) };

		playerSprite.spritePos = { playerSprite.playerSprt.width / 2.0f,playerSprite.playerSprt.height / 2.0f };

		playerSprite.currentFrame = 0.0f;
		playerSprite.framesCounter = 0.0f;
		playerSprite.framesSpeed = 8.0;

		return playerSprite;
	}

	void UpdateSprite(Sprite& playerSprt, gamePlayer::Player player)
	{
		float scaleFramPosX = player.playerPos.x + 60.0f;
		float scaleFramPosY = player.playerPos.y + 7.0f;

		float farmeSpeed = 10.0f;

		playerSprt.framesCounter += GetFrameTime();
		
		if (IsKeyPressed(KEY_SPACE))
		{
			playerSprt.isAnimated = true;
		}

		if (playerSprt.isAnimated && playerSprt.framesCounter >=  (GetFPS() / farmeSpeed) * GetFrameTime())
		{
			playerSprt.framesCounter = 0;
			playerSprt.currentFrame++;

			if (playerSprt.currentFrame > 5)
			{
			playerSprt.currentFrame = 0;
			playerSprt.isAnimated = false;
			}
			playerSprt.frameRec.x = (float)playerSprt.currentFrame * (float)playerSprt.playerSprt.width / 10;

		}
		playerSprt.scaleFrame.x = scaleFramPosX;
		playerSprt.scaleFrame.y = scaleFramPosY;
		
	}

	void DrawSprite(Sprite playerSprt)
	{
		DrawTexturePro(playerSprt.playerSprt, playerSprt.frameRec, playerSprt.scaleFrame, playerSprt.spritePos, 0.0f, WHITE);
	}

	void UnloadTextures(Sprite& playerSprt)
	{
		UnloadTexture(playerSprt.playerSprt);
	}
}