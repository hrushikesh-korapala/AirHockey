#ifndef _GAME_CLIENT_GAME_BASE_CLASS_SCREEN_
#define _GAME_CLIENT_GAME_BASE_CLASS_SCREEN_
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

namespace texture
{
    class Screen
    {
        public:
        Screen() {}
        virtual ~Screen() {}
        
        virtual void loadTexture(SDL_Window* window, SDL_Renderer* renderer) {}
        virtual void clearTexture(SDL_Window* window, SDL_Renderer* renderer) {}
    };
}

#endif // _GAME_CLIENT_GAME_BASE_CLASS_SCREEN_