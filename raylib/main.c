#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(800, 450, "basic shapes drawing Duong Nguyen");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    float rotation = 0.0f;

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        rotation += 0.2f; // rotate the object
        BeginDrawing();   // begin drawing

        ClearBackground(RAYWHITE);
        DrawText("some basic shapes available on raylib", 20, 20, 20, DARKBROWN);

        DrawCircle(screenWidth / 5, 120, 35, DARKBLUE);
        DrawCircleGradient(screenWidth / 5, 220, 60, GREEN, SKYBLUE);
        DrawCircleLines(screenWidth / 5, 340, 80, DARKBLUE);

        DrawRectangle(screenWidth / 4 * 2 - 60, 100, 120, 60, RED);
        DrawRectangleGradientH(screenWidth / 4 * 2 - 90, 170, 180, 130, MAROON, GOLD);
        DrawRectangleLines(screenWidth / 4 * 2 - 40, 320, 80, 60, ORANGE); // NOTE: Uses QUADS internally, not lines

        DrawPoly((Vector2){screenWidth / 4.0f * 3, 330}, 6, 80, rotation, BROWN);
        DrawPolyLines((Vector2){screenWidth / 4.0f * 3, 330}, 6, 90, rotation, BROWN);
        DrawPolyLinesEx((Vector2){screenWidth / 4.0f * 3, 330}, 6, 85, rotation, 6, BEIGE);
        // NOTE: We draw all LINES based shapes together to optimize internal drawing,
        // this way, all LINES are rendered in a single draw pass
        DrawLine(18, 42, screenWidth - 18, 42, BLACK);
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}