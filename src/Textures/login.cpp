#include "Textures/login.h"

using namespace texture;


Login::~Login()
{
    SDL_DestroyTexture(this->__text);
}

void Login::loadTexture(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 191, 150, 160);
    SDL_RenderClear(renderer);
    auto user_icon = IMG_LoadTexture(renderer, this->__user_icon.c_str());
    auto pass_icon = IMG_LoadTexture(renderer, this->__pass_icon.c_str());
    auto text_box = IMG_LoadTexture(renderer, this->__text_box.c_str());
    auto login_box = IMG_LoadTexture(renderer, this->__login_icon.c_str());
	SDL_RenderCopy(renderer, user_icon, NULL, &this->__user_rect);
	SDL_RenderCopy(renderer, pass_icon, NULL, &this->__pass_rect);
	SDL_RenderCopy(renderer, text_box, NULL, &this->__user_box_rect);
	SDL_RenderCopy(renderer, text_box, NULL, &this->__pass_box_rect);
	SDL_RenderCopy(renderer, login_box, NULL, &this->__login_rect);
    SDL_RenderPresent(renderer);
}

void Login::init(SDL_Window* window, SDL_Renderer* renderer)
{
    this->__curr_state = LoginState::Normal;
    this->loadTexture(window,renderer);
    this->__font = TTF_OpenFont(this->__font_path.c_str(), 20);
    if (!this->__font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }
}

void Login::clearTexture(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

LoginState Login::checkEvent(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
        {
            this->__curr_state = LoginState::Quit;
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (inRect(event.button.x,event.button.y,this->__user_box_rect))
                {
                    this->__curr_state = LoginState::Username;
                }
                else if (inRect(event.button.x,event.button.y,this->__pass_box_rect))
                {
                    this->__curr_state = LoginState::Password;
                }
                else if (inRect(event.button.x,event.button.y,this->__login_rect))
                {
                    this->__curr_state = LoginState::Login;
                }
                else 
                {
                    this->__curr_state = LoginState::Normal;
                }
            }
            break;
        }
        case SDL_KEYDOWN:
        {
            if(this->__curr_state==LoginState::Username) this->__username+=event.key.keysym.sym;
            else if(this->__curr_state==LoginState::Password) this->__password+=event.key.keysym.sym;
            break;
        }
    }
    return this->__curr_state;
}

PageState Login::handleEvent(SDL_Event &event, SDL_Window* window, SDL_Renderer* renderer)
{
    this->checkEvent(event);
    if(event.type==SDL_KEYDOWN)
    {
        SDL_RenderFillRect(renderer, &this->__user_box_rect);
        SDL_RenderFillRect(renderer, &this->__pass_box_rect);

        __ttf = TTF_RenderText_Solid(this->__font, this->__username.c_str(), BLACK_COLOR);
        __text = SDL_CreateTextureFromSurface(renderer, __ttf);
        SDL_RenderCopy(renderer, __text, NULL, &this->__user_box_rect);
        SDL_FreeSurface(__ttf);
        SDL_DestroyTexture(__text);

        __ttf = TTF_RenderText_Solid(this->__font, this->__password.c_str(), BLACK_COLOR);
        __text = SDL_CreateTextureFromSurface(renderer, __ttf);
        SDL_RenderCopy(renderer, __text, NULL, &this->__pass_box_rect);
        SDL_FreeSurface(__ttf);
        SDL_DestroyTexture(__text);
        SDL_RenderPresent(renderer);
    }

    if(this->__curr_state==LoginState::Login) return PageState::MenuPage;
    else if(this->__curr_state == LoginState::Quit) return PageState::QuitPage;
    else return PageState::LoginPage;
}
