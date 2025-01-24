#include <SDL2/SDL.h>
#include <iostream>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Print SDL version
    SDL_version compiled;
    SDL_VERSION(&compiled);
    std::cout << "SDL Version (compiled): "
              << static_cast<int>(compiled.major) << "."
              << static_cast<int>(compiled.minor) << "."
              << static_cast<int>(compiled.patch) << std::endl;

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "SDL Test Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::cout << "SDL initialized and window created successfully!" << std::endl;

    // Event loop
    bool running = true;
    SDL_Event event;
    
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        running = false;
                    }
                    break;
            }
        }
        
        // Add a small delay to prevent high CPU usage
        SDL_Delay(16); // Roughly 60 FPS
    }

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}