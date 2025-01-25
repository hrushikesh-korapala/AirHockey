#include "Utils/utils.h"

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