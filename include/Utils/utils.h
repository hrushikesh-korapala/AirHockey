#pragma once

#include <iostream>

constexpr uint64_t WIDTH=480;
constexpr uint64_t HEIGHT=840;
#define BLACK_COLOR (SDL_Color){0, 0, 0, 255}

SDL_Rect createSDLRect(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x=x;
    rect.y=y;
    rect.w=w;
    rect.h=h;
    return rect;
}

bool inRect(int x, int y, SDL_Rect box)
{
    if(x>=box.x && x<=box.x+box.w && y>=box.y && y<=box.y+box.h) return true;
    else return false;
}
