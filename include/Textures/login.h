#ifndef _GAME_CLIENT_GAME_LOGIN_TEXTURE_
#define _GAME_CLIENT_GAME_LOGIN_TEXTURE_
#include "screen.h"


namespace texture
{
    class Login : public Screen
    {
        public:
        Login() : __user_icon(std::string(TEXTURE_PATH)+"sample.png") {}
        ~Login() override {}
        void load_texture(SDL_Window* window, SDL_Renderer* renderer) override;
        private:
        std::string __user_icon;
    };
}

#endif // _GAME_CLIENT_GAME_LOGIN_TEXTURE_