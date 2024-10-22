#include "perlin.h"
#include <raylib.h>

int perlin::getWidth(){
    return width;
}

int perlin::getHeight(){
    return height;
}

Image perlin::perlinGen(){
    return GenImagePerlinNoise(SCREEN_WIDTH, SCREEN_HEIGHT, offsetX, offsetY, scale);
}

int perlin::setOffSet_X(){
    return offsetX = 50;
}

int perlin::setOffSet_Y(){
    return offsetY = 50;
}

int perlin::setScale(){
    return scale = 4.0f;
}
