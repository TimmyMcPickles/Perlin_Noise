#include "raylib.h"
#include "perlin.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"


int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  int getFrames = GetFrameTime();
  perlin noise = {};
  Texture2D texture = LoadTextureFromImage(noise.perlinGen());

  //camera.target = (Vector2){};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
    int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;

    DrawTexture(texture, texture_x, texture_y, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
