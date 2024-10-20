#include <SDL.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#undef main

#define screenW 800
#define screenH 600

SDL_Renderer* renderer;

int ShouldQuit(SDL_Event event)
{
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        return 1;
    return 0;
}

int main()
{
    //return 0;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* mainWin = SDL_CreateWindow(
        "3D Poly Renderer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenW, screenH,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(mainWin, 0, SDL_RENDERER_SOFTWARE);

    int loop = 1;
    SDL_Event event;
    while (loop)
    {
        SDL_PollEvent(&event);

        if (ShouldQuit(event))
            break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(mainWin);
    SDL_Quit();
}