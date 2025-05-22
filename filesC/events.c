#include "events.h"
#include "player.h"

void waitingEvent(SDL_Renderer *renderer, SDL_Texture **tableauTextures) {
    SDL_Event event;
    SDL_bool continuer = SDL_TRUE;

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    Uint32 lastSpawnTime = 0; // Temps du dernier spawn

    while (continuer) {
        // Gestion des evenements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                    continuer = SDL_FALSE;

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    continuer = SDL_FALSE;
                }

                if (event.key.keysym.sym == SDLK_SPACE) {
                    continuer = SDL_FALSE;
                }

                if (event.key.keysym.sym == SDLK_z) {
                    sauter();
                }

                if (event.key.keysym.sym == SDLK_q) {
                    // todo
                    // reculer()
                    printf("q\n");
                }
            }
        }

        // Verifie si la touche est maintenue
        if (keystates[SDL_SCANCODE_D]) {
            if (avancer(renderer, tableauTextures, &(lastSpawnTime)) == 1)
                continuer = SDL_FALSE;
            // SDL_Delay(16); // petite pause (~60 FPS)
        }
    }
}

void waitingEventMenu(SDL_Renderer *renderer) {
    // un evenement SDL
    SDL_Event event;
    // le boolean qui stoppe la boucle while
    SDL_bool continuer = SDL_TRUE;

    while (continuer) {
        SDL_WaitEvent(&event); // attente d'un evenement
        switch (event.type) {
        case SDL_QUIT:             // clic sur la fermeture de fenetre
            continuer = SDL_FALSE; // on stoppe la boucle
            exit(EXIT_SUCCESS);
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE) {
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                continuer = SDL_FALSE;
                break;
            };
        }
    }
}