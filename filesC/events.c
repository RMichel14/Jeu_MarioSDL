#include "events.h"
#include "player.h"

void waitingEvent(SDL_Renderer *renderer) {
    // un evenement SDL
    SDL_Event event;
    // le boolean qui stoppe la boucle while
    SDL_bool continuer = SDL_TRUE;

    while (continuer) {
        SDL_WaitEvent(&event); // attente d'un evenement
        switch (event.type) {
            case SDL_QUIT:             // clic sur la fermeture de fenetre
                continuer = SDL_FALSE; // on stoppe la boucle
                break;
            
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE) {
                    continuer = SDL_FALSE;
                    break;
                };
                if (event.key.keysym.sym == SDLK_z) { 
                    // sauter()
                    printf("z");
                    break;
                };
                if (event.key.keysym.sym == SDLK_d) {
                    // avancer()
                    break;
                };
                if (event.key.keysym.sym == SDLK_q) {
                    // recule()
                    break;
                }
                // SDL_RenderClear(renderer);
                // SDL_RenderPresent(renderer);
                // break;
        }
    }
}