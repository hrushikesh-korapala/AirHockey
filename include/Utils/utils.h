#ifndef _GAME_CLIENT_UTILS_
#define _GAME_CLIENT_UTILS_

#include <iostream>
#include <cstdint>
#include "SDL_rect.h"

constexpr uint64_t WIDTH=480;
constexpr uint64_t HEIGHT=840;
#define BLACK_COLOR (SDL_Color){0, 0, 0, 255}

SDL_Rect createSDLRect(int x, int y, int w, int h);

bool inRect(int x, int y, SDL_Rect box);

#endif // _GAME_CLIENT_UTILS_