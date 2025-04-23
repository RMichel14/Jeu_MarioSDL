#include "game.h"

SDL_Window *createWindow(int window_Width, int window_Height) {
    // une fenêtre
    SDL_Window *window = NULL;

    // initialisation de la video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
                SDL_GetError());
        exit(EXIT_FAILURE); // On quitte le programme
    }

    const char *title = "MarioSDL";

    window = SDL_CreateWindow(title, 0, 0, window_Width, window_Height, SDL_WINDOW_OPENGL);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return window;
}

SDL_Renderer *createRenderer(SDL_Window *window) {
    // verification si la window existe sinon fin de programme
    if (window == NULL) exit(EXIT_FAILURE);

    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);

    return renderer;
}