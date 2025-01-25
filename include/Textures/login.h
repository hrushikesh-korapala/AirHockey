#ifndef _GAME_CLIENT_GAME_LOGIN_TEXTURE_
#define _GAME_CLIENT_GAME_LOGIN_TEXTURE_
#include "screen.h"
#include "Utils/utils.h"
#include "Utils/states.h"

namespace texture
{
    class Login : public Screen
    {
        public:
        Login() : __user_icon(std::string(TEXTURE_PATH)+"user_icon.png"),
                    __pass_icon(std::string(TEXTURE_PATH)+"password_icon.png"),
                    __login_icon(std::string(TEXTURE_PATH)+"login_icon.png"),
                    __font_path(std::string(TEXTURE_PATH)+"font.ttf"),
                    __text_box(std::string(TEXTURE_PATH)+"text_box.png") {
            if (TTF_Init() < 0)
            {
                std::cerr << "TTF error: " << TTF_GetError() << std::endl;
                exit(3);
            }
            this->__user_rect = createSDLRect(WIDTH/5,(HEIGHT/3)-45,30,30);
            this->__pass_rect = createSDLRect(WIDTH/5,(HEIGHT/3)+15,30,30);
            this->__user_box_rect = createSDLRect((WIDTH/5)+45,(HEIGHT/3)-43,(WIDTH/2),30);
            this->__pass_box_rect = createSDLRect((WIDTH/5)+45,(HEIGHT/3)+17,(WIDTH/2),30);
            this->__login_rect = createSDLRect((WIDTH/2)-30,(HEIGHT/3)+60,60,30);
        }
        void init(SDL_Window* window, SDL_Renderer* renderer);
        ~Login() override;
        void loadTexture(SDL_Window* window, SDL_Renderer* renderer) override;
        void clearTexture(SDL_Window* window, SDL_Renderer* renderer) override;
        LoginState::LoginState checkEvent(SDL_Event &event);
        PageState::PageState handleEvent(SDL_Event &event, SDL_Window* window, SDL_Renderer* renderer);

        private:
        LoginState::LoginState __curr_state;
        std::string __user_icon;
        std::string __pass_icon;
        std::string __login_icon;
        std::string __text_box;
        std::string __username;
        std::string __password;
        std::string __font_path;

        TTF_Font *__font;
        SDL_Surface *__ttf;
        SDL_Texture *__text;
        SDL_Rect __user_rect, __pass_rect,__user_box_rect,__pass_box_rect, __login_rect;
    };
}

#endif // _GAME_CLIENT_GAME_LOGIN_TEXTURE_