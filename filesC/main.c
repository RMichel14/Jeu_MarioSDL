#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#include "game.h"
#include "events.h"

// fenetre originale 640 par 480
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    SDL_Window *window = createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Renderer *renderer = createRenderer(window);

    // Events SDL
    waitingEvent(renderer);

    // liberation de la memoire
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}