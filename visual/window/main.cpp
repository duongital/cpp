#include "raylib.h"

int main() {
  int screenWidth = 800;
  int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
  Texture2D texture = LoadTexture("resources/Circle.png");

  // Main game loop
  while (!WindowShouldClose()) {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawTexture(texture, 0, 0, PINK);
    DrawText("Congrats! You created your first window!", 190, 200, 20, RED);

    EndDrawing();

    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  UnloadTexture(texture);
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}