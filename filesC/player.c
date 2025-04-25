#include "player.h"

void avancer(renderer, tableauTextures) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight); // optient la taille de la fenetre (hauteur, largeur)

    SDL_Texture *bg = tableauTextures[1];

    int bgWidth, bgHeight;
    SDL_QueryTexture(bg, NULL, NULL, &bgWidth, &bgHeight);

    int scrollX = 0;
    int scrollSpeed = 5;

    int running = 1;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        // Récupérer la taille actuelle de la fenêtre
        int windowWidth, windowHeight;
        // SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

        scrollX -= scrollSpeed;
        if (scrollX <= -bgWidth)
        {
            scrollX += bgWidth;
        }

        SDL_RenderClear(renderer);

        // Dessine autant d'images que nécessaire pour couvrir toute la largeur
        for (int x = scrollX; x < windowWidth; x += bgWidth)
        {
            SDL_Rect dest = {x, 0, bgWidth, windowHeight};
            SDL_RenderCopy(renderer, bg, NULL, &dest);
        }

        SDL_RenderPresent(renderer);
    }
}