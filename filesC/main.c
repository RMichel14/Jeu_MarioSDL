#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#include "game.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main() {
    int *tableau = NULL;
    // tableau = malloc(10*sizeof(int));

    int window = createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    // liberation de la memoire
    // if (NULL != renderer)
    //     SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}