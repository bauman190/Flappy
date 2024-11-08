#pragma once

#include "player.h"

namespace gameSprite
{
	struct Sprite
	{
		Texture2D playerSprt;
		Rectangle frameRec = { 0, 0, 0, 0 };
		Rectangle scaleFrame = { 0, 0, 0, 0 };
		Vector2 spritePos = { 0.0f,0.0f };
		float currentFrame = 0;
		float framesCounter = 0;
		float framesSpeed = 8;
		bool isAnimated = false;

		bool matchStart = false;
	};

	Sprite CreatePlayerSprite(gamePlayer::Player player);
	void UpdateSprite(Sprite& playerSprt, gamePlayer::Player player);
	void DrawSprite(Sprite playerSprt);
}