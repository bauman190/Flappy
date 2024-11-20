#pragma once

#include "raylib.h"

namespace gameBackAnim
{
	struct Background
	{
		Texture2D background;
		Texture2D midground;
		Texture2D frontground;
		Texture2D front2ground;
		Texture2D backLayer;

		float scrollingBack;
		float scrollingMid;
		float scrollingFront;
		float scrollingFront2;
		float scrollingbackLayer;
		float backSpeed;
		float midSpeed;
		float frontSpeed;
		float front2Speed;
	};

	void CreateBackScene();
	void UpdateBackground( bool matchStart);
	void DrawBackground();
	void UnloadTextures();
}