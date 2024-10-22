#pragma once
#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

class perlin : public Texture2D {

public:
  Image perlinGen();
  int getWidth();   // Getters
  int getHeight();

  int setOffSet_X();    // Setters
  int setOffSet_Y();
  int setScale();

  protected:

  int offsetX = 50;
  int offsetY = 50;
  float scale = 4.0f;
};
