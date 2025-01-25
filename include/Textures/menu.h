#ifndef _GAME_CLIENT_GAME_MENU_TEXTURE_
#define _GAME_CLIENT_GAME_MENU_TEXTURE_
#include "screen.h"
#include "Utils/utils.h"
#include "Utils/states.h"

namespace texture
{
    class Menu : public Screen
    {
        public:
        Menu() : __start_icon(std::string(TEXTURE_PATH)+"start_icon.png") {
            this->__start_rect = createSDLRect((WIDTH/2)-50,(HEIGHT/2)-50,100,100);
        }
        void init(SDL_Window* window, SDL_Renderer* renderer);
        ~Menu() override;
        void loadTexture(SDL_Window* window, SDL_Renderer* renderer) override;
        void clearTexture(SDL_Window* window, SDL_Renderer* renderer) override;
        MenuState::MenuState checkEvent(SDL_Event &event);
        PageState::PageState handleEvent(SDL_Event &event, SDL_Window* window, SDL_Renderer* renderer);

        private:
        MenuState::MenuState __curr_state;
        std::string __start_icon;

        TTF_Font *__font;
        SDL_Rect __start_rect;
    };
}

#endif // _GAME_CLIENT_GAME_MENU_TEXTURE_