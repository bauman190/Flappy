#pragma once
#include "raylib.h"

namespace gameMouse
{
	struct Mouse
	{
		Vector2 mousePos;
	};

	Mouse CreateMouse(Mouse gameMouse);
	void UpdateMousePos(Mouse& gameMouse);
}