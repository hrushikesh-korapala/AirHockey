#include "Textures/login.h"
#include "Utils/utils.h"

int main() {
    SDL_Window* win;
    SDL_Renderer* rend;

    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	win = SDL_CreateWindow("Air Hockey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!win)
	{
		std::cerr << "SDL error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!rend)
	{
		std::cerr << "SDL error: " << SDL_GetError() << std::endl;
		exit(1);
	}
    texture::Login log;
    log.init(win,rend);
    PageState page_state;
    

    bool running = true;
    SDL_Event event;
    
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    page_state = log.handleEvent(event,win,rend);
                    if(page_state == PageState::MenuPage) log.clearTexture(win,rend);
                    else if(page_state == PageState::QuitPage) running = false;
                    break;
            }
        }
        
        // Add a small delay to prevent high CPU usage
        SDL_Delay(16); // Roughly 60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 0;
}