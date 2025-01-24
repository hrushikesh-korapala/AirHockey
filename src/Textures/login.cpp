#include "login.h"

using namespace texture;

void Login::load_texture(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    auto background = IMG_LoadTexture(renderer, this->__user_icon.c_str());
	SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderPresent(renderer);
}