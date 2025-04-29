#include "player.h"

void avancer(SDL_Renderer* renderer, SDL_Texture** tableauTextures) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight); // optient la taille de la fenetre (hauteur, largeur)

    SDL_Texture *bg = tableauTextures[1];

    int bgWidth, bgHeight;
    SDL_QueryTexture(bg, NULL, NULL, &bgWidth, &bgHeight);

    int scrollX = 0;
    int scrollSpeed = 2;

    // SDL_Event event;
    // SDL_bool continuer = SDL_TRUE;

    // while (continuer) {
    //     if (event.key.keysym.sym) {
    //         printf("KEY q released !");
    //         continuer = SDL_FALSE;
    //     }
        // SDL_PollEvent(&event); // attente d'un evenement
        // switch (event.type) {
        //     case SDL_QUIT:
        //         continuer = SDL_FALSE;
        //         break;
        //     case SDL_KEYUP:
        //         if (event.key.keysym.sym == SDLK_a) {
        //             continuer = SDL_FALSE;
        //             printf("KEY q released !");
        //             break;
        //         };
        //         if (event.key.keysym.sym == SDLK_SPACE) {
        //             continuer = SDL_FALSE;
        //             printf("FORCE EXIT");
        //             exit(EXIT_SUCCESS);
        //             break;
        //         };
            
        // }

        // Récupérer la taille actuelle de la fenêtre
        // int windowWidth, windowHeight;
        // SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        // SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

        scrollX -= scrollSpeed;
        if (scrollX <= -bgWidth)
            scrollX += bgWidth;

        SDL_RenderClear(renderer);

        // Dessine autant d'images que nécessaire pour couvrir toute la largeur
        for (int x = scrollX; x < windowWidth; x += bgWidth) {
            SDL_Rect dest = {x, 0, bgWidth, windowHeight};
            SDL_RenderCopy(renderer, bg, NULL, &dest);
        }

        SDL_RenderPresent(renderer);
    }
// }