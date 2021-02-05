#include "raylib/raylib.h"


int main()
{
	InitWindow(640, 480, "BUTSS");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("FUCK!", 100, 100, 15, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}