#include "raylib.h"
#include "raymath.h"
//#include "perlin.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"


int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  //perlin noise;

  Texture2D texture;
  Image image;

  //camera.target = (Vector2){};
  float x = 0.1f * GetRandomValue(0, 255);
  float y = 0.1f * GetRandomValue(0, 255);
  float scale = 4.0f;
  float time = 0;
  while (!WindowShouldClose()) {
      time += 1.0f;
      y ++;
      x++;
    image = GenImagePerlinNoise(SCREEN_WIDTH, SCREEN_HEIGHT, (x + Lerp(0.0f, 7.0f, 0.314f)) + time, (y + Lerp(0.0f, 3.0f, 0.314f)) + time, scale + Lerp(0.0f, 10.0f, 0.23f));
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

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
