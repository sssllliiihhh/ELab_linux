#include <SDL.h>
#include <iostream>

SDL_Event ev;

int main(int argc, char* argv[]) 
{
    bool run = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_DisplayMode desktopMode;
    SDL_GetDesktopDisplayMode(0, &desktopMode);

    //std::string s = desktopMode.w + "|" + desktopMode.h;
    SDL_Window* window = SDL_CreateWindow("ELab", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

    std::cout << desktopMode.w << "|" << desktopMode.h << std::endl;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 250, 250, 250, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer); SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    while (run)
    {
        SDL_PollEvent(&ev);
        switch (ev.type)
        {
            case SDL_QUIT:
                run = false;
                break;
            case SDL_WINDOWEVENT:
                if (ev.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    SDL_SetRenderDrawColor(renderer, 250, 250, 250, 255);
                    SDL_RenderClear(renderer);

                    SDL_RenderPresent(renderer); SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
                }
                break;
        }
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
