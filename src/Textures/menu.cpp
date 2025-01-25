#include "Textures/menu.h"
#include <iostream>
using namespace texture;


Menu::~Menu()
{
}

void Menu::loadTexture(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 191, 150, 160);
    SDL_RenderClear(renderer);
    auto start_box = IMG_LoadTexture(renderer, this->__start_icon.c_str());
	SDL_RenderCopy(renderer, start_box, NULL, &this->__start_rect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(start_box);
}

void Menu::init(SDL_Window* window, SDL_Renderer* renderer)
{
    this->__curr_state = MenuState::Normal;
    this->loadTexture(window,renderer);
}

void Menu::clearTexture(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

MenuState::MenuState Menu::checkEvent(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
        {
            this->__curr_state = MenuState::Quit;
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (inRect(event.button.x,event.button.y,this->__start_rect))
                {
                    this->__curr_state = MenuState::Start;
                }
                else 
                {
                    this->__curr_state = MenuState::Normal;
                }
            }
            break;
        }
    }
    return this->__curr_state;
}

PageState::PageState Menu::handleEvent(SDL_Event &event, SDL_Window* window, SDL_Renderer* renderer)
{
    this->checkEvent(event);

    if(this->__curr_state == MenuState::Start) return PageState::GamePage;
    else if(this->__curr_state == MenuState::Quit) return PageState::QuitPage;
    else return PageState::MenuPage;
}
