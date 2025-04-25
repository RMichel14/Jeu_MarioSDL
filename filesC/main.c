#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "events.h"

// fenetre originale 640 par 480
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    SDL_Window *window = createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (window == NULL) {
        printf("window: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = createRenderer(window);
    if (renderer == NULL) {
        printf("renderer: %s\n", SDL_GetError());
        exit(1);
    }
    int nbImage = 0;
    SDL_Texture **tableauTextures = loadTextures(renderer, &nbImage);
    if (tableauTextures == NULL) {
        SDL_Error(-1);
        printf("Error: Aucune texture chargée ! (File: main.c)");
    };

    // demarrage sur le menu
    menu(renderer, tableauTextures);
    waitingEventMenu(renderer);

    // chargement du jeu
    game(renderer, tableauTextures);

    // Events SDL
    waitingEvent(renderer, tableauTextures);

    // liberation de la memoire
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    if (NULL != tableauTextures) {
        for (int i = 0; i < (nbImage); i++) {
            SDL_DestroyTexture(tableauTextures[i]);
        }
        free(tableauTextures);
    }
    IMG_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}