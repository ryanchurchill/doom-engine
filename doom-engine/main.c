#include <SDL.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include "typedefs.h"

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

void PutPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    if (x > screenW || y > screenH)
        return;

    if (x < 0 || y < 0)
        return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void UpdateScreen()
{
    SDL_RenderPresent(renderer);
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