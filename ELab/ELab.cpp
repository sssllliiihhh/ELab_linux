// ELab.cpp: определяет точку входа для приложения.
//

#include "ELab.h"
#include "SDL.h"

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Не удалось инициализировать SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Создание окна
    SDL_Window* window = SDL_CreateWindow("Simple window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Не удалось создать окно: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Создание рендерера
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Не удалось создать рендерер: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Установка белого фона
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // RGB для белого цвета
    SDL_RenderClear(renderer); // Очистка рендерера с установленным цветом
    SDL_RenderPresent(renderer); // Отображение рендерера

    // Цикл обработки событий
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Выход из цикла при закрытии окна
            }
        }
    }

    // Освобождение ресурсов
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
