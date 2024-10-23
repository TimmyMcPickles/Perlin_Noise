#include "raylib.h"
#include "perlin.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"


int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  int getFrames = GetFrameTime();
  //perlin noise;

  Texture2D texture;
  Image image;

  //camera.target = (Vector2){};
  float time = 0.0f;
  while (!WindowShouldClose()) {
      time += 0.01f;

      for (int y = 0; y < SCREEN_HEIGHT; ++y ){
          for (int x = 0; x < SCREEN_WIDTH; ++x){
              image = GenImagePerlinNoise(SCREEN_WIDTH, SCREEN_HEIGHT, x * 0.1f + time, y * 0.1f + time, 4.0f);
              texture = LoadTextureFromImage(image);
          }
      }

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
