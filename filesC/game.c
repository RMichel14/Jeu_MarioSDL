#include "game.h"

int createWindow(int window_Width, int window_Height) {
    // une fenêtre
    SDL_Window *window = NULL;

    // initialisation de la video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
                SDL_GetError());
        exit(EXIT_FAILURE); // On quitte le programme
    }

    const char title = "MarioSDL";

    int *window = NULL;
    window = SDL_CreateWindow(title, 0, 0, window_Width, window_Height, SDL_WINDOW_OPENGL);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    return window;
}