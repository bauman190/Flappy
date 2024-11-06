#pragma once

#include "raylib.h"

//ARENA settings
const float screenWidth = 1024.0f;
const float screenHeight = 768.0f;
const float midScreenWidth = screenWidth / 2;
const float midScreenHeight = screenHeight / 2;
const float screenHeightDiv6 = screenHeight / 6;
const float auxFloat = 100.0f;


const int MAX_FRAME_SPEED = 15;
const int MIN_FRAME_SPEED = 1;
const float structureSeparation = 200.0f;

struct Circle
{
	Vector2 circlePos;
	float radius;
};