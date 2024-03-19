#include "raylib-cpp.hpp"

int main()
{
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
    // raylib::Texture logo("./logo.jpg");
    raylib::Image image = raylib::LoadImage("logo.jpg");
    // raylib::Texture2D texture = raylib::LoadT

    SetTargetFPS(60);
    float rotation = 0.0f;

    while (!WindowShouldClose())
    {
        rotation += 0.2f;
        BeginDrawing();

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

        // Object methods.
        // logo.Draw(
        //     screenWidth / 2 - logo.GetWidth() / 2,
        //     screenHeight / 2 - logo.GetHeight() / 2);

        EndDrawing();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}